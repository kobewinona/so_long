/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:31:49 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/12 20:31:50 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_handler.h"

int	print_error_message(char *message, int return_value)
{
	if (message)
	{
		ft_putstr_fd(RED, STDERR_FILENO);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd(GREY, STDERR_FILENO);
		ft_putstr_fd("● ", STDERR_FILENO);
		ft_putstr_fd(message, STDERR_FILENO);
		ft_putstr_fd(DEFAULT, STDERR_FILENO);
	}
	return (return_value);
}

static void	print_error_log(t_list **error_log)
{
	t_list	*current;

	current = *error_log;
	ft_putstr_fd(GREY, STDERR_FILENO);
	while (current)
	{
		ft_putstr_fd("╰┈➤ ", STDERR_FILENO);
		ft_putstr_fd(current->content, STDERR_FILENO);
		current = current->next;
		if (current)
			ft_putstr_fd("  ", STDERR_FILENO);
	}
	ft_putstr_fd(DEFAULT, STDERR_FILENO);
	ft_lstclear(error_log, free);
}

static int	is_message_duplicated(t_list *error_log, char *message)
{
	while (error_log)
	{
		if (ft_strncmp(error_log->content, message, ft_strlen(message)) == 0)
			return (TRUE);
		error_log = error_log->next;
	}
	return (FALSE);
}

int	log_error_message(t_list **error_log, char *error_message, int return_value)
{
	char	*message;
	t_list	*new_log;

	if (error_message && !is_message_duplicated(*error_log, error_message))
	{
		message = ft_strdup(error_message);
		if (!message)
			return (print_error_message(UNKNOWN_ERR, return_value));
		new_log = ft_lstnew(message);
		if (!new_log)
			return (print_error_message(UNKNOWN_ERR, return_value));
		ft_lstadd_front(error_log, new_log);
	}
	return (return_value);
}

void	handle_error(int result, void *component, t_error error)
{
	if (result == ERROR || result == FALSE)
	{
		if (error.message)
			print_error_message(error.message, error.is_fatal);
		if (error.error_log)
			print_error_log(error.error_log);
		ft_putchar_fd('\n', STDERR_FILENO);
		if (component && error.cleanup)
			error.cleanup(component);
		if (error.is_fatal)
			exit(EXIT_FAILURE);
	}
}
