/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <marvavieira-@student.42porto.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:59:03 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/30 17:41:26 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_breno_idle_sprites(t_game *game)
{
	load_sprite(game->mlx_ptr, &game->player.idle.sprite[0], "sprites/breno.xpm");
}

void	init_breno_running_sprites(t_game *game)
{
	int		i;
	char *player_running_sprite_paths[14];

	i = 0;
	player_running_sprite_paths[0] = "sprites/brenoruning1.xpm";
	player_running_sprite_paths[1] = "sprites/brenoruning2.xpm";
	player_running_sprite_paths[2] = "sprites/brenoruning3.xpm";
	player_running_sprite_paths[3] = "sprites/brenoruning4.xpm";
	player_running_sprite_paths[4] = "sprites/brenoruning5.xpm";
	player_running_sprite_paths[5] = "sprites/brenoruning6.xpm";
	player_running_sprite_paths[6] = "sprites/brenoruning7.xpm";
	player_running_sprite_paths[7] = "sprites/brenoruning8.xpm";
	player_running_sprite_paths[8] = "sprites/brenoruning9.xpm";
	player_running_sprite_paths[9] = "sprites/brenoruning10.xpm";
	player_running_sprite_paths[10] = "sprites/brenoruning11.xpm";
	player_running_sprite_paths[11] = "sprites/brenoruning12.xpm";
	player_running_sprite_paths[12] = "sprites/brenoruning13.xpm";
	player_running_sprite_paths[13] = "sprites/brenoruning14.xpm";
	while (i < 14)
	{
		load_sprite(game->mlx_ptr, &game->player.running.sprite[i],
			player_running_sprite_paths[i]);
		i++;
	}
}

void	init_breno_attack_sprites(t_game *game)
{
	int		i;
	char *player_attack_sprite_paths[14];

	i = 0;
	player_attack_sprite_paths[0] = "sprites/brenoattack1.xpm";
	player_attack_sprite_paths[1] = "sprites/brenoattack2.xpm";
	player_attack_sprite_paths[2] = "sprites/brenoattack3.xpm";
	player_attack_sprite_paths[3] = "sprites/brenoattack4.xpm";
	player_attack_sprite_paths[4] = "sprites/brenoattack5.xpm";
	player_attack_sprite_paths[5] = "sprites/brenoattack6.xpm";
	player_attack_sprite_paths[6] = "sprites/brenoattack7.xpm";
	player_attack_sprite_paths[7] = "sprites/brenoattack8.xpm";
	player_attack_sprite_paths[8] = "sprites/brenoattack9.xpm";
	player_attack_sprite_paths[9] = "sprites/brenoattack10.xpm";
	player_attack_sprite_paths[10] = "sprites/brenoattack11.xpm";
	player_attack_sprite_paths[11] = "sprites/brenoattack12.xpm";
	player_attack_sprite_paths[12] = "sprites/brenoattack13.xpm";
	player_attack_sprite_paths[13] = "sprites/brenoattack14.xpm";
	while (i < 14)
	{
		load_sprite(game->mlx_ptr, &game->player.attack.sprite[i],
			player_attack_sprite_paths[i]);
		i++;
	}
}

void	init_breno_jumping_sprites(t_game *game)
{
	int		i;
	char *player_jumping_sprite_paths[4];

	i = 0;
	player_jumping_sprite_paths[0] = "sprites/brenojumping1.xpm";
	player_jumping_sprite_paths[1] = "sprites/brenojumping2.xpm";
	player_jumping_sprite_paths[2] = "sprites/brenojumping3.xpm";
	player_jumping_sprite_paths[3] = "sprites/brenojumping4.xpm";
	while (i < 4)
	{
		load_sprite(game->mlx_ptr, &game->player.jumping.sprite[i],
			player_jumping_sprite_paths[i]);
		i++;
	}
}

void	init_breno_sprites(t_game *game)
{
	init_breno_idle_sprites(game);
	init_breno_running_sprites(game);
	init_breno_attack_sprites(game);
	init_breno_jumping_sprites(game);
	init_breno_falling_sprites(game);
	init_player_moves_sprites(game);
}
