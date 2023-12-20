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
	t_gstate	*g_state;

	g_state = (t_gstate *)*ptr;
	if (g_state)
	{
		if (g_state->types_table)
			free(g_state->types_table);
		if (g_state->layout && g_state->layout->buffer)
		{
			cleanup_buffer(g_state->layout->buffer);
			free(g_state->layout);
		}
		if (g_state->buffer)
			cleanup_buffer(g_state->buffer);
		if (g_state->sprites)
			cleanup_sprites(g_state->window->mlx_ptr,
				g_state->types_table, &g_state->sprites);
		free(g_state);
	}
}

static int	create_game_env(const char *mapfile, t_gstate *g_state)
{
	g_state->types_table = NULL;
	g_state->buffer = NULL;
	g_state->layout = NULL;
	if (create_types_table(
			&g_state->types_table, g_state->error_log) != SUCCESS)
		return (log_error_message(g_state->error_log, TYPES_TABLE_ERR, ERROR));
	if (init_game_buffer(mapfile, &g_state->buffer, (t_gdata){g_state->window,
			g_state->error_log, g_state->types_table, NULL}) != SUCCESS)
		return (log_error_message(g_state->error_log, BUFFER_ERR, ERROR));
	print_buffer(g_state->buffer, (t_xy){0, 0});
	if (is_map_valid(g_state->buffer, g_state->error_log) != TRUE)
		return (log_error_message(g_state->error_log, VALIDATION_ERR, ERROR));
	if (create_layout(&g_state->layout,
			g_state->buffer, g_state->error_log) != SUCCESS)
		return (log_error_message(g_state->error_log, LAYOUT_ERR, ERROR));
	g_state->coll_count = count_collectables(g_state->buffer);
	g_state->p_pos = find_player_position(g_state->buffer);
	print_buffer(g_state->layout->buffer, (t_xy){0, 0});
	return (SUCCESS);
}

int	read_keys(int key_pressed, void **ptr)
{
	t_gstate	**g_state;

	g_state = (t_gstate **)ptr;
	if (!(*g_state))
		return (ERROR);
	if (key_pressed == ESC)
	{
		cleanup_game(ptr);
		exit(EXIT_SUCCESS);
	}
	if (key_pressed >= A && key_pressed <= D || key_pressed == W)
		(*g_state)->p_pos = move_player(
				&(*g_state)->buffer, (*g_state)->layout->buffer,
				(*g_state)->p_pos, key_pressed);
	return (SUCCESS);
}

int	render_game(void **ptr)
{
	t_gstate	**g_state;
	t_obj		obj;
	t_xy		pos;

	g_state = (t_gstate **)ptr;
	if (!g_state)
		return (ERROR);
	pos.y = 0;
	while ((*g_state)->buffer[pos.y])
	{
		pos.x = 0;
		while ((*g_state)->buffer[pos.y][pos.x].type != END)
		{
			render_object((t_obj){EMPTY, (*g_state)->sprites[0],
				FALSE, pos}, (*g_state)->window);
			obj = (*g_state)->buffer[pos.y][pos.x];
			if (obj.sprite)
				render_object(obj, (*g_state)->window);
//			if (obj.type == PLAYER)
//				ft_printf("obj.pos y %d pos x %d\n", obj.position.y, obj.position.x);
			pos.x++;
		}
		pos.y++;
	}
	return (SUCCESS);
}

int	init_game(const char *mapfile, t_list **error_log)
{
	t_gstate	*g_state;

	g_state = (t_gstate *)malloc(sizeof(t_gstate));
	if (!g_state)
		return (log_error_message(error_log, UNKNOWN_ERR, ERROR));
	g_state->window = NULL;
	g_state->error_log = error_log;
	handle_error(create_game_env(mapfile, g_state), &g_state, (t_error){
		&cleanup_game, GAME_ENV_ERR, g_state->error_log, TRUE});
	g_state->sprites = NULL;
	handle_error(create_window(
			g_state->layout->width, g_state->layout->height,
			&g_state->window, g_state->error_log), &g_state, (t_error){
		&cleanup_game, GAME_ERR, g_state->error_log, TRUE});
	handle_error(create_sprites(&g_state->sprites, (t_gdata){
			g_state->window, g_state->error_log, g_state->types_table, NULL}),
		&g_state, (t_error){&cleanup_game, GAME_ERR, g_state->error_log});
	add_sprites_to_buffer(g_state->buffer, g_state->sprites, (t_xy){0, 0});
	add_sprites_to_buffer(
		g_state->layout->buffer, g_state->sprites, (t_xy){0, 0});
	mlx_key_hook(g_state->window->win_ptr, &read_keys, &g_state);
	mlx_loop_hook(g_state->window->mlx_ptr, &render_game, &g_state);
	mlx_loop(g_state->window->mlx_ptr);
	cleanup_game((void **)&g_state);
	return (SUCCESS);
}
