/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:48:37 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/11 15:48:38 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_error.h"

void    print_error_msg(char *err_msg)
{
    if (err_msg)
    {
        ft_putstr_fd(RED, STDERR_FILENO);
        ft_putstr_fd("Error\n", STDERR_FILENO);
        ft_putstr_fd(GREY, STDERR_FILENO);
        ft_putstr_fd(err_msg, STDERR_FILENO);
        ft_putstr_fd(DEFAULT, STDERR_FILENO);
    }
    ft_putchar_fd('\n', STDERR_FILENO);
}
