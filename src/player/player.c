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

t_img	*create_player_sprite(t_gdata gdata)
{
	t_img	*sprite;

	sprite = create_image(SPRITE_WIDTH, SPRITE_HEIGHT, gdata.window->mlx_ptr);
	if (!sprite)
	{
		log_error_message(gdata.error_log, UNKNOWN_ERR, ERROR);
		return (NULL);
	}
	draw_shape((t_shape){0, 0, SPRITE_WIDTH,
		SPRITE_HEIGHT, create_color(255, 81, 163, 163)},
		(t_xy){0, 0}, *sprite);
	return (sprite);
}
