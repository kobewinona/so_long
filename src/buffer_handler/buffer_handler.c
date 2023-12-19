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

void	cleanup_buffer(t_obj **buffer)
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

void	add_sprites_to_buffer(t_obj **buffer, t_img **sprites, t_xy pos)
{
	while (buffer[pos.y])
	{
		pos.x = 0;
		while (buffer[pos.y][pos.x].type != END)
		{
			buffer[pos.y][pos.x].sprite = sprites[buffer[pos.y][pos.x].type];
			pos.x++;
		}
		pos.y++;
	}
}

void	print_buffer(t_obj **buffer, t_xy pos)
{
	if (*buffer)
	{
		while (buffer[pos.y])
		{
			pos.x = 0;
			while (buffer[pos.y][pos.x].type != END)
			{
				if (buffer[pos.y][pos.x].type == EXIT)
					ft_printf("%s%s", DARK_PURPLE, "⍈");
				if (buffer[pos.y][pos.x].type == EMPTY)
					ft_printf("%s%s", GREY, "▢");
				if (buffer[pos.y][pos.x].type == PLAYER)
					ft_printf("%s%s", DARK_BLUE, "◉");
				if (buffer[pos.y][pos.x].type == COLLECTABLE)
					ft_printf("%s%s", DARK_GREEN, "◎");
				if (buffer[pos.y][pos.x].type == WALL)
					ft_printf("%s%s", DEFAULT, "▣");
				pos.x++;
				if (buffer[pos.y][pos.x].type != END)
					ft_putchar_fd(' ', STDOUT_FILENO);
			}
			ft_putchar_fd('\n', STDOUT_FILENO);
			pos.y++;
		}
	}
}
