/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:43:37 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/18 18:43:40 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H
# include "so_long.h"
# include "../draw_shape/draw_shape.h"

typedef struct s_exit	t_exit;

struct s_exit
{
	int		collision;
	t_size	size;
	int		color;
	t_img	*sprite;
	void	(*render)(t_win *, t_xy, t_exit *);
	void	(*cleanup)(t_exit **, void *);
};

int	create_exit(
		t_exit **exit, void *mlx_ptr, t_list **error_log);

#endif
