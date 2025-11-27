/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:04:29 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/11/27 04:00:33 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/minilibx-linux/mlx.h"
#include "../types.h"
#include "../clearing.h"

void	free_player_moves(t_game *game)
{
	int	i;

	i = 10;
	while (i--)
	{
		if (game->player.move.sprite[i].image)
			mlx_destroy_image(game->mlx_ptr, game->player.move.sprite[i].image);
	}
}

void	free_player_sprites(t_game *game)
{
	free_player_idle(game);
	free_player_running(game);
	free_player_jumping(game);
	free_player_falling(game);
	free_player_attack(game);
	free_player_moves(game);
}

void	free_samus_sprites(t_game *game)
{
	int	i;

	i = 14;
	while (i--)
	{
		if (game->samus.sprite[i].image)
			mlx_destroy_image(game->mlx_ptr, game->samus.sprite[i].image);
	}
}

void	free_sprites(t_game *game)
{
	free_player_sprites(game);
	free_samus_sprites(game);
	if (game->bckgrnd.sprite.image)
		mlx_destroy_image(game->mlx_ptr, game->bckgrnd.sprite.image);
	if (game->tile.sprite.image)
		mlx_destroy_image(game->mlx_ptr, game->tile.sprite.image);
	if (game->towel.sprite.image)
		mlx_destroy_image(game->mlx_ptr, game->towel.sprite.image);
	if (game->portal.sprite.image)
		mlx_destroy_image(game->mlx_ptr, game->portal.sprite.image);
	if (game->portal.sprite2.image)
		mlx_destroy_image(game->mlx_ptr, game->portal.sprite2.image);
}
