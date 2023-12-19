/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:06:26 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/12 11:06:27 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types_table.h"

int	is_type_valid(const t_obj_type *types_table, t_obj_type src)
{
	int	i;

	if (src == INVALID || src == END)
		return (FALSE);
	i = 0;
	while (i < 256)
	{
		if (types_table[i++] == src)
			return (TRUE);
	}
	return (FALSE);
}

t_obj_type	match_type(const t_obj_type *types_table, int src)
{
	if (!types_table)
		return (INVALID);
	return (types_table[(unsigned char) src]);
}

int	count_valid_types(const t_obj_type *table)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < 256)
	{
		if (table[i] != INVALID && table[i] != END)
			count++;
		i++;
	}
	return (count);
}

int	create_types_table(t_obj_type **types_table, t_list **error_log)
{
	int	i;

	*types_table = (t_obj_type *)malloc(256 * sizeof(t_obj_type));
	if (!(*types_table))
		return (ERROR);
	i = 0;
	while (i < 256)
		(*types_table)[i++] = INVALID;
	(*types_table)['0'] = EMPTY;
	(*types_table)['1'] = WALL;
	(*types_table)['P'] = PLAYER;
	(*types_table)['C'] = COLLECTABLE;
	(*types_table)['E'] = EXIT;
	return (SUCCESS);
}
