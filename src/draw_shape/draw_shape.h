/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shape.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:58:14 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/04 12:58:14 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_SHAPE_H
# define DRAW_SHAPE_H
# include "so_long.h"
# include "../put_pixel_img/put_pixel_img.h"

typedef struct s_shape
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_shape;

void	draw_shape(t_shape shape, t_xy temp, t_img img);

#endif
