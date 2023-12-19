/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:46:49 by dklimkin          #+#    #+#             */
/*   Updated: 2023/11/29 16:46:50 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	validate_mapfile(char *filename, t_list **error_log)
{
	char	*ext;
	int		fd;

	ext = ft_strrchr(filename, '.');
	if (!ext)
		return (log_error_message(error_log, UNKNOWN_ERR, ERROR));
	if (ft_strncmp(ext, VALID_MAPFILE_EXT, ft_strlen(ext)) != 0)
		return (log_error_message(error_log, MAPFILE_EXT_ERR, ERROR));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (log_error_message(error_log, READING_MAPFILE_ERR, ERROR));
	close(fd);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_list	*error_log;

	error_log = NULL;
	handle_error(argc != 1, NULL, (t_error){
		NULL, NO_MAPFILE_ERR, &error_log, TRUE});
	handle_error(argc <= 2, NULL, (t_error){
		NULL, TOO_MANY_ARGUMENTS_ERR, &error_log, TRUE});
	handle_error(validate_mapfile(argv[1], &error_log), NULL, (t_error){
		NULL, GAME_ERR, &error_log, TRUE});
	init_game(argv[1], &error_log);
	return (0);
}
