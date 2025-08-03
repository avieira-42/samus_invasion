/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <marvavieira-@student.42porto.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:59:03 by avieira-          #+#    #+#             */
/*   Updated: 2025/07/31 17:11:07 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/so_long.h"

void	init_breno_idle_sprites(t_game *game)
{
	game->player.idle.i = 0;
	game->player.idle.timer = 0;
	load_sprite(game->mlx_ptr, &game->player.idle.sprite[0],
		"b_textures/breno.xpm");
}

void	init_breno_running_sprites(t_game *game)
{
	int		i;
	char	*player_running_sprite_paths[14];

	i = -1;
	game->player.running.i = 0;
	game->player.running.timer = 0;
	player_running_sprite_paths[0] = "b_textures/brenoruning1.xpm";
	player_running_sprite_paths[1] = "b_textures/brenoruning2.xpm";
	player_running_sprite_paths[2] = "b_textures/brenoruning3.xpm";
	player_running_sprite_paths[3] = "b_textures/brenoruning4.xpm";
	player_running_sprite_paths[4] = "b_textures/brenoruning5.xpm";
	player_running_sprite_paths[5] = "b_textures/brenoruning6.xpm";
	player_running_sprite_paths[6] = "b_textures/brenoruning7.xpm";
	player_running_sprite_paths[7] = "b_textures/brenoruning8.xpm";
	player_running_sprite_paths[8] = "b_textures/brenoruning9.xpm";
	player_running_sprite_paths[9] = "b_textures/brenoruning10.xpm";
	player_running_sprite_paths[10] = "b_textures/brenoruning11.xpm";
	player_running_sprite_paths[11] = "b_textures/brenoruning12.xpm";
	player_running_sprite_paths[12] = "b_textures/brenoruning13.xpm";
	player_running_sprite_paths[13] = "b_textures/brenoruning14.xpm";
	while (++i < 14)
	{
		load_sprite(game->mlx_ptr, &game->player.running.sprite[i],
			player_running_sprite_paths[i]);
	}
}

void	init_breno_attack_sprites(t_game *game)
{
	int		i;
	char	*player_attack_sprite_paths[14];

	i = -1;
	game->player.attack.i = 0;
	game->player.attack.timer = 0;
	player_attack_sprite_paths[0] = "b_textures/brenoattack1.xpm";
	player_attack_sprite_paths[1] = "b_textures/brenoattack2.xpm";
	player_attack_sprite_paths[2] = "b_textures/brenoattack3.xpm";
	player_attack_sprite_paths[3] = "b_textures/brenoattack4.xpm";
	player_attack_sprite_paths[4] = "b_textures/brenoattack5.xpm";
	player_attack_sprite_paths[5] = "b_textures/brenoattack6.xpm";
	player_attack_sprite_paths[6] = "b_textures/brenoattack7.xpm";
	player_attack_sprite_paths[7] = "b_textures/brenoattack8.xpm";
	player_attack_sprite_paths[8] = "b_textures/brenoattack9.xpm";
	player_attack_sprite_paths[9] = "b_textures/brenoattack10.xpm";
	player_attack_sprite_paths[10] = "b_textures/brenoattack11.xpm";
	player_attack_sprite_paths[11] = "b_textures/brenoattack12.xpm";
	player_attack_sprite_paths[12] = "b_textures/brenoattack13.xpm";
	player_attack_sprite_paths[13] = "b_textures/brenoattack14.xpm";
	while (++i < 14)
	{
		load_sprite(game->mlx_ptr, &game->player.attack.sprite[i],
			player_attack_sprite_paths[i]);
	}
}

void	init_breno_jumping_sprites(t_game *game)
{
	int		i;
	char	*player_jumping_sprite_paths[4];

	i = 0;
	game->player.jumping.i = 0;
	game->player.jumping.timer = 0;
	player_jumping_sprite_paths[0] = "b_textures/brenojumping1.xpm";
	player_jumping_sprite_paths[1] = "b_textures/brenojumping2.xpm";
	player_jumping_sprite_paths[2] = "b_textures/brenojumping3.xpm";
	player_jumping_sprite_paths[3] = "b_textures/brenojumping4.xpm";
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
