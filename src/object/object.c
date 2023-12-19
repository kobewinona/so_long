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

void	render_object(t_obj obj, t_win *window)
{
	if (window->mlx_ptr && window->win_ptr && obj.sprite->img_ptr)
	{
		mlx_put_image_to_window(
			window->mlx_ptr, window->win_ptr,
			obj.sprite->img_ptr,
			(obj.position.x * SPRITE_WIDTH), (obj.position.y * SPRITE_HEIGHT));
	}
}

t_obj	create_object(t_gdata gdata, t_obj_type type, t_xy position)
{
	t_obj	object;

	object.type = type;
	if (gdata.sprites)
		object.sprite = gdata.sprites[type];
	else
		object.sprite = NULL;
	object.collision = type == WALL;
	object.position = position;
	object.render = &render_object;
	return (object);
}
