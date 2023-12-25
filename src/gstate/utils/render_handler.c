/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:43:01 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/25 18:43:04 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gstate.h"

int	render_layout(t_gstate	**gstate)
{
	t_xy		pos;
	t_obj		background;

	background = create_object(BACKGROUND, (*gstate)->sprites[BACKGROUND]);
	pos.y = 0;
	while ((*gstate)->layout_buffer[pos.y])
	{
		pos.x = 0;
		while ((*gstate)->layout_buffer[pos.y][pos.x].type != END)
		{
			render_object(background, (t_xy){pos.x, pos.y}, (*gstate)->window);
			render_object(
				(*gstate)->layout_buffer[pos.y][pos.x],
				(t_xy){pos.x, pos.y}, (*gstate)->window);
			pos.x++;
		}
		pos.y++;
	}
	return (SUCCESS);
}

int	render_objects(t_gstate **gstate)
{
	t_obj		obj;
	t_xy		pos;

	pos.y = 0;
	while ((*gstate)->objs_buffer[pos.y])
	{
		pos.x = 0;
		while ((*gstate)->objs_buffer[pos.y][pos.x].type != END)
		{
			obj = (*gstate)->objs_buffer[pos.y][pos.x];
			if (obj.sprite && obj.type == PLAYER)
				render_object(obj, (t_xy){pos.x, pos.y}, (*gstate)->window);
			if (obj.sprite && obj.type == COLLECTABLE)
				render_object(obj, (t_xy){pos.x, pos.y}, (*gstate)->window);
			pos.x++;
		}
		pos.y++;
	}
	return (SUCCESS);
}

int	render_game(t_gstate **gstate)
{
	render_layout(gstate);
	render_objects(gstate);
	return (SUCCESS);
}
