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

void    cleanup_layout(t_layout **layout)
{
	int         y;

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

static void  print_layout_buffer(t_obj_type **buffer, int rows, int columns)
{
    int y;
    int x;

    y = 0;
    while (y < rows)
    {
        x = 0;
        while (x < columns)
        {
            ft_printf("%d", buffer[y][x]);
            x++;
            if (x != columns)
                ft_printf(" ");
        }
        ft_printf("\n");
        y++;
    }
}

//void  print_layout_buffer(t_layout *layout)
//{
//    int y;
//    int x;
//
//    y = 0;
//    while (y < layout->rows)
//    {
//        x = 0;
//        while (x < layout->columns)
//        {
//            ft_printf("%d", layout->buffer[y][x]);
//            x++;
//            if (x != layout->columns)
//                ft_printf(" ");
//        }
//        ft_printf("\n");
//        y++;
//    }
//}

int create_layout(t_layout **layout, char *filename, t_list **error_log)
{

	*layout = (t_layout *)malloc(sizeof(t_layout));
	if (!(*layout))
		return (ERROR);
	(*layout)->types_table = NULL;
	(*layout)->buffer = NULL;
	(*layout)->cleanup = &cleanup_layout;
	if (create_types_table(&(*layout)->types_table, error_log) != SUCCESS)
		return (log_error_message(error_log, LAYOUT_ERR, TRUE));
	if (init_layout_buffer(filename, &(*layout)->buffer, (*layout)->types_table, error_log) != SUCCESS)
		return (log_error_message(error_log, BUFFER_ERR, TRUE));
	if (is_layout_valid((const t_obj_type *const *)(*layout)->buffer, error_log) != TRUE)
		return (log_error_message(error_log, LAYOUT_VALIDATION_ERR, TRUE));
//	print_layout_buffer((*layout)->buffer, 5, 13);
	return (SUCCESS);
}
