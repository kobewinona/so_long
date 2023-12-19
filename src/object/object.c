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

void	render_object(t_obj obj)
{
	mlx_put_image_to_window(
		obj.win->mlx_ptr, obj.win->win_ptr,
		obj.sprite->img_ptr,
		(obj.pos.x * SPRITE_WIDTH), (obj.pos.y * SPRITE_HEIGHT));
}

t_obj	create_object(t_gdata gdata, t_obj_type type, t_xy pos)
{
	t_obj	object;

	object.type = type;
	object.win = gdata.window;
	if (gdata.sprites)
		object.sprite = gdata.sprites[type];
	object.collision = type == WALL;
	object.pos = pos;
	object.render = &render_object;
	return (object);
}
