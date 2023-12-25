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

void	find_player_position(t_obj **buffer, t_xy *p_pos)
{
	t_xy	pos;

	pos = (t_xy){0, 0};
	while (buffer[pos.y])
	{
		pos.x = 0;
		while (buffer[pos.y][pos.x].type != EMPTY)
		{
			if (buffer[pos.y][pos.x].type == PLAYER)
			{
				*p_pos = pos;
				return ;
			}
			pos.x++;
		}
		pos.y++;
	}
}

void	move_player(
		t_obj **buffer, t_obj **layout_buffer, t_xy *p_pos, int key_pressed)
{
	int	dir_y;
	int	dir_x;

	dir_y = (key_pressed == S) - (key_pressed == W);
	dir_x = (key_pressed == D) - (key_pressed == A);
	buffer[p_pos->y + dir_y][p_pos->x + dir_x] = buffer[p_pos->y][p_pos->x];
	buffer[p_pos->y][p_pos->x] = layout_buffer[p_pos->y][p_pos->x];
	p_pos->y = (p_pos->y + dir_y);
	p_pos->x = (p_pos->x + dir_x);
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
