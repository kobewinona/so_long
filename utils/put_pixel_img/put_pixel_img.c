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

void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && y >= 0) && (x < img.width && y < img.height))
	{
		dst = img.addr + ((y * img.line_len) + (x * (img.bpp / 8)));
		*(unsigned int *)dst = color;
	}
}
