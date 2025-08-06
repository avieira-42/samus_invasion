/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_displays_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 01:08:56 by avieira-          #+#    #+#             */
/*   Updated: 2025/08/06 13:48:57 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/so_long_bonus.h"

void	free_death_screen(t_game *game)
{
	if (game->death_screen.image)
		mlx_destroy_image(game->mlx_ptr, game->death_screen.image);
}

void	free_victory_screen(t_game *game)
{
	if (game->victory_screen.image)
		mlx_destroy_image(game->mlx_ptr, game->victory_screen.image);
}

int	free_displays(t_game *game)
{
	free_death_screen(game);
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

void	open_victory_screen(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->victory_screen.image, 0, 0);
	game->end = TRUE;
}

void	open_death_screen(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->death_screen.image, 0, 0);
	game->end = TRUE;
}
