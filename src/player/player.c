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

void	define_player_position(t_obj_type **buffer, t_xy *p_pos)
{
	*p_pos = (t_xy){0, 0};
	while (buffer[p_pos->y])
	{
		p_pos->x = 0;
		while (buffer[p_pos->y][p_pos->x] != END)
		{
			if (buffer[p_pos->y][p_pos->x] == PLAYER)
				return ;
			p_pos->x++;
		}
		p_pos->y++;
	}
}

void	move_player(t_obj_type **game, t_obj_type **layout,
			t_xy *p_pos, int key_pressed)
{
	int			dir_y;
	int			dir_x;

	dir_y = (key_pressed == S) - (key_pressed == W);
	dir_x = (key_pressed == D) - (key_pressed == A);
	if (layout[p_pos->y + dir_y][p_pos->x + dir_x] == WALL)
		return ;
	game[p_pos->y + dir_y][p_pos->x + dir_x] = game[p_pos->y][p_pos->x];
	game[p_pos->y][p_pos->x] = layout[p_pos->y][p_pos->x];
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
