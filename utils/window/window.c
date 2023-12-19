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

int	create_window(int width, int height, t_win **window, t_list **error_log)
{
	*window = (t_win *)malloc(sizeof(t_win));
	if (!(*window))
		return (log_error_message(error_log, WINDOW_ERR, ERROR));
	(*window)->mlx_ptr = mlx_init();
	(*window)->win_ptr = mlx_new_window(
			(*window)->mlx_ptr,
			(width * SPRITE_WIDTH),
			(height * SPRITE_HEIGHT),
			TITLE);
	if (!(*window)->mlx_ptr || !(*window)->win_ptr)
		return (log_error_message(error_log, WINDOW_ERR, ERROR));
	(*window)->width = (width * SPRITE_WIDTH);
	(*window)->height = (height * SPRITE_HEIGHT);
	return (SUCCESS);
}
