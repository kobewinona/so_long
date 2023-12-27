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

int	render_game(t_gstate **gstate)
{
	t_list		*current;
	t_xy		pos;

	pos.y = 0;
	while (pos.y < (*gstate)->size.height)
	{
		pos.x = 0;
		while (pos.x < (*gstate)->size.width)
		{
			current = (*gstate)->layers_buffer[pos.y][pos.x];
			while (current)
			{
				render_object((*gstate)->window,
					(*gstate)->sprites[get_object(current)->type], pos);
				current = current->next;
			}
			pos.x++;
		}
		pos.y++;
	}
	return (SUCCESS);
}
