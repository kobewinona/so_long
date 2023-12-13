/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:31:47 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/12 15:31:48 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "layout_buffer.h"

static int cleanup_on_exit(char *line)
{
    free(line);
    return (ERROR);
}

static int count_columns(const char *line)
{
    int count;

    count = 0;
    while (line[count] && line[count] != '\n')
        count++;
    return (count);
}

static int  adjust_layout_buffer_size(int rows, t_obj_type ***buffer)
{
	size_t      old_size;
	size_t      new_size;
	t_obj_type  **new_buffer;

	old_size = (rows * sizeof(t_obj_type *));
	new_size = ((rows + 2) * sizeof(t_obj_type *));
	new_buffer = ft_realloc(*buffer,  old_size, new_size);
	if (!new_buffer)
		return (ERROR);
	ft_bzero((new_buffer + rows), (2 * sizeof(t_obj_type *)));
	*buffer = new_buffer;
	return (SUCCESS);
}

static int fill_layout_buffer_row(t_obj_type *types_table, t_obj_type *buffer, char *line, t_list **error_log)
{
	t_obj_type  type;
	int         i;

    i = 0;
    while (line[i] && line[i] != '\n')
    {
	    type = match_type(types_table, line[i]);
		if (is_type_valid(types_table, type))
            buffer[i] = type;
		else
		{
			log_error_message(error_log, INVALID_OBJ_ERR, FALSE);
			return (ERROR);
		}
        i++;
    }
	buffer[i] = EMPTY;
	return (SUCCESS);
}

int init_layout_buffer(char *map, t_obj_type ***buffer, t_obj_type *types_table, t_list **error_log)
{
	int     fd;
    char    *line;
    int     y;

    y = 0;
	fd = open(map, O_RDONLY);
    line = get_next_line(fd);
    while (line)
    {
		if (adjust_layout_buffer_size(y, buffer) != SUCCESS)
			return (cleanup_on_exit(line));
	    (*buffer)[y] = (t_obj_type *)ft_calloc((count_columns(line) + 1), sizeof(t_obj_type));
        if (!(*buffer)[y])
	        return (cleanup_on_exit(line));
		if (fill_layout_buffer_row(types_table, (*buffer)[y], line, error_log) != SUCCESS)
			return (cleanup_on_exit(line));
        free(line);
        line = get_next_line(fd);
        y++;
    }
	close(fd);
    return (SUCCESS);
}
