/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gstate_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:39:50 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/18 12:39:52 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gstate.h"

static int	cleanup_on_exit(char *line, t_list **error_log)
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

static int	adjust_layout_buffer_size(
		int height, t_obj ***buffer, t_list **error_log)
{
	size_t	old_size;
	size_t	new_size;
	t_obj	**new_buffer;

	old_size = (height * sizeof(t_obj *));
	new_size = ((height + 2) * sizeof(t_obj *));
	new_buffer = ft_realloc((*buffer), old_size, new_size);
	if (!new_buffer)
		return (log_error_message(error_log, UNKNOWN_ERR, ERROR));
	ft_bzero((new_buffer + height), (2 * sizeof(t_obj *)));
	(*buffer) = new_buffer;
	return (SUCCESS);
}

static int	fill_layout_buffer_row(
		t_gdata gdata, int y, t_obj *buffer, char *line)
{
	t_obj_type	type;
	int			x;

	x = 0;
	while (line[x] && line[x] != '\n')
	{
		type = match_type(gdata.types_table, line[x]);
		if (is_type_valid(gdata.types_table, type))
			buffer[x] = create_object(gdata, type, NULL);
		else
			return (log_error_message(gdata.error_log, INVALID_OBJ_ERR, ERROR));
		x++;
	}
	buffer[x].type = END;
	return (SUCCESS);
}

int	init_game_buffer(const char *mapfile, t_obj ***buffer, t_gdata gdata)
{
	int		fd;
	char	*line;
	int		y;

	y = 0;
	fd = open(mapfile, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (adjust_layout_buffer_size(y, buffer, gdata.error_log) != SUCCESS)
			return (cleanup_on_exit(line, gdata.error_log));
		(*buffer)[y] = (t_obj *)ft_calloc(
				(count_width(line) + 1), sizeof(t_obj));
		if (!(*buffer)[y])
			return (cleanup_on_exit(line, gdata.error_log));
		if (fill_layout_buffer_row(
				gdata, y, (*buffer)[y], line) != SUCCESS)
			return (cleanup_on_exit(line, gdata.error_log));
		free(line);
		line = get_next_line(fd);
		y++;
	}
	close(fd);
	return (SUCCESS);
}
