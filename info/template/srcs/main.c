/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:32:35 by avieira-          #+#    #+#             */
/*   Updated: 2025/07/05 20:27:07 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	main(void)
{
	t_cub	cub;

	cub_init(&cub);
	init_window(&cub);
	mlx_hook(cub.win_ptr, 02, (1L<<0), key_pressed, &cub); // Listen for key presses
	mlx_hook(cub.win_ptr, 03, (1L<<1), key_released, &cub); // Listen for key releases
	mlx_loop_hook(cub.mlx_ptr, game_loop, &cub);
	mlx_loop(cub.mlx_ptr);
}



