/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 00:48:43 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/28 00:48:44 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_H
# define ANIMATION_H
# include "so_long.h"
# include "../sprite_handler/sprite_handler.h"

typedef struct s_animation
{
	t_list		*frames;
	int			width;
	int			height;
	int			delay;			// How many fps it takes to change animation
	int			_tmp_delay;		// Delay Iterator
	int			current_frame;	// Which frame is selected
	long int	last_updated;	// When was the last update
	long int	frame_count;	// The frame count
	t_obj_type	type;
}	t_animation;

#endif
