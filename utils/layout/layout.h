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
# include "libgnl.h"
# include "../print_error/print_error.h"

// is file extension valid ✔
// is layout size valid ✖
// is obj count valid ✖
// is map rectangular ✖
// is layout surrounded by walls ✖
// are collectables accessible ✖
// are all the objs valid ✖

// TODO grid is the same as buffer - maybe put buffer here instead of gstate (?)
typedef struct s_layout {
    int     rows;
    int     columns;
    char    **grid;
}   t_layout;

t_layout   *create_layout(char *filename);

#endif
