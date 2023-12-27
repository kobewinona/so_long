/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layers_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:56:30 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/27 17:56:31 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gstate.h"

void	cleanup_layers_buffer(t_list ***layers_buffer)
{
	int	y;
	int	x;

	if (layers_buffer)
	{
		y = 0;
		while (layers_buffer[y])
		{
			x = 0;
			while (layers_buffer[y][x])
			{
				ft_lstclear(&layers_buffer[y][x], free);
				x++;
			}
			free(layers_buffer[y]);
			y++;
		}
		free(layers_buffer);
	}
}

static t_list	*create_list_node(t_obj_type type)
{
	t_obj	*obj;
	t_list	*node;

	obj = create_object(type);
	if (!obj)
		return (NULL);
	node = ft_lstnew(obj);
	if (!node)
	{
		cleanup_object(obj);
		return (NULL);
	}
	return (node);
}

static int	fill_buffer(const t_obj_type *game_buffer, t_list **row)
{
	t_obj_type	type;
	t_list		*node;
	int			x;

	x = 0;
	node = NULL;
	while (game_buffer[x] != END)
	{
		node = create_list_node(BACKGROUND);
		if (!node)
			return (ERROR);
		ft_lstadd_back(&row[x], node);
		type = game_buffer[x];
		if (type != EMPTY)
		{
			node = create_list_node(type);
			if (!node)
				return (ERROR);
			ft_lstadd_back(&row[x], node);
		}
		x++;
	}
	return (SUCCESS);
}

int	init_layers_buffer(
		t_obj_type **game_buffer, t_list ****layers_buffer, t_gdata gdata)
{
	int		y;

	(*layers_buffer) = (t_list ***)ft_calloc(
			(gdata.size.height + 1), sizeof(t_list **));
	if (!(*layers_buffer))
		return (log_error_message(gdata.error_log, UNKNOWN_ERR, ERROR));
	y = 0;
	while (game_buffer[y])
	{
		(*layers_buffer)[y] = (t_list **)ft_calloc(
				(gdata.size.width + 1), sizeof(t_list *));
		if (!(*layers_buffer)[y])
			return (log_error_message(gdata.error_log, UNKNOWN_ERR, ERROR));
		if (fill_buffer(game_buffer[y], (*layers_buffer)[y]) != SUCCESS)
			return (log_error_message(gdata.error_log, UNKNOWN_ERR, ERROR));
		y++;
	}
	return (SUCCESS);
}
