/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:46:16 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/11 14:46:17 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "layout.h"

void	cleanup_layout(t_layout **layout)
{
	int	y;

	if ((*layout))
	{
		if ((*layout)->types_table)
			free((*layout)->types_table);
		if ((*layout)->buffer)
		{
			y = 0;
			while ((*layout)->buffer[y])
			{
				free((*layout)->buffer[y]);
				y++;
			}
			free((*layout)->buffer);
		}
		free((*layout));
	}
}

void	print_buffer(t_layout *layout, t_xy temp)
{
	if (layout->buffer)
	{
		while (layout->buffer[temp.y])
		{
			temp.x = 0;
			while (layout->buffer[temp.y][temp.x] != EMPTY)
			{
				if (layout->buffer[temp.y][temp.x] == EXIT)
					ft_printf("%s%s", DARK_PURPLE, "⍈");
				if (layout->buffer[temp.y][temp.x] == GROUND)
					ft_printf("%s%s", GREY, "▢");
				if (layout->buffer[temp.y][temp.x] == PLAYER)
					ft_printf("%s%s", DARK_BLUE, "◉");
				if (layout->buffer[temp.y][temp.x] == COLLECTABLE)
					ft_printf("%s%s", DARK_GREEN, "◎");
				if (layout->buffer[temp.y][temp.x] == WALL)
					ft_printf("%s%s", DEFAULT, "▣");
				temp.x++;
				if (layout->buffer[temp.y][temp.x] != EMPTY)
					ft_putchar_fd(' ', STDOUT_FILENO);
			}
			ft_putchar_fd('\n', STDOUT_FILENO);
			temp.y++;
		}
	}
}

int	create_layout(t_layout **layout, const char *mapfile, t_list **error_log)
{
	*layout = (t_layout *)malloc(sizeof(t_layout));
	if (!(*layout))
		return (log_error_message(error_log, UNKNOWN_ERR, ERROR));
	(*layout)->types_table = NULL;
	(*layout)->buffer = NULL;
	(*layout)->print_buffer = &print_buffer;
	(*layout)->cleanup = &cleanup_layout;
	if (create_types_table(&(*layout)->types_table, error_log) != SUCCESS)
		return (log_error_message(error_log, LAYOUT_ERR, ERROR));
	if (init_layout_buffer(
			mapfile, &(*layout)->buffer,
			(*layout)->types_table, error_log) != SUCCESS)
		return (log_error_message(error_log, BUFFER_ERR, ERROR));
	if (is_layout_valid(
			(const t_obj_type * const *)(*layout)->buffer, error_log) != TRUE)
		return (log_error_message(error_log, LAYOUT_VALIDATION_ERR, ERROR));
	return (SUCCESS);
}
