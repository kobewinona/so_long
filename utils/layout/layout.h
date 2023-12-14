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
#define LAYOUT_H
# include "so_long.h"
# include "./types_table/types_table.h"
# include "./layout_buffer/layout_buffer.h"
# include "./layout_validator/layout_validator.h"

typedef struct s_layout t_layout;

struct s_layout {
    int         rows;
    int         columns;
    t_obj_type  *types_table;
    t_obj_type  **buffer;
	void        (*print_buffer)(t_layout *, t_xy);
	void	    (*cleanup)(t_layout **);
};

int     create_layout(t_layout **layout, const char *mapfile, t_list **error_log);
void    print_buffer(t_layout *layout, t_xy temp);
void    cleanup_layout(t_layout **layout);

#endif
