/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:32:35 by avieira-          #+#    #+#             */
/*   Updated: 2025/07/29 01:15:28 by a-soeiro         ###   ########.fr       */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
   
	// PARSE ARGV
	if (!parse(&game, argc, argv))
		return (1);
	init_game(&game);
	mlx_hook(game.win_ptr, 17, 0, free_displays, &game);
	mlx_hook(game.win_ptr, 02, 1L<<0, key_pressed, &game);
	mlx_loop_hook(game.mlx_ptr, game_loop, &game);
	mlx_loop(game.mlx_ptr);
}
