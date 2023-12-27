/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:40:38 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/18 17:40:40 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_handler.h"

void	cleanup_buffer(t_obj_type **buffer)
{
	int	y;

	if (buffer)
	{
		y = 0;
		while (buffer[y])
		{
			free(buffer[y]);
			buffer[y] = NULL;
			y++;
		}
		free(buffer);
		buffer = NULL;
	}
}

static void	print_buffer_value(t_obj_type type)
{
	if (type == EXIT)
		ft_printf("%s%s", DARK_PURPLE, "⍈");
	if (type == EMPTY)
		ft_printf("%s%s", GREY, "▢");
	if (type == PLAYER)
		ft_printf("%s%s", DARK_BLUE, "◉");
	if (type == COLLECTABLE)
		ft_printf("%s%s", DARK_GREEN, "◎");
	if (type == WALL)
		ft_printf("%s%s", DEFAULT, "▣");
}

void	print_buffer(t_obj_type **buffer, t_xy pos)
{
	if (*buffer)
	{
		while (buffer[pos.y])
		{
			pos.x = 0;
			while (buffer[pos.y][pos.x] != END)
			{
				print_buffer_value(buffer[pos.y][pos.x]);
				pos.x++;
				if (buffer[pos.y][pos.x] != END)
					ft_putchar_fd(' ', STDOUT_FILENO);
			}
			ft_putchar_fd('\n', STDOUT_FILENO);
			pos.y++;
		}
	}
}
