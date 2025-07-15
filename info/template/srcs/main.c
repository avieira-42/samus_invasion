/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:32:35 by avieira-          #+#    #+#             */
/*   Updated: 2025/07/15 02:18:17 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	main(void)
{
	t_cub	cub;

	init_window(&cub);
	cub_init(&cub);
	mlx_hook(cub.win_ptr, 02, (1L<<0), key_pressed, &cub);
	mlx_hook(cub.win_ptr, 03, (1L<<1), key_released, &cub);
	mlx_hook(cub.win_ptr, 17, 0, free_displays, &cub);
	mlx_loop_hook(cub.mlx_ptr, game_loop, &cub);
	mlx_loop(cub.mlx_ptr);
	drawtexture(&cub.image, &cub.player.sprite, cub.player.camera, 1);
}



