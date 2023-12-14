/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:37:40 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/14 17:37:41 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPS_H
# define TEMPS_H

typedef struct s_xy {
	int	x;
	int	y;
}	t_xy;

typedef struct s_size {
	int	width;
	int	height;
}	t_size;

typedef struct s_xy_size {
	int	x;
	int	y;
	int	width;
	int	height;
}	t_xy_size;

#endif
