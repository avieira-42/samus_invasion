/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <marvavieira-@student.42porto.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:13:27 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/31 00:36:38 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_breno_falling_sprites(t_game *game)
{
	int		i;
	char *player_falling_sprite_paths[4];

	i = 0;
	game->player.falling.i = 0;
	game->player.falling.timer = 0;
	player_falling_sprite_paths[0] = "sprites/brenofalling1.xpm";
	player_falling_sprite_paths[1] = "sprites/brenofalling2.xpm";
	player_falling_sprite_paths[2] = "sprites/brenofalling3.xpm";
	player_falling_sprite_paths[3] = "sprites/brenofalling4.xpm";
	while (i < 4)
	{
		load_sprite(game->mlx_ptr, &game->player.falling.sprite[i],
			player_falling_sprite_paths[i]);
		i++;
	}
}

void	init_bckgrnd_sprite(t_game *game)
{
	load_sprite(game->mlx_ptr, &game->bckgrnd.sprite,
			"sprites/quasar.xpm");
}


void	init_player_moves_sprites(t_game *game)
{
	int i;
	char	*player_moves_sprite_paths[10];

	i = 0;
	player_moves_sprite_paths[0] = "sprites/0.xpm";
	player_moves_sprite_paths[1] = "sprites/1.xpm";
	player_moves_sprite_paths[2] = "sprites/2.xpm";
	player_moves_sprite_paths[3] = "sprites/3.xpm";
	player_moves_sprite_paths[4] = "sprites/4.xpm";
	player_moves_sprite_paths[5] = "sprites/5.xpm";
	player_moves_sprite_paths[6] = "sprites/6.xpm";
	player_moves_sprite_paths[7] = "sprites/7.xpm";
	player_moves_sprite_paths[8] = "sprites/8.xpm";
	player_moves_sprite_paths[9] = "sprites/9.xpm";
	while (i < 10)
	{
		load_sprite(game->mlx_ptr, &game->player.move.sprite[i],
			player_moves_sprite_paths[i]);
		i++;
	}
}

