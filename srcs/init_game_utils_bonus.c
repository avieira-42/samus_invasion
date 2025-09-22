/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 02:32:50 by avieira-          #+#    #+#             */
/*   Updated: 2025/08/06 17:32:10 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/samus_invasion.h"

void	init_tile(t_game *game)
{
	game->tile.pos.x = 0;
	game->tile.pos.y = 0;
	game->tile.next = NULL;
	zero_sprites(&game->tile.sprite, 1);
	init_tile_sprite(game);
}

void	init_item(t_game *game)
{
	game->towel.orientation = 1;
	game->towel.tmp_pos.x = 0;
	game->towel.tmp_pos.y = 0;
	game->towel.pos.x = 0;
	game->towel.pos.y = 0;
	game->towel.next = NULL;
	zero_sprites(&game->towel.sprite, 1);
	init_towel_sprite(game);
}

void	init_exit(t_game *game)
{
	game->portal.tmp_pos.x = 0;
	game->portal.tmp_pos.y = 0;
	game->portal.pos.x = 0;
	game->portal.pos.y = 0;
	game->portal.pos.x = 0;
	game->portal.pos.y = 0;
	game->portal.tmp_pos.x = 0;
	game->portal.tmp_pos.y = 0;
	zero_sprites(&game->portal.sprite, 1);
	zero_sprites(&game->portal.sprite2, 1);
	init_portal_sprite(game);
}

void	init_enemy(t_game *game)
{
	game->samus.i = 0;
	game->samus.timer = 0;
	game->samus.tmp_pos.x = 0;
	game->samus.tmp_pos.y = 0;
	zero_sprites(game->samus.sprite, 14);
	init_samus_sprites(game);
}

void	init_player(t_game *game)
{
	game->player.attack_counter = 0;
	game->player.attack_timer = 25;
	game->player.attacking = FALSE;
	game->player.orientation = 1;
	game->player.touching_ground = FALSE;
	game->player.touching_leftwall = FALSE;
	game->player.touching_rightwall = FALSE;
	game->player.touching_ceiling = FALSE;
	game->player.touching_exit = FALSE;
	game->player.pos.x = 0;
	game->player.pos.y = 0;
	game->player.tmp_pos = game->player.pos;
	game->player.direction = game->player.pos;
	game->player.velocity = game->player.pos;
	game->player.jump.max_count = game->map.height / TILE_SIZE_Y;
	game->player.jump.count = 0;
	game->player.jump.active = FALSE;
	game->player.jump.t_started = 0;
	game->player.jump.t_elapsed = 0;
	game->player.jump.velocity = 0;
	game->player.camera.x = 0;
	game->player.camera.y = 0;
	game->player.move.count = 0;
	init_breno_sprites(game);
}
