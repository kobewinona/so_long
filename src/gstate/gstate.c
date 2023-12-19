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
	print_buffer(g_state->layout->buffer, (t_xy){0, 0});
	return (SUCCESS);
}

static void	add_sprites(
		t_obj **game_buffer, t_obj **layout_buffer, t_img **sprites, t_xy pos)
{
	ft_printf("add_sprites 1\n");
	while (game_buffer[pos.y])
	{
		ft_printf("add_sprites 2\n");
		pos.x = 0;
		while (game_buffer[pos.y][pos.x].type != END)
		{
			game_buffer[pos.y][pos.x].sprite = sprites[game_buffer[pos.y][pos.x].type];
			layout_buffer[pos.y][pos.x].sprite = sprites[layout_buffer[pos.y][pos.x].type];
			pos.x++;
		}
		pos.y++;
	}
}

static t_img	*create_sprite(t_obj_type type, t_gdata gdata)
{
	if (type == PLAYER)
		return (create_player_sprite(gdata.window->mlx_ptr, gdata.error_log));
	return (NULL);
}

static int	create_sprites(t_img ***sprites, t_gdata gdata)
{
	int	i;
	int	types_count;

	types_count = count_valid_types(gdata.types_table);
	(*sprites) = (t_img **)ft_calloc(types_count, sizeof(t_img *));
	if (!(*sprites))
	{
		ft_printf("here\n");
		return (log_error_message(gdata.error_log, UNKNOWN_ERR, ERROR));
	}
	ft_printf("types_count %d\n", types_count);
	i = 0;
	while (i < types_count)
	{
		(*sprites)[i] = create_sprite(i, gdata);
//		if (!(*sprites)[i])
//			return (log_error_message(gdata.error_log, SPRITES_ERR, ERROR));
		i++;
	}
	for (i = 0; i < types_count; i++) {
		ft_printf("(*sprites)[%d] %p\n", i, (*sprites)[i]);
	}
	return (SUCCESS);
}

int	render_buffer(void *ptr)
{
	t_gstate	*g_state;
	t_obj		obj;
	t_xy		pos;

	g_state = (t_gstate *)ptr;
	ft_printf("here 1\n");
	ft_printf("g_state %p\n", g_state);
	ft_printf("g_state buffer 0 0 (d%)\n", g_state->buffer[0][0]);
	ft_printf("g_state buffer 0 0 (d%)\n", g_state->buffer[3][1]);
	pos.y = 0;
	while (g_state->buffer[pos.y])
	{
		pos.x = 0;
		while (g_state->buffer[pos.y][pos.x].type != EMPTY)
		{
			ft_printf("here 1\n");
			obj = g_state->buffer[pos.y][pos.x];
			obj.render(obj);
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
	add_sprites(g_state->buffer,
		g_state->layout->buffer, g_state->sprites, (t_xy){0, 0});
	mlx_loop_hook(g_state->window->mlx_ptr, &render_buffer, g_state);
	mlx_loop(g_state->window->mlx_ptr);
	cleanup_game((void **)&g_state);
	return (SUCCESS);
}
