/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */ /*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:03:20 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/07/17 17:48:20 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_game(t_game *game)
{
	//INITIALIZE ALL MEHCANICS FIELDS//
	//SEPERATE INIT PER FIELD//


	//init_main_struct(game);
	init_window(game);
	game->game_start = false;
	game->fd = 0;
	game->gravity = GRAVITY_ACC;
	game->delta = 0;
	game->ground_pos = 0;
	game->ceiling_pos = 0;
	game->right_wall_pos = 0;
	game->left_wall_pos = 0;
	game->last_frame_time = get_time();
	game->walls = NULL;
	game->items = NULL;
	game->map.height = game->map.height * TILE_SIZE_Y;
	game->map.width = game->map.width * TILE_SIZE_X;

	//init_image(game);
	game->image.x = 0;
	game->image.y = 0;
	game->image.bits_per_pixel = 0;
	game->image.line_length = 0;
	game->image.endian = 0;
	game->image.image = NULL;
	game->image.addr = NULL;

	// init_background(game);
	game->bckgrnd.pos.x = 0;
	game->bckgrnd.pos.y = 0;
	game->bckgrnd.scale = 0.7;
	game->bckgrnd.sprite.image = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/quasar.xpm", &game->bckgrnd.sprite.x, &game->bckgrnd.sprite.y);
	game->bckgrnd.sprite.addr = mlx_get_data_addr(game->bckgrnd.sprite.image, &game->bckgrnd.sprite.bits_per_pixel, &game->bckgrnd.sprite.line_length, &game->bckgrnd.sprite.endian);

	
	// init_tile(game);
	game->tile.sprite.image = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/tile.xpm", &game->tile.sprite.x, &game->tile.sprite.y);
	game->tile.sprite.addr = mlx_get_data_addr(game->tile.sprite.image, &game->tile.sprite.bits_per_pixel, &game->tile.sprite.line_length, &game->tile.sprite.endian);
	game->tile.pos.x = 0;
	game->tile.pos.y = 0;
	game->tile.vect.height = 0;
	game->tile.vect.width = 0;
	game->tile.next = NULL;

	//init_towel(game);
	game->towel.sprite.image = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/towel.xpm", &game->towel.sprite.x, &game->towel.sprite.y);
	game->towel.sprite.addr = mlx_get_data_addr(game->towel.sprite.image, &game->towel.sprite.bits_per_pixel, &game->towel.sprite.line_length, &game->towel.sprite.endian);
	game->towel.pos.x = 0;
	game->towel.pos.y = 0;
	game->tile.vect.height = 0;
	game->tile.vect.width = 0;
	game->tile.next = NULL;

	//init_portal(game);
	game->portal.sprite.image = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/offportal.xpm", &game->portal.sprite.x, &game->portal.sprite.y);
	game->portal.sprite.addr = mlx_get_data_addr(game->portal.sprite.image, &game->portal.sprite.bits_per_pixel, &game->portal.sprite.line_length, &game->portal.sprite.endian);
	game->portal.sprite2.image = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/portal.xpm", &game->portal.sprite2.x, &game->portal.sprite2.y);
	game->portal.sprite2.addr = mlx_get_data_addr(game->portal.sprite2.image, &game->portal.sprite2.bits_per_pixel, &game->portal.sprite2.line_length, &game->portal.sprite2.endian);
	game->portal.pos.x = 0;
	game->portal.pos.y = 0;
	game->portal.tmp_pos.x = 0;
	game->portal.tmp_pos.y = 0;

	// init_player(game);
	game->player.movements = 0;
	game->player.touching_ground = false;
	game->player.touching_leftwall = false;
	game->player.touching_rightwall = false;
	game->player.touching_ceiling = false;
	game->player.touching_exit = false;
	game->player.pos.x = 0;
	game->player.pos.y = 0;
	game->player.tmp_pos.x = 0;
	game->player.tmp_pos.y = 0;
	game->player.direction.x = 0;
	game->player.direction.y = 0;
	game->player.velocity.x = 0;
	game->player.velocity.y = 0;
	game->player.jump.active = false;
	game->player.jump.t_started = 0;
	game->player.jump.t_elapsed = 0;
	game->player.jump.velocity = 0;
	game->player.vect.height = 0;
	game->player.vect.width = 0;
	game->player.camera.x = 0;
	game->player.camera.y = 0;
		//init_player_sprites(game);
				//init_player_idle(game);
	game->player.idle.i = 0;
	game->player.idle.timer = 0;
	game->player.idle.sprite[0].image = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/breno.xpm", &game->player.idle.sprite[0].x, &game->player.idle.sprite[0].y);
	game->player.idle.sprite[0].addr = mlx_get_data_addr(game->player.idle.sprite[0].image, &game->player.idle.sprite[0].bits_per_pixel, &game->player.idle.sprite[0].line_length, &game->player.idle.sprite[0].endian);
				//init_player_running(game);
	game->player.running.i = 0;
	game->player.running.timer = 0;
	game->player.running.sprite[0].image = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/brenoruning1.xpm", &game->player.running.sprite[0].x, &game->player.running.sprite[0].y);
	game->player.running.sprite[0].addr = mlx_get_data_addr(game->player.running.sprite[0].image, &game->player.running.sprite[0].bits_per_pixel, &game->player.running.sprite[0].line_length, &game->player.running.sprite[0].endian);
	game->player.running.sprite[1].image = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/brenoruning2.xpm", &game->player.running.sprite[1].x, &game->player.running.sprite[1].y);
	game->player.running.sprite[1].addr = mlx_get_data_addr(game->player.running.sprite[1].image, &game->player.running.sprite[1].bits_per_pixel, &game->player.running.sprite[1].line_length, &game->player.running.sprite[1].endian);
	game->player.running.sprite[2].image = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/brenoruning3.xpm", &game->player.running.sprite[2].x, &game->player.running.sprite[2].y);
	game->player.running.sprite[2].addr = mlx_get_data_addr(game->player.running.sprite[2].image, &game->player.running.sprite[2].bits_per_pixel, &game->player.running.sprite[2].line_length, &game->player.running.sprite[2].endian);
	game->player.running.sprite[3].image = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/brenoruning4.xpm", &game->player.running.sprite[3].x, &game->player.running.sprite[3].y);
	game->player.running.sprite[3].addr = mlx_get_data_addr(game->player.running.sprite[3].image, &game->player.running.sprite[3].bits_per_pixel, &game->player.running.sprite[3].line_length, &game->player.running.sprite[3].endian);
	game->player.running.sprite[4].image = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/brenoruning5.xpm", &game->player.running.sprite[4].x, &game->player.running.sprite[4].y);
	game->player.running.sprite[4].addr = mlx_get_data_addr(game->player.running.sprite[4].image, &game->player.running.sprite[4].bits_per_pixel, &game->player.running.sprite[4].line_length, &game->player.running.sprite[4].endian);
	game->player.running.sprite[5].image = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/brenoruning6.xpm", &game->player.running.sprite[5].x, &game->player.running.sprite[5].y);
	game->player.running.sprite[5].addr = mlx_get_data_addr(game->player.running.sprite[5].image, &game->player.running.sprite[5].bits_per_pixel, &game->player.running.sprite[5].line_length, &game->player.running.sprite[5].endian);
	game->player.running.sprite[6].image = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/brenoruning7.xpm", &game->player.running.sprite[6].x, &game->player.running.sprite[6].y);
	game->player.running.sprite[6].addr = mlx_get_data_addr(game->player.running.sprite[6].image, &game->player.running.sprite[6].bits_per_pixel, &game->player.running.sprite[6].line_length, &game->player.running.sprite[6].endian);
	game->player.running.sprite[7].image = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/brenoruning8.xpm", &game->player.running.sprite[7].x, &game->player.running.sprite[7].y);
	game->player.running.sprite[7].addr = mlx_get_data_addr(game->player.running.sprite[7].image, &game->player.running.sprite[7].bits_per_pixel, &game->player.running.sprite[7].line_length, &game->player.running.sprite[7].endian);
	game->player.running.sprite[8].image = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/brenoruning9.xpm", &game->player.running.sprite[8].x, &game->player.running.sprite[8].y);
	game->player.running.sprite[8].addr = mlx_get_data_addr(game->player.running.sprite[8].image, &game->player.running.sprite[8].bits_per_pixel, &game->player.running.sprite[8].line_length, &game->player.running.sprite[8].endian);
	game->player.running.sprite[9].image = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/brenoruning10.xpm", &game->player.running.sprite[9].x, &game->player.running.sprite[9].y);
	game->player.running.sprite[9].addr = mlx_get_data_addr(game->player.running.sprite[9].image, &game->player.running.sprite[9].bits_per_pixel, &game->player.running.sprite[9].line_length, &game->player.running.sprite[9].endian);
	game->player.running.sprite[10].image = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/brenoruning11.xpm", &game->player.running.sprite[10].x, &game->player.running.sprite[10].y);
	game->player.running.sprite[10].addr = mlx_get_data_addr(game->player.running.sprite[10].image, &game->player.running.sprite[10].bits_per_pixel, &game->player.running.sprite[10].line_length, &game->player.running.sprite[10].endian);
	game->player.running.sprite[11].image = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/brenoruning12.xpm", &game->player.running.sprite[11].x, &game->player.running.sprite[11].y);
	game->player.running.sprite[11].addr = mlx_get_data_addr(game->player.running.sprite[11].image, &game->player.running.sprite[11].bits_per_pixel, &game->player.running.sprite[11].line_length, &game->player.running.sprite[11].endian);
	game->player.running.sprite[12].image = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/brenoruning13.xpm", &game->player.running.sprite[12].x, &game->player.running.sprite[12].y);
	game->player.running.sprite[12].addr = mlx_get_data_addr(game->player.running.sprite[12].image, &game->player.running.sprite[12].bits_per_pixel, &game->player.running.sprite[12].line_length, &game->player.running.sprite[12].endian);
	game->player.running.sprite[13].image = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/brenoruning14.xpm", &game->player.running.sprite[13].x, &game->player.running.sprite[13].y);
	game->player.running.sprite[13].addr = mlx_get_data_addr(game->player.running.sprite[13].image, &game->player.running.sprite[13].bits_per_pixel, &game->player.running.sprite[13].line_length, &game->player.running.sprite[13].endian);

	//init_enemy(game);
	game->enemy.pos.x = game->player.pos.x + 30;
	game->enemy.pos.y = game->player.pos.y;
	game->enemy.tmp_pos.x = 0;
	game->enemy.tmp_pos.y = 0;
	game->enemy.sprite.image = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/samus.xpm", &game->enemy.sprite.x, &game->enemy.sprite.y);
	game->enemy.sprite.addr = mlx_get_data_addr(game->enemy.sprite.image, &game->enemy.sprite.bits_per_pixel, &game->enemy.sprite.line_length, &game->enemy.sprite.endian);

	// init_camera(game);
	game->camera.x = game->player.pos.x - SCREEN_SIZE_X / 2;
	game->camera.y = game->player.pos.y - SCREEN_SIZE_Y / 2;
}
