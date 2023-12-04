/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:23:25 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/01 14:23:26 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_win	generate_window(int width, int height, char *title)
{
	t_win	window;

	window.mlx_ptr = mlx_init();
	window.win_ptr = mlx_new_window(\
		window.mlx_ptr, \
		width, \
		height, \
		title \
	);
	window.width = width;
	window.height = height;
	return (window);
}
