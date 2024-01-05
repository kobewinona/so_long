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

//t_img	*create_file_image(char *path, void *mlx_ptr)
//{
//	t_img	*sprite;
//
//	sprite = (t_img *)malloc(sizeof(t_img));
//	if (!sprite)
//		return (NULL);
//	sprite->img_ptr = mlx_xpm_file_to_image(
//			mlx_ptr, path, &sprite->width, &sprite->height);
//	if (!sprite->img_ptr)
//		return (NULL);
//	sprite->addr = mlx_get_data_addr(
//			sprite->img_ptr, &(sprite->bpp),
//			&(sprite->line_len), &(sprite->endian));
//	return (sprite);
//}

t_img	*create_new_file_image(char *path, void *mlx_ptr)
{
	t_img	sprite;

	sprite->img_ptr = mlx_xpm_file_to_image(
			mlx_ptr, path, &sprite->width, &sprite->height);
	if (!sprite->img_ptr)
		return (NULL);
	sprite->addr = mlx_get_data_addr(
			sprite->img_ptr, &(sprite->bpp),
			&(sprite->line_len), &(sprite->endian));
	return (sprite);
}

unsigned int	get_pixel_img(t_img img, int x, int y)
{
	return (*(unsigned int *)((img.addr + (y * img.line_len) + (x * img.bpp / 8))));
}

t_img	*create_image(int width, int height, void *mlx_ptr)
{
	t_img	*image;

	image = (t_img *)malloc(sizeof(t_img));
	if (!image)
		return (NULL);
	image->img_ptr = mlx_new_image(mlx_ptr, width, height);
	if (!image->img_ptr)
		return (NULL);
	image->addr = mlx_get_data_addr(
			image->img_ptr, &image->bpp,
			&image->line_len, &image->endian);
	image->width = width;
	image->height = height;
	return (image);
}
