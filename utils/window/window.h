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

typedef struct s_img	t_img;

typedef struct s_buffer {
	t_img			*img;
}	t_buffer;

typedef struct s_win {
	void		*mlx_ptr;
	void		*win_ptr;
	int			width;
	int			height;
	t_buffer	**buffer;
}	t_win;

t_win	create_window(char *title);

#endif
