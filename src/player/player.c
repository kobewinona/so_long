/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:52:39 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/04 14:52:40 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

t_xy	find_player_position(t_obj **buffer)
{
	t_xy	pos;

	pos = (t_xy){0, 0};
	while (buffer[pos.y])
	{
		pos.x = 0;
		while (buffer[pos.y][pos.x].type != EMPTY)
		{
			if (buffer[pos.y][pos.x].type == PLAYER)
				return (pos);
			pos.x++;
		}
		pos.y++;
	}
	return ((t_xy){-1, -1});
}

t_xy	move_player(t_obj ***buffer, t_obj **layout_buffer, t_xy pos, int key_pressed)
{
//	t_obj	temp;
//
//	temp = (*buffer)[pos.y][pos.x];
//	(*buffer)[pos.y][pos.x] = layout_buffer[pos.y][pos.x];
	if (key_pressed == W)
	{
//		temp.position = (t_xy){pos.x, pos.y - 1};
		(*buffer)[pos.y - 1][pos.x] = (*buffer)[pos.y][pos.x];
		(*buffer)[pos.y][pos.x] = layout_buffer[pos.y][pos.x];
	}
	if (key_pressed == D)
	{
//		temp.position = (t_xy){pos.x + 1, pos.y};
		(*buffer)[pos.y][pos.x + 1] = (*buffer)[pos.y][pos.x];
		(*buffer)[pos.y][pos.x] = (t_obj){EMPTY, NULL, FALSE, pos.x, pos.y};
	}
	return (pos);
}

t_img	*create_player_sprite(void *mlx_ptr, t_list **error_log)
{
	t_img	*sprite;

	sprite = create_file_image("./assets/player/player_idle.xpm", mlx_ptr);
	if (!sprite)
	{
		log_error_message(error_log, UNKNOWN_ERR, ERROR);
		return (NULL);
	}
	return (sprite);
}
