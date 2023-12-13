/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:31:56 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/12 20:31:57 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H
# include "so_long.h"
# include "../layout/layout.h"

typedef void (*cleanup_func)(void **);

typedef struct s_error {
	cleanup_func    cleanup;
	char            *message;
	t_list          **error_log;
	int             is_fatal;
}   t_error;

// TODO Do I need "is_on_exit"? Maybe just pass FALSE or ERROR instead so it would return exactly that?
void    handle_error(int result, void *component, t_error error);
int     log_error_message(t_list **error_log, char *error_message, int is_on_exit);
int     print_error_message(char *message, int is_on_exit);

#endif
