/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:14:34 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/19 16:14:35 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKGROUND_H
# define BACKGROUND_H
# include "so_long.h"
# include "../draw_shape/draw_shape.h"

typedef struct s_background	t_background;

struct s_background
{
	int		collision;
	t_size	size;
	int		color;
	t_img	*sprite;
	void	(*render)(t_win *, t_xy, t_background *);
	void	(*cleanup)(t_background **, void *);
};

int	create_background(
		t_background **background, void *mlx_ptr, t_list **error_log);

#endif
