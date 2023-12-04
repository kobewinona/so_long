/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:45:33 by dklimkin          #+#    #+#             */
/*   Updated: 2023/11/29 16:45:34 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <OpenGL/gl.h>
# include "libft.h"
# include "libftprintf.h"
# include "../libs/minilibx_macos/mlx.h"
# include "../src/src.h"
# include "../utils/utils.h"

// magic numbers
# define TRUE 1
# define FALSE 0
# define ERROR -1

// keyboard keys
# define ESC 53
# define FOLLOW 3
# define COLOR 8
# define CLEAR 6

int	read_keys(int key_pressed, void *param);
int	follow_mouse(unsigned int mouse_x, unsigned int mouse_y, void *param);
int	trigger_drawing(int button);
int	cancel_drawing(int button);

#endif
