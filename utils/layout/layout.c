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

static int is_file_ext_valid(char *filename)
{
    char    *ext;

    ext = ft_strrchr(filename, '.');
    if (!ext)
        return (FALSE);
    if (ft_strncmp(ext, VALID_MAP_EXT, ft_strlen(ext)) != 0)
    {
        print_error_msg(INCORRECT_MAP_EXT_ERR);
        return (FALSE);
    }
    return (TRUE);
}

t_layout   *create_layout(char *filename)
{
    t_layout    *layout;
    int         fd;
    char        *line;

    if (is_file_ext_valid(filename) == FALSE)
        return (NULL);
    layout = malloc(sizeof(t_layout));
    if (!layout)
        return ((void *)0);
    fd = open(filename, O_RDONLY);
    return (layout);
}
