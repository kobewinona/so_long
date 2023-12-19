/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectable.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:39:23 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/18 18:39:24 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLECTABLE_H
# define COLLECTABLE_H
# include "so_long.h"
# include "../draw_shape/draw_shape.h"

typedef struct s_collectable	t_collectable;

struct s_collectable
{
	int		collision;
	t_size	size;
	int		color;
	t_img	*sprite;
	void	(*render)(t_win *, t_xy, t_collectable *);
	void	(*cleanup)(t_collectable **, void *);
};

int	create_collectable(
		t_collectable **collectable, void *mlx_ptr, t_list **error_log);

#endif
