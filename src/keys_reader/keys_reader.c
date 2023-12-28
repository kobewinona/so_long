/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:44:54 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/28 16:44:55 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys_reader.h"

static void	handle_player(t_gstate **gstate, int key_pressed)
{
	move_player((*gstate)->layers_buffer, &(*gstate)->p_pos, key_pressed);
	(*gstate)->moves_count++;
	ft_printf("moves made: %d\n", (*gstate)->moves_count);
	update_collectables_count((*gstate)->game_buffer,
		(*gstate)->p_pos, &(*gstate)->collectables_count);
	if ((*gstate)->collectables_count == 0)
	{
		(*gstate)->sprites[EXIT] = create_open_exit_sprite(
				(*gstate)->window->mlx_ptr, (*gstate)->error_log);
		if (is_exit_reached((*gstate)->layers_buffer, (*gstate)->p_pos))
		{
			cleanup_game((void **)gstate);
			exit(EXIT_SUCCESS);
		}
	}
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
	if ((key_pressed >= A && key_pressed <= D) || key_pressed == W)
		handle_player(gstate, key_pressed);
	return (SUCCESS);
}
