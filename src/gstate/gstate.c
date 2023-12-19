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
		if (g_state->layout && g_state->layout->cleanup)
			g_state->layout->cleanup(&g_state->layout);
		if (g_state->buffer)
			cleanup_buffer(g_state->buffer);
		free(g_state);
	}
}

static int	create_game_env(const char *mapfile, t_gstate *g_state)
{
	g_state->types_table = NULL;
	handle_error(create_types_table(
			&g_state->types_table, g_state->error_log), &g_state, (t_error){
		&cleanup_game, GAME_ENV_ERR, g_state->error_log, TRUE});
	g_state->buffer = NULL;
	handle_error(init_game_buffer(mapfile, &g_state->buffer, (t_gdata){
			g_state->window, g_state->error_log, g_state->types_table, NULL}),
		&g_state, (t_error){
		&cleanup_game, GAME_ENV_ERR, g_state->error_log, TRUE});
	print_buffer(g_state->buffer, (t_xy){0, 0});
	handle_error(is_map_valid(
			g_state->buffer, g_state->error_log), &g_state, (t_error){
		&cleanup_game, GAME_ENV_ERR, g_state->error_log, TRUE});
	g_state->layout = NULL;
	handle_error(create_layout(
			&g_state->layout, g_state->buffer, g_state->error_log),
		&g_state, (t_error){&cleanup_game, GAME_ERR, g_state->error_log, TRUE});
	print_buffer(g_state->layout->buffer, (t_xy){0, 0});
	return (SUCCESS);
}

int	init_game(const char *mapfile, t_list **error_log)
{
	t_gstate	*g_state;

	g_state = (t_gstate *)malloc(sizeof(t_gstate));
	if (!g_state)
		return (log_error_message(error_log, UNKNOWN_ERR, ERROR));
	g_state->error_log = error_log;
	create_game_env(mapfile, g_state);
	handle_error(create_window(
			g_state->layout->width, g_state->layout->height,
			&g_state->window, g_state->error_log), &g_state, (t_error){
		&cleanup_game, GAME_ERR, g_state->error_log, TRUE});
//	create_sprites(&gdata);
//	handle_error(create_entities(), &g_game, (t_error){
//		&cleanup_game, GAME_ERR, g_game->error_log, TRUE});
//	print_buffer(g_game->buffer, (t_xy){0, 0});
//	mlx_loop_hook(g_game->window->mlx_ptr, &render_buffer, g_game->window);
//	mlx_key_hook(g_game->window->win_ptr, &read_keys, &g_game->window);
//	mlx_loop(g_game->window->mlx_ptr);
	cleanup_game((void **)&g_state);
	return (SUCCESS);
}
