/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ground.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:18:17 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/07 16:18:18 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	create_ground(t_win *window)
{
	t_ground	*ground;

	ground = (t_ground *)malloc(sizeof(t_ground));
	if (!ground)
		return ;
	ground->obj.obj_type = GROUND;
	ground->obj.win = window;
	ground->obj.collision = FALSE;
	ground->obj.x = 0;
	ground->obj.y = 0;
	ground->width = TILE_WIDTH;
	ground->height = TILE_HEIGHT;
	ground->color = create_color(100, 250, 240, 202);
	ground->sprite = create_image(
			ground->width, ground->height, window);
	draw_shape((t_shape){
		0, 0, ground->width, ground->height, ground->color
	}, *(ground->sprite));
}
