/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ground.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:19:44 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/07 16:19:45 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GROUND_H
# define GROUND_H

typedef struct s_ground
{
	t_obj	obj;
	int		width;
	int		height;
	int		color;
	t_img	*sprite;
}	t_ground;

void	create_ground(t_win *window);

#endif
