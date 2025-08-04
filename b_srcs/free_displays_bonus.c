/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_displays_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 01:08:56 by avieira-          #+#    #+#             */
/*   Updated: 2025/08/04 16:10:09 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/so_long_bonus.h"

int	free_displays(t_game *game)
{
	mlx_loop_end((*game).mlx_ptr);
	ft_free_matrix(game->map.text);
	free_sprites(game);
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
