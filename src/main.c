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

void    handle_error(t_gstate *game, char *err_msg)
{
    if (err_msg)
        print_error_msg(err_msg);
    exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_gstate	game;

    if (argc == 1)
        handle_error(&game, NO_MAP_ERR);
    if (argc > 2)
        handle_error(&game, TOO_MANY_ARGUMENTS_ERR);
    game.layout = create_layout(argv[1]);
    if (!game.layout)
        handle_error(&game, NULL);
	game.window = create_window();
    init_buffer(&game);
	if (!game.window.mlx_ptr || !game.window.win_ptr || !game.buffer)
        handle_error(&game, UNKNOWN_ERR);
	game.ground = create_ground(game.window);
    render_buffer(&game);
	mlx_loop(game.window.mlx_ptr);
	return (0);
}
