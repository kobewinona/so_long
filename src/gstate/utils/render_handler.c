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

void	render_object(t_win *window, t_img *sprite, t_xy pos)
{
	if (window && sprite)
	{
		if (window->mlx_ptr && window->win_ptr)
		{
			mlx_put_image_to_window(
				window->mlx_ptr, window->win_ptr, sprite->img_ptr,
				(pos.x * SPRITE_WIDTH), (pos.y * SPRITE_HEIGHT));
		}
	}
}

int	render_layout(t_gstate	**gstate)
{
	t_obj_type	obj_type;
	t_xy		pos;

	pos.y = 0;
	while ((*gstate)->layout_buffer[pos.y])
	{
		pos.x = 0;
		while ((*gstate)->layout_buffer[pos.y][pos.x] != END)
		{
			obj_type = (*gstate)->layout_buffer[pos.y][pos.x];
			render_object((*gstate)->window,
				(*gstate)->sprites[BACKGROUND], pos);
			render_object((*gstate)->window,
				(*gstate)->sprites[obj_type], pos);
			pos.x++;
		}
		pos.y++;
	}
	return (SUCCESS);
}

int	render_objects(t_gstate **gstate)
{
	t_obj_type	obj_type;
	t_xy		pos;

	pos.y = 0;
	while ((*gstate)->game_buffer[pos.y])
	{
		pos.x = 0;
		while ((*gstate)->game_buffer[pos.y][pos.x] != END)
		{
			obj_type = (*gstate)->game_buffer[pos.y][pos.x];
			if (obj_type == PLAYER || obj_type == COLLECTABLE)
				render_object((*gstate)->window,
					(*gstate)->sprites[obj_type], pos);
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
