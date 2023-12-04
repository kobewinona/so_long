/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:57:58 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/04 12:57:59 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	draw_shape(t_shape shape, t_img img)
{
	unsigned int	y;
	unsigned int	x;

	y = 0;
	while (y < shape.height && y + shape.y < img.height)
	{
		x = 0;
		while (x < shape.width && x + shape.x < img.width)
		{
			put_pixel_img(img, x + shape.x, y + shape.y, shape.color);
			x++;
		}
		y++;
	}
}
