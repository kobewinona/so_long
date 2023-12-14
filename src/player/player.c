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

void	create_player(t_win *window)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
		return ;
	player->obj.obj_type = PLAYER;
	player->collision = TRUE;
	player->x = 0;
	player->y = 0;
	player->width = TILE_WIDTH;
	player->height = TILE_HEIGHT;
	player->color = create_color(100, 13, 59, 102);
	player->sprite = create_image(
			player->width, player->height, window);
	draw_shape((t_shape){
		0, 0, player->width, player->height, player->color
	}, (t_xy){0, 0}, *(player->sprite));
}
