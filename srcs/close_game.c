/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:16:42 by avieira-          #+#    #+#             */
/*   Updated: 2025/07/04 16:45:09 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_game(t_game *game)
{
	mlx_loop_end((*game).mlx_ptr);
	mlx_destroy_window((*game).mlx_ptr, (*game.win_ptr));
	mlx_destroy_display((*game).mlx_ptr);
	free(*(cub.mlx_ptr));
	ft_printf("Game Closed");
	exit(1);
	return (0);
}
