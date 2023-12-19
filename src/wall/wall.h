/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:01:27 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/18 18:01:28 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WALL_H
# define WALL_H
# include "so_long.h"
# include "gdata.h"
# include "../draw_shape/draw_shape.h"

typedef struct s_wall	t_wall;

struct s_wall
{
	int		collision;
	t_size	size;
	int		color;
	t_img	*sprite;
	void	(*render)(t_win *, t_xy, t_wall *);
	void	(*cleanup)(t_wall **, void *);
};

//int		create_wall(
//			t_wall **wall, void *mlx_ptr, t_list **error_log);
t_img	*create_wall_sprite(t_gdata gdata);

#endif
