/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sprites_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:04:29 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/08/04 23:32:12 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/so_long_bonus.h"

void	free_player_running(t_game *game)
{
	int	i;

	i = 14;
	while (i--)
	{
		if (game->player.running.sprite[i].image)
			mlx_destroy_image(game->mlx_ptr,
				game->player.running.sprite[i].image);
	}
}

void	free_player_idle(t_game *game)
{
	int	i;

	i = 4;
	while (i--)
	{
		if (game->player.idle.sprite[i].image)
			mlx_destroy_image(game->mlx_ptr,
				game->player.idle.sprite[i].image);
	}
}

void	free_player_jumping(t_game *game)
{
	int	i;

	i = 4;
	while (i--)
	{
		if (game->player.jumping.sprite[i].image)
			mlx_destroy_image(game->mlx_ptr,
				game->player.jumping.sprite[i].image);
	}
}

void	free_player_attack(t_game *game)
{
	int	i;

	i = 14;
	while (i--)
	{
		if (game->player.attack.sprite[i].image)
			mlx_destroy_image(game->mlx_ptr,
				game->player.attack.sprite[i].image);
	}
}

void	free_player_falling(t_game *game)
{
	int	i;

	i = 4;
	while (i--)
	{
		if (game->player.falling.sprite[i].image)
			mlx_destroy_image(game->mlx_ptr,
				game->player.falling.sprite[i].image);
	}
}
