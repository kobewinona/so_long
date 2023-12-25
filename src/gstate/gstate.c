/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gstate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:06:17 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/08 15:06:18 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gstate.h"

int	cleanup_game(void **ptr)
{
	t_gstate	*gstate;

	gstate = (t_gstate *)*ptr;
	if (gstate)
	{
		if (gstate->types_table)
			free(gstate->types_table);
		if (gstate->types_buffer)
			cleanup_types_buffer(gstate->types_buffer);
		if (gstate->layout_buffer)
			cleanup_objs_buffer(gstate->layout_buffer);
		if (gstate->objs_buffer)
			cleanup_objs_buffer(gstate->objs_buffer);
		if (gstate->sprites)
			cleanup_sprites(gstate->window->mlx_ptr,
				gstate->types_table, &gstate->sprites);
		free(gstate);
	}
	exit(EXIT_SUCCESS);
}

static int	create_game_env(const char *mapfile, t_gstate *gstate)
{
	gstate->types_table = NULL;
	gstate->types_buffer = NULL;
	gstate->layout_buffer = NULL;
	gstate->objs_buffer = NULL;
	gstate->sprites = NULL;
	if (create_types_table(
			&gstate->types_table, gstate->error_log) != SUCCESS)
		return (log_error_message(gstate->error_log, TYPES_TABLE_ERR, ERROR));
	if (init_types_buffer(mapfile, &gstate->types_buffer, &gstate->size,
			(t_gdata){gstate->window, gstate->size, gstate->error_log,
			gstate->types_table, NULL}) != SUCCESS)
		return (log_error_message(gstate->error_log, BUFFER_ERR, ERROR));
	print_types_buffer(gstate->types_buffer, (t_xy){0, 0});
	if (is_map_valid(gstate->types_buffer, gstate->error_log) != TRUE)
		return (log_error_message(gstate->error_log, VALIDATION_ERR, ERROR));
	count_collectables(gstate->types_buffer, &gstate->collectables_count);
	define_player_position(gstate->types_buffer, &gstate->p_pos);
	create_window(gstate->size.width, gstate->size.height,
		&gstate->window, gstate->error_log);
	if (!gstate->window->mlx_ptr || !gstate->window->win_ptr)
		return (log_error_message(gstate->error_log, WINDOW_ERR, ERROR));
	if (create_sprites(&gstate->sprites, (t_gdata){gstate->window, gstate->size,
			gstate->error_log, gstate->types_table, NULL}) != SUCCESS)
		return (log_error_message(gstate->error_log, SPRITES_ERR, ERROR));
	return (SUCCESS);
}

int	read_keys(int key_pressed, void **ptr)
{
	t_gstate	**gstate;

	gstate = (t_gstate **)ptr;
	if (!(*gstate))
		return (ERROR);
	if (key_pressed == ESC)
		cleanup_game(ptr);
	if (key_pressed >= A && key_pressed <= D || key_pressed == W)
	{
		move_player((*gstate)->objs_buffer,
			(*gstate)->layout_buffer, &(*gstate)->p_pos, key_pressed);
		update_collectables_count((*gstate)->types_buffer,
			(*gstate)->layout_buffer, (*gstate)->p_pos,
			&(*gstate)->collectables_count);
		if ((*gstate)->collectables_count == 0)
			(*gstate)->sprites[EXIT] = create_open_exit_sprite(
					(*gstate)->window->mlx_ptr, (*gstate)->error_log);
	}
	return (SUCCESS);
}

int	init_game(const char *mapfile, t_list **error_log)
{
	t_gstate	*gstate;

	gstate = (t_gstate *)malloc(sizeof(t_gstate));
	if (!gstate)
		return (log_error_message(error_log, UNKNOWN_ERR, ERROR));
	gstate->window = NULL;
	gstate->error_log = error_log;
	handle_error(create_game_env(mapfile, gstate), &gstate, (t_error){
		&cleanup_game, GAME_ENV_ERR, gstate->error_log, TRUE});
	if (init_layout_buffer(gstate->types_buffer, &gstate->layout_buffer,
			(t_gdata){gstate->window, gstate->size, gstate->error_log,
			gstate->types_table, gstate->sprites}) != SUCCESS)
		return (log_error_message(gstate->error_log, LAYOUT_ERR, ERROR));
	print_objects_buffer(gstate->layout_buffer, (t_xy){0, 0});
	if (init_objs_buffer(gstate->types_buffer, &gstate->objs_buffer,
			(t_gdata){gstate->window, gstate->size, gstate->error_log,
			gstate->types_table, gstate->sprites}) != SUCCESS)
		return (log_error_message(gstate->error_log, LAYOUT_ERR, ERROR));
	print_objects_buffer(gstate->objs_buffer, (t_xy){0, 0});
	mlx_loop_hook(gstate->window->mlx_ptr, render_game, &gstate);
	mlx_key_hook(gstate->window->win_ptr, read_keys, &gstate);
	mlx_hook(gstate->window->win_ptr, 17, 0, cleanup_game, &gstate);
	mlx_loop(gstate->window->mlx_ptr);
	cleanup_game((void **)&gstate);
	return (SUCCESS);
}
