/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:14:04 by dklimkin          #+#    #+#             */
/*   Updated: 2023/09/26 13:14:05 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdlib.h>
# include "so_long.h"

typedef struct s_lines_lst
{
	char			    *content;
	struct s_lines_lst	*next;
}					    t_line_lst;
char	*get_next_line(int fd);
char	*find_nl(char *buff, size_t *len);
ssize_t	ft_read(int fd, char *buffer);
int	    ftm_lstadd_back(t_line_lst **lst, void *content);
void	ft_delone(t_line_lst **lst, void (*del)(void *));

#endif
