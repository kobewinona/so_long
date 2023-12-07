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

typedef struct s_shape	t_shape;

struct s_shape {
	unsigned int	x;
	unsigned int	y;
	unsigned int	width;
	unsigned int	height;
	int				color;
};

void	draw_shape(t_shape shape, t_img img);

#endif
