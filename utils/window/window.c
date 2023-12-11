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

#include "window.h"

t_win	create_window(void)
{
	t_win	window;

	window.mlx_ptr = mlx_init();
	window.win_ptr = mlx_new_window(
			window.mlx_ptr,
			WINDOW_WIDTH,
			WINDOW_HEIGHT,
			TITLE);
	window.width = WINDOW_WIDTH;
	window.height = WINDOW_HEIGHT;
	return (window);
}
