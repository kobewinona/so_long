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
		if (gstate->game_buffer)
			cleanup_buffer(gstate->game_buffer);
		if (gstate->layout_buffer)
			cleanup_buffer(gstate->layout_buffer);
		if (gstate->layers_buffer)
			cleanup_layers_buffer(gstate->layers_buffer);
		if (gstate->sprites)
			cleanup_sprites(gstate->window->mlx_ptr,
				gstate->types_table, &gstate->sprites);
		if (gstate->window)
			mlx_destroy_window(
				gstate->window->mlx_ptr, gstate->window->win_ptr);
		free(gstate);
	}
	return (SUCCESS);
}

static int	create_game_env(const char *mapfile, t_gstate *gstate)
{
	if (create_types_table(
			&gstate->types_table, gstate->error_log) != SUCCESS)
		return (log_error_message(gstate->error_log, TYPES_TABLE_ERR, ERROR));
	if (init_game_buffer(mapfile, &gstate->game_buffer, &gstate->size,
			(t_gdata){gstate->window, gstate->size, gstate->error_log,
			gstate->types_table, NULL}) != SUCCESS)
		return (log_error_message(gstate->error_log, BUFFER_ERR, ERROR));
	define_buffer_size(gstate->game_buffer, &gstate->size);
	if (is_map_valid(gstate->game_buffer,
			gstate->size, gstate->error_log) != TRUE)
		return (log_error_message(gstate->error_log, VALIDATION_ERR, ERROR));
	if (init_layout_buffer(gstate->game_buffer, &gstate->layout_buffer,
			(t_gdata){gstate->window, gstate->size, gstate->error_log,
			gstate->types_table, gstate->sprites}) != SUCCESS)
		return (log_error_message(gstate->error_log, LAYOUT_ERR, ERROR));
	if (init_layers_buffer(gstate->game_buffer, &gstate->layers_buffer,
			(t_gdata){gstate->window, gstate->size, gstate->error_log,
			gstate->types_table, gstate->sprites}) != SUCCESS)
		return (log_error_message(gstate->error_log, LAYOUT_ERR, ERROR));
	count_collectables(gstate->game_buffer, &gstate->collectables_count);
	find_buffer_type(gstate->game_buffer, &gstate->p_pos, PLAYER);
	return (SUCCESS);
}

int	init_game(const char *mapfile, t_list **error_log)
{
	t_gstate	*gstate;

	gstate = (t_gstate *)malloc(sizeof(t_gstate));
	if (!gstate)
		return (log_error_message(error_log, UNKNOWN_ERR, ERROR));
	ft_memset(gstate, 0, sizeof(t_gstate));
	gstate->error_log = error_log;
	handle_error(create_game_env(mapfile, gstate), &gstate, (t_error){
		&cleanup_game, GAME_ENV_ERR, gstate->error_log, TRUE});
	create_window(gstate->size.width, gstate->size.height,
		&gstate->window, gstate->error_log);
	handle_error(gstate->window != NULL, &gstate, (t_error){
		&cleanup_game, WINDOW_ERR, gstate->error_log, TRUE});
	handle_error(create_sprites(&gstate->sprites, (t_gdata){
			gstate->window, gstate->size, gstate->error_log,
			gstate->types_table, NULL}), &gstate, (t_error){
		&cleanup_game, WINDOW_ERR, gstate->error_log, TRUE});
	mlx_loop_hook(gstate->window->mlx_ptr, render_game, &gstate);
	mlx_key_hook(gstate->window->win_ptr, read_keys, &gstate);
	mlx_hook(gstate->window->win_ptr, 17, 0, cleanup_game, &gstate);
	mlx_loop(gstate->window->mlx_ptr);
	cleanup_game((void **)&gstate);
	return (SUCCESS);
}
