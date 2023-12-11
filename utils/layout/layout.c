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

static void init_layout_grid(int fd, t_layout **layout)
{
    char    *line;
    int     y;

    y = 0;
    (*layout)->grid = malloc(13 * 6 *sizeof(char));
    while ((line = get_next_line(fd)) != NULL)
    {
        ft_printf("here 2\n");
        (*layout)->columns = (int)ft_strlen(line);
        ft_printf("here 3\n");
        (*layout)->grid[y] = malloc((*layout)->columns * sizeof(char));
        ft_printf("here 4\n");
        if (!(*layout)->grid[y])
        {
            ft_printf("here 5\n");
            free(line);
            return ;
        }
        ft_printf("here 6\n");
        ft_strlcpy((*layout)->grid[y], line, (*layout)->columns + 1);
        ft_printf("here 7\n");
        free(line);
        y++;
    }
    (*layout)->rows = y;
}

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
    ft_printf("here 1\n");
    init_layout_grid(fd, &layout);
    ft_printf("grid %c\n", layout->grid[1][1]);
    return (layout);
}
