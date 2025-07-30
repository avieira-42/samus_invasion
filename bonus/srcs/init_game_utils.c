/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 02:32:50 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/31 00:25:41 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_tile(t_game *game)
{
	game->tile.pos.x = 0;
	game->tile.pos.y = 0;
	game->tile.vect.height = 0;
	game->tile.vect.width = 0;
	game->tile.next = NULL;
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
	init_portal_sprite(game);
}

void	init_enemy(t_game *game)
{
	game->samus.i = 0;
	game->samus.timer = 0;
	game->samus.tmp_pos.x = 0;
	game->samus.tmp_pos.y = 0;
	init_samus_sprites(game);
}

void	init_player(t_game *game)
{
	game->player.attack_counter = 0;
	game->player.attack_timer = 25;
	game->player.attacking = false;
	game->player.orientation = 1;
	game->player.touching_ground = false;
	game->player.touching_leftwall = false;
	game->player.touching_rightwall = false;
	game->player.touching_ceiling = false;
	game->player.touching_exit = false;
	game->player.pos.x = 0;
	game->player.pos.y = 0;
	game->player.tmp_pos = game->player.pos;
	game->player.direction = game->player.pos;
	game->player.velocity = game->player.pos;
	game->player.jump.active = false;
	game->player.jump.t_started = 0;
	game->player.jump.t_elapsed = 0;
	game->player.jump.velocity = 0;
	game->player.vect.height = 0;
	game->player.vect.width = 0;
	game->player.camera.x = 0;
	game->player.camera.y = 0;
	game->player.move.count = 0;
	init_breno_sprites(game);
}
