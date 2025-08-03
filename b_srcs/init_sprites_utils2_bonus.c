/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <marvavieira-@student.42porto.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:13:27 by avieira-          #+#    #+#             */
/*   Updated: 2025/07/31 17:17:43 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/so_long.h"

void	init_breno_falling_sprites(t_game *game)
{
	int		i;
	char	*player_falling_sprite_paths[4];

	i = 0;
	game->player.falling.i = 0;
	game->player.falling.timer = 0;
	player_falling_sprite_paths[0] = "b_textures/brenofalling1.xpm";
	player_falling_sprite_paths[1] = "b_textures/brenofalling2.xpm";
	player_falling_sprite_paths[2] = "b_textures/brenofalling3.xpm";
	player_falling_sprite_paths[3] = "b_textures/brenofalling4.xpm";
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
		"b_textures/quasar.xpm");
}

void	init_player_moves_sprites(t_game *game)
{
	int		i;
	char	*player_moves_sprite_paths[10];

	i = 0;
	player_moves_sprite_paths[0] = "b_textures/0.xpm";
	player_moves_sprite_paths[1] = "b_textures/1.xpm";
	player_moves_sprite_paths[2] = "b_textures/2.xpm";
	player_moves_sprite_paths[3] = "b_textures/3.xpm";
	player_moves_sprite_paths[4] = "b_textures/4.xpm";
	player_moves_sprite_paths[5] = "b_textures/5.xpm";
	player_moves_sprite_paths[6] = "b_textures/6.xpm";
	player_moves_sprite_paths[7] = "b_textures/7.xpm";
	player_moves_sprite_paths[8] = "b_textures/8.xpm";
	player_moves_sprite_paths[9] = "b_textures/9.xpm";
	while (i < 10)
	{
		load_sprite(game->mlx_ptr, &game->player.move.sprite[i],
			player_moves_sprite_paths[i]);
		i++;
	}
}
