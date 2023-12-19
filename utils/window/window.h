/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:24:07 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/01 14:24:08 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H
# include "so_long.h"

typedef struct s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			width;
	int			height;
}	t_win;

int	create_window(int width, int height, t_win **window, t_list **error_log);

#endif
