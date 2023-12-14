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

void	put_pixel_img(t_img img, t_xy tmp, int color)
{
	char	*dst;

	if ((tmp.x >= 0 && tmp.y >= 0) && (tmp.x < img.width && tmp.y < img.height))
	{
		dst = img.addr + ((tmp.y * img.line_len) + (tmp.x * (img.bpp / 8)));
		*(unsigned int *)dst = color;
	}
}
