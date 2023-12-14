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

#include "draw_shape.h"

void	draw_shape(t_shape shape, t_xy temp, t_img img)
{
	while (temp.y < shape.height && (temp.y + shape.y) < img.height)
	{
		temp.x = 0;
		while (temp.x < shape.width && (temp.x + shape.x) < img.width)
		{
			put_pixel_img(img, (t_xy){temp.x + shape.x, temp.y + shape.y}, shape.color);
			temp.x++;
		}
		temp.y++;
	}
}
