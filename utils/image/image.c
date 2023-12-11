/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:23:08 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/01 14:23:08 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

t_img	*create_image(int width, int height, void *mlx_ptr)
{
	t_img	*image;

	image = (t_img *)malloc(sizeof(t_img));
	if (!image)
		return ((void *)0);
	image->img_ptr = mlx_new_image(mlx_ptr, width, height);
	image->addr = mlx_get_data_addr(
			image->img_ptr, &image->bpp,
			&image->line_len, &image->endian);
	image->width = width;
	image->height = height;
	return (image);
}
