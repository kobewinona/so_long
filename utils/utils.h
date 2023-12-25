/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:51:34 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/01 14:51:35 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "./window/window.h"
# include "./image/image.h"
# include "./colors/colors.h"
# include "./error_handler/error_handler.h"

typedef enum e_obj_type
{
	EMPTY,
	BACKGROUND,
	WALL,
	PLAYER,
	COLLECTABLE,
	EXIT,
	END,
	INVALID
}	t_obj_type;

typedef struct s_xy
{
	int	x;
	int	y;
}	t_xy;

typedef struct s_size
{
	int	width;
	int	height;
}	t_size;

#endif