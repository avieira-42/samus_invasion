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
	game->game_start = false;
	game->mlx_ptr = NULL;
	init_window(&game);
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

	//init_map(game);
	game->map.text = read_map();
	game->map.height = 0;
	game->map.width = 0;
	game->map.C_count = 0;
	game->map.P_count = 0;
	game->map.E_count = 0;
	game->map.X_count = 0;

	//init_image(game);
	game->image.x = 0;
	game->image.y = 0;
	game->bits_per_pixel = 0;
	game->line_length = 0;
	game->endian = 0;
	game->image.image = NULL;
	game->image.addr = NULL;

	// init_background(game);
	game->bckgrnd.pos.x = 0;
	game->bckgrnd.pos.y = 0;
	game->bckgrnd.scale = 0.7;
	game->bckgrnd.sprite.image = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/quasar.xpm", &game->bckgrnd.sprite.x, &game->bckgrnd.sprite.y);
	game->bckgrnd.sprite.addr = mlx_get_data_addr(game->bckgrnd.sprite.image, &game->bckgrnd.sprite.bits_per_pixel, &game->bckgrnd.sprite.line_length, &game->bckgrnd.sprite.endian);

	
	// init_tile(game);
	game->tile.
	game->tile.sprite.image = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/tile.xpm", &game->tile.sprite.x, &game->tile.sprite.y);
	game->tile.sprite.addr = mlx_get_data_addr(game->tile.sprite.image, &game->tile.sprite.bits_per_pixel, &game->tile.sprite.line_length, &game->tile.sprite.endian);
	
	//init_walls(game);


	//init_towel(game);
	game->towel.sprite.image = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/towel.xpm", &game->towel.sprite.x, &game->towel.sprite.y);
	game->towel.sprite.addr = mlx_get_data_addr(game->towel.sprite.image, &game->towel.sprite.bits_per_pixel, &game->towel.sprite.line_length, &game->towel.sprite.endian);


	//init_items(game);


	//init_portal(game);
	game->portal.sprite.image = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/offportal.xpm", &game->portal.sprite.x, &game->portal.sprite.y);
	game->portal.sprite.addr = mlx_get_data_addr(game->portal.sprite.image, &game->portal.sprite.bits_per_pixel, &game->portal.sprite.line_length, &game->portal.sprite.endian);
	game->portal.sprite2.image = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/portal.xpm", &game->portal.sprite2.x, &game->portal.sprite2.y);
	game->portal.sprite2.addr = mlx_get_data_addr(game->portal.sprite2.image, &game->portal.sprite2.bits_per_pixel, &game->portal.sprite2.line_length, &game->portal.sprite2.endian);


	// init_player(game);
	game->player.movements = 0;
	game->player.velocity.x = 0;
	game->player.velocity.y = 0;
	game->player.direction.x = 0;
	game->player.direction.y = 0;
	game->player.jump.active = false;
	game->player.jump.t_elapsed = 0;
	game->player.jump.t_started = 0;
	game->player.jump.velocity = 0;
	game->player.sprite.image = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/breno.xpm", &game->player.sprite.x, &game->player.sprite.y);
	game->player.sprite.addr = mlx_get_data_addr(game->player.sprite.image, &game->player.sprite.bits_per_pixel, &game->player.sprite.line_length, &game->player.sprite.endian);

	//init_enemy(game);
	game->enemy.pos.x = game->player.pos.x + 30;
	game->enemy.pos.y = game->player.pos.y;
	game->enemy.sprite.image = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/samus.xpm", &game->enemy.sprite.x, &game->enemy.sprite.y);
	game->enemy.sprite.addr = mlx_get_data_addr(game->enemy.sprite.image, &game->enemy.sprite.bits_per_pixel, &game->enemy.sprite.line_length, &game->enemy.sprite.endian);

	// init_camera(game);
	game->camera.x = game->player.pos.x - SCREEN_SIZE_X / 2;
	game->camera.y = game->player.pos.y - SCREEN_SIZE_Y / 2;

}
