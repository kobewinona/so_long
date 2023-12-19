/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:46:24 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/11 14:46:26 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAYOUT_H
# define LAYOUT_H
# include "so_long.h"
# include "../buffer_handler/buffer_handler.h"

typedef struct s_layout	t_layout;

struct s_layout
{
	t_obj	**buffer;
	int		width;
	int		height;
	void	(*cleanup)(t_layout **);
};

int		create_layout(
			t_layout **layout, t_obj **game_buffer, t_list **error_log);
int		init_layout_buffer(
			t_obj **game_buffer, t_obj ***layout_buffer,
			t_size size, t_list **error_log);
void	cleanup_layout(t_layout **layout);

#endif
