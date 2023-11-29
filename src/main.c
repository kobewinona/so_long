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

#include "../includes/so_long.h"

int	main(void)
{
	int		trgb;

	trgb = create_trgb(0, 20, 150, 200);
	printf("create_trgb %d\n", trgb);
	printf("get_t %d\n", get_t(trgb));
	printf("get_r %d\n", get_r(trgb));
	printf("get_g %d\n", get_g(trgb));
	printf("get_b %d\n", get_b(trgb));
	mlx_new_window(mlx_init(), 100, 100, "so long");
	return (1);
}
