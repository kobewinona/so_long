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

#include "ground.h"

void	render_ground(int x, int y, t_ground *ground)
{
	mlx_put_image_to_window(
            ground->window.mlx_ptr,
            ground->window.win_ptr,
            ground->sprite->img_ptr,
		(x * TILE_WIDTH), (y * TILE_HEIGHT)
		);
}

t_ground	*create_ground(t_win window)
{
	t_ground	*ground;

	ground = (t_ground *)malloc(sizeof(t_ground));
	if (!ground)
		return ((void *)0);
	ground->obj.obj_type = GROUND;
    ground->window = window;
	ground->collision = FALSE;
	ground->x = 0;
	ground->y = 0;
	ground->width = TILE_WIDTH;
	ground->height = TILE_HEIGHT;
	ground->color = create_color(255, 250, 240, 202);
	ground->sprite = create_image(
			ground->width, ground->height, window.mlx_ptr);
	draw_shape((t_shape){
		0, 0, ground->width, ground->height, ground->color
	}, *(ground->sprite));
	ground->render_ground = render_ground;
	return (ground);
}
