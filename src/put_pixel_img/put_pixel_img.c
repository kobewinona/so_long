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

void	put_pixel_img(t_img img, t_xy pos, int color)
{
	char	*dst;

	if ((pos.x >= 0 && pos.y >= 0) && (pos.x < img.width && pos.y < img.height))
	{
		dst = img.addr + ((pos.y * img.line_len) + (pos.x * (img.bpp / 8)));
		*(unsigned int *)dst = color;
	}
}
