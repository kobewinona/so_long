/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:17:55 by dklimkin          #+#    #+#             */
/*   Updated: 2023/09/26 13:17:55 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*find_nl(char *buff, size_t *len)
{
	ssize_t	i;

	i = 0;
	while (buff && buff[i] != '\0')
	{
		if (buff[i] == '\n')
		{
			*len += i + 1;
			return (&buff[i]);
		}
		i++;
	}
	*len += i;
	return (NULL);
}

ssize_t	ft_read(int fd, char *buffer)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read > 0 && bytes_read <= BUFFER_SIZE)
		buffer[bytes_read] = '\0';
	return (bytes_read);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	s1_len;
	size_t	i;

	s1_len = 0;
	while (s1 && s1[s1_len] != '\0')
		s1_len++;
	s2 = (char *)malloc((s1_len + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int	ftm_lstadd_back(t_line_lst **lst, void *content)
{
    t_line_lst	*new;
    t_line_lst	*current;

	new = (t_line_lst *)malloc(sizeof(t_line_lst));
	if (!new)
		return (0);
	new->content = ft_strdup(content);
	if (!new->content)
	{
		free(new);
		return (0);
	}
	new->next = (NULL);
	if (*lst == NULL)
		*lst = new;
	else
	{
		current = *lst;
		while (current->next)
			current = current->next;
		current->next = new;
	}
	return (1);
}

void	ft_delone(t_line_lst **lst, void (*del)(void *))
{
    t_line_lst	*temp;

	temp = *lst;
	*lst = (*lst)->next;
	if (temp)
	{
		if (del && temp && temp->content)
			del(temp->content);
		free(temp);
	}
}
