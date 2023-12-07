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
# include <math.h>
# include <string.h>
# include "libft.h"
# include "libftprintf.h"
# include "../libs/minilibx_macos/mlx.h"
# include "../utils/utils.h"
# include "../src/src.h"

// title
# define TITLE "so_long"

// magic numbers
# define TRUE 1
# define FALSE 0
# define ERROR -1

// keyboard keys
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

// grid size
# define WINDOW_WIDTH 768
# define WINDOW_HEIGHT 585
# define TILE_WIDTH 64
# define TILE_HEIGHT 64

#endif
