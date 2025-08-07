/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:32:35 by avieira-          #+#    #+#             */
/*   Updated: 2025/08/05 21:55:33 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (!parse(&game, argc, argv))
		return (1);
	init_game(&game);
	draw_map(&game);
	mlx_hook(game.win_ptr, 17, 0, free_displays, &game);
	mlx_hook(game.win_ptr, 02, 1L << 0, key_pressed, &game);
	mlx_loop(game.mlx_ptr);
}
