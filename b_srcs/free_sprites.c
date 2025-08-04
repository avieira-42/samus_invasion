/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:04:29 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/08/04 12:58:38 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/so_long.h"

void    free_player_running(t_game *game)
{
        int     i;

        i = 14;
        while (i--)
                mlx_destroy_image(game->mlx_ptr, game->player.running.sprite[i].image);
}

void    free_player_idle(t_game *game)
{
        int i;

        i = 1;
        while(i--)
                mlx_destroy_image(game->mlx_ptr, game->player.idle.sprite[i].image);
}

void	free_player_jumping(t_game *game)
{
	int	i;

	i = 4;
	while(i--)
		mlx_destroy_image(game->mlx_ptr, game->player.jumping.sprite[i].image);

}

void	free_player_attack(t_game *game)
{
	int	i;

	i = 14;
	while(i--)
		mlx_destroy_image(game->mlx_ptr, game->player.jumping.sprite[i].image);

}

void	free_player_falling(t_game *game)
{
	int	i;

	i = 4;
	while(i--)
		mlx_destroy_image(game->mlx_ptr, game->player.jumping.sprite[i].image);

}

void	free_player_moves(t_game *game)
{
	int	i;

	i = 10;
	while(i--)
		mlx_destroy_image(game->mlx_ptr, game->player.move.sprite[i].image);

}

void    free_player_sprites(t_game *game)
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

	i = 6;
	while (i--)
		mlx_destroy_image(game->mlx_ptr, game->samus.sprite[i].image);
}

void    free_sprites(t_game *game)
{
	free_player_sprites(game);
	free_samus_sprites(game);
	mlx_destroy_image(game->mlx_ptr, game->bckgrnd.sprite.image);
	mlx_destroy_image(game->mlx_ptr, game->tile.sprite.image);
	mlx_destroy_image(game->mlx_ptr, game->towel.sprite.image);
	mlx_destroy_image(game->mlx_ptr, game->portal.sprite.image);
	mlx_destroy_image(game->mlx_ptr, game->portal.sprite2.image);
}
