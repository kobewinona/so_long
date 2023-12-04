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

typedef struct s_win
{
	void			*mlx_ptr;
	void			*win_ptr;
	unsigned int	width;
	unsigned int	height;
}	t_win;

t_win	generate_window(int width, int height, char *title);

#endif
