/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:46:04 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/04 12:46:05 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put_pixel_img.h"

void	put_pixel_img(t_img img, t_xy temp, int color)
{
	char	*dst;

	if ((temp.x >= 0 && temp.y >= 0) && (temp.x < img.width && temp.y < img.height))
	{
		dst = img.addr + ((temp.y * img.line_len) + (temp.x * (img.bpp / 8)));
		*(unsigned int *)dst = color;
	}
}
