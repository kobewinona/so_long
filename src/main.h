/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:53:03 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/01 14:53:04 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include "so_long.h"
# include "../utils/utils.h"
# include "src.h"

/*
mlx lost memory with no window

==58843== LEAK SUMMARY:
==58843==    definitely lost: 7,920 bytes in 156 blocks
==58843==    indirectly lost: 3,712 bytes in 83 blocks
==58843==      possibly lost: 2,456 bytes in 57 blocks
==58843==    still reachable: 13,688 bytes in 115 blocks
==58843==         suppressed: 1,376,958 bytes in 400 blocks
==58843== Rerun with --leak-check=full to see details of leaked memory
==58843==
==58843== For lists of detected and suppressed errors, rerun with: -s
==58843== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 53 from 4)
 */

/*
mlx lost memory with a window

==20129== LEAK SUMMARY:
==20129==    definitely lost: 14,120 bytes in 207 blocks
==20129==    indirectly lost: 5,392 bytes in 115 blocks
==20129==      possibly lost: 3,944 bytes in 73 blocks
==20129==    still reachable: 52,385 bytes in 367 blocks
==20129==                       of which reachable via heuristic:
==20129==                         newarray           : 112 bytes in 2 blocks
==20129==         suppressed: 1,377,830 bytes in 418 blocks
==20129== Rerun with --leak-check=full to see details of leaked memory
==20129==
==20129== For lists of detected and suppressed errors, rerun with: -s
==20129== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 53 from 4)
 */

#endif
