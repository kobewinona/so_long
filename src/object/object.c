/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:06:26 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/07 16:06:26 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

void	render_object(t_obj obj, t_xy pos, t_win *window)
{
	if (window->mlx_ptr && window->win_ptr && obj.sprite)
	{
		mlx_put_image_to_window(
			window->mlx_ptr, window->win_ptr,
			obj.sprite->img_ptr,
			(pos.x * SPRITE_WIDTH), (pos.y * SPRITE_HEIGHT));
	}
}

t_obj	create_object(t_obj_type type, t_img *sprite)
{
	t_obj	object;

	object.type = type;
	object.sprite = sprite;
	object.collision = type == WALL;
	return (object);
}
