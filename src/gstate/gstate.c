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

void	cleanup_game(void **ptr)
{
	t_gstate	*gstate;

	gstate = (t_gstate *)*ptr;
	if (gstate)
	{
		if (gstate->types_table)
			free(gstate->types_table);
		if (gstate->layout && gstate->layout->buffer)
		{
			cleanup_buffer(gstate->layout->buffer);
			free(gstate->layout);
		}
		if (gstate->buffer)
			cleanup_buffer(gstate->buffer);
		if (gstate->sprites)
			cleanup_sprites(gstate->window->mlx_ptr,
				gstate->types_table, &gstate->sprites);
		free(gstate);
	}
}

static int	create_game_env(const char *mapfile, t_gstate *gstate)
{
	gstate->types_table = NULL;
	gstate->buffer = NULL;
	gstate->layout = NULL;
	if (create_types_table(
			&gstate->types_table, gstate->error_log) != SUCCESS)
		return (log_error_message(gstate->error_log, TYPES_TABLE_ERR, ERROR));
	if (init_game_buffer(mapfile, &gstate->buffer, (t_gdata){gstate->window,
		gstate->error_log, gstate->types_table, NULL}) != SUCCESS)
		return (log_error_message(gstate->error_log, BUFFER_ERR, ERROR));
	print_buffer(gstate->buffer, (t_xy){0, 0});
	if (is_map_valid(gstate->buffer, gstate->error_log) != TRUE)
		return (log_error_message(gstate->error_log, VALIDATION_ERR, ERROR));
	if (create_layout(&gstate->layout,
			gstate->buffer, gstate->error_log) != SUCCESS)
		return (log_error_message(gstate->error_log, LAYOUT_ERR, ERROR));
	gstate->coll_count = count_collectables(gstate->buffer);
	find_player_position(gstate->buffer, &gstate->p_pos);
	print_buffer(gstate->layout->buffer, (t_xy){0, 0});
	return (SUCCESS);
}

int	read_keys(int key_pressed, void **ptr)
{
	t_gstate	**gstate;

	gstate = (t_gstate **)ptr;
	if (!(*gstate))
		return (ERROR);
	if (key_pressed == ESC)
	{
		cleanup_game(ptr);
		exit(EXIT_SUCCESS);
	}
	if (key_pressed >= A && key_pressed <= D || key_pressed == W)
	{
		move_player((*gstate)->buffer, (*gstate)->layout->buffer,
			&(*gstate)->p_pos, key_pressed);
	}
	return (SUCCESS);
}

int	render_layout(t_gstate	*gstate)
{
	t_xy		pos;
	t_obj		ground;

	ground = (t_obj){EMPTY, gstate->sprites[0], FALSE};
	pos.y = 0;
	while (gstate->buffer[pos.y])
	{
		pos.x = 0;
		while (gstate->buffer[pos.y][pos.x].type != END)
		{
			render_object(ground, (t_xy){pos.x, pos.y}, gstate->window);
			render_object(
				gstate->buffer[pos.y][pos.x],
				(t_xy){pos.x, pos.y}, gstate->window);
			pos.x++;
		}
		pos.y++;
	}
	return (SUCCESS);
}

int	render_player(t_gstate *gstate)
{
	t_obj		obj;
	t_xy		pos;

	pos.y = 0;
	while (gstate->buffer[pos.y])
	{
		pos.x = 0;
		while (gstate->buffer[pos.y][pos.x].type != END)
		{
			obj = gstate->buffer[pos.y][pos.x];
			if (obj.sprite && obj.type == PLAYER)
				render_object(obj, (t_xy){pos.x, pos.y}, gstate->window);
			pos.x++;
		}
		pos.y++;
	}
	return (SUCCESS);
}

int	render_game(t_gstate *gstate)
{
	t_obj		obj;
	t_xy		pos;

	render_layout(gstate);
	render_player(gstate);
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
	gstate->sprites = NULL;
	handle_error(create_window(
			gstate->layout->width, gstate->layout->height,
			&gstate->window, gstate->error_log), &gstate, (t_error){
		&cleanup_game, GAME_ERR, gstate->error_log, TRUE});
	handle_error(create_sprites(&gstate->sprites, (t_gdata){
			gstate->window, gstate->error_log, gstate->types_table, NULL}),
		&gstate, (t_error){&cleanup_game, GAME_ERR, gstate->error_log});
	add_sprites_to_buffer(gstate->buffer, gstate->sprites, (t_xy){0, 0});
	add_sprites_to_buffer(
		gstate->layout->buffer, gstate->sprites, (t_xy){0, 0});
	mlx_loop_hook(gstate->window->mlx_ptr, &render_game, gstate);
	mlx_key_hook(gstate->window->win_ptr, &read_keys, &gstate);
	mlx_loop(gstate->window->mlx_ptr);
	cleanup_game((void **)&gstate);
	return (SUCCESS);
}
