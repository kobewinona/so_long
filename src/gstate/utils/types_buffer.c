/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 13:28:38 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/25 13:28:39 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gstate.h"

static int	cleanup_on_exit(char *line)
{
	free(line);
	return (ERROR);
}

static int	count_width(const char *line)
{
	int	count;

	count = 0;
	while (line[count] && line[count] != '\n')
		count++;
	return (count);
}

static int	adjust_buffer_size(
		int height, t_obj_type ***buffer, t_list **error_log)
{
	size_t		old_size;
	size_t		new_size;
	t_obj_type	**new_buffer;

	old_size = (height * sizeof(t_obj_type *));
	new_size = ((height + 2) * sizeof(t_obj_type *));
	new_buffer = ft_realloc((*buffer), old_size, new_size);
	if (!new_buffer)
		return (log_error_message(error_log, UNKNOWN_ERR, ERROR));
	ft_bzero((new_buffer + height), (2 * sizeof(t_obj_type *)));
	(*buffer) = new_buffer;
	return (SUCCESS);
}

static int	fill_buffer(t_obj_type *buffer, char *line, t_gdata gdata)
{
	t_obj_type	type;
	int			x;

	x = 0;
	while (line[x] && line[x] != '\n')
	{
		type = match_type(gdata.types_table, line[x]);
		if (is_type_valid(gdata.types_table, type))
			buffer[x] = type;
		else
			return (log_error_message(gdata.error_log, INVALID_OBJ_ERR, ERROR));
		x++;
	}
	buffer[x] = END;
	return (SUCCESS);
}

int	init_types_buffer(
		const char *mapfile, t_obj_type ***buffer, t_size *size, t_gdata gdata)
{
	int		fd;
	char	*line;
	int		y;

	y = 0;
	fd = open(mapfile, O_RDONLY);
	line = get_next_line(fd);
	size->width = count_width(line);
	while (line)
	{
		if (adjust_buffer_size(y, buffer, gdata.error_log) != SUCCESS)
			return (cleanup_on_exit(line));
		(*buffer)[y] = (t_obj_type *)ft_calloc(
				(size->width + 1), sizeof(t_obj_type));
		if (!(*buffer)[y])
			return (cleanup_on_exit(line));
		if (fill_buffer((*buffer)[y], line, gdata) != SUCCESS)
			return (cleanup_on_exit(line));
		free(line);
		line = get_next_line(fd);
		y++;
	}
	size->height = y;
	close(fd);
	return (SUCCESS);
}
