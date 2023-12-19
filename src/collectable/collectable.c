/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:39:18 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/18 18:39:18 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collectable.h"

t_img	*create_collectable_sprite(void *mlx_ptr, t_list **error_log)
{
	t_img	*sprite;

	sprite = create_image(SPRITE_WIDTH, SPRITE_HEIGHT, mlx_ptr);
	if (!sprite)
	{
		log_error_message(error_log, UNKNOWN_ERR, ERROR);
		return (NULL);
	}
	draw_shape((t_shape){0, 0, SPRITE_WIDTH,
		SPRITE_HEIGHT, create_color(255, 240, 247, 87)},
		(t_xy){0, 0}, *sprite);
	return (sprite);
}
