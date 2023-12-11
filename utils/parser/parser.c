/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:32:06 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/11 12:32:07 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

//int count_rows(char **argv)
//{
//    int count;
//
//    count = 0;
//    while (argv[count])
//    {
//        ft_printf("argv[count] %s\n", argv[count]);
//        count++;
//    }
//    return (count);
//}

int count_rows(char **argv)
{
    int y;
    int x;
    int count;

    y = 0;
    count = 0;
    while (argv[y])
    {
        x = 0;
        while (argv[y][x])
        {
            ft_printf("argv[y][%d] %c\n", x, argv[y][x]);
            if (argv[y][x] == '\n')
                count++;
            x++;
        }
        ft_printf("argv[%d] %s\n", y, argv[y]);
        count++;
        y++;
    }
    return (count);
}

void    parse_map(char **argv, t_obj_type ***buffer)
{
    int y;
    int x;

    y = 0;
    while (argv[y])
    {
        x = 0;
        while (argv[y][x])
        {
            if (argv[y][x] == '0')
                (*buffer)[y][x] = GROUND;
            if (argv[y][x] == 'P')
                (*buffer)[y][x] = PLAYER;
            x++;
        }
        y++;
    }
}
