/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_displays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 01:08:56 by avieira-          #+#    #+#             */
/*   Updated: 2025/07/31 20:43:55 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	free_displays(t_game *game)
{
	ft_free_matrix(game->map.text);
	mlx_loop_end((*game).mlx_ptr);
	free_items(game->items);
	free_enemies(game->enemies);
	free_walls(game->walls);
	mlx_destroy_window((*game).mlx_ptr, (*game).win_ptr);
	mlx_destroy_display((*game).mlx_ptr);
	free(game->mlx_ptr);
	ft_printf("Closing Application!");
	exit(1);
	return (0);
}
