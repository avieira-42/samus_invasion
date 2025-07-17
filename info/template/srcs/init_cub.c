/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:03:20 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/07/17 03:10:28 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	cub_init(t_cub *cub)
{
	//INITIALIZE ALL MEHCANICS FIELDS//
	//SEPERATE INIT PER FIELD//
	

	cub->fd = 0;
	cub->items = NULL;
	cub->delta = 0; cub->game_start = false;
	cub->last_frame_time = get_time();

	// init_enemy(cub)
	cub->enemy.pos.x = cub->player.pos.x + 30;
	cub->enemy.pos.y = cub->player.pos.y;

	// init_player(cub)
	cub->player.direction.x = 0;
	cub->player.direction.y = 0;
	cub->player.pos.x  = 500;
	cub->player.pos.y = SCREEN_SIZE_Y / 2;

	// init_background(cub)
	cub->bckgrnd.pos.x = 0;
	cub->bckgrnd.pos.y = 0;

	// INIT VELOCITY (vel_init())
	cub->player.velocity.x = 0;
	cub->player.velocity.y = 0;

	// INITIALIZE JUMP (jump_init())
	cub->player.jump.active = false;
	cub->player.jump.t_elapsed = 0;
	cub->player.jump.t_started = 0;
	cub->player.jump.velocity = 0;

	// INITIALIZE BACKGROUND (bckgrnd_init())
	cub->bckgrnd.scale = 0.7;
	cub->bckgrnd.sprite.image = mlx_xpm_file_to_image(cub->mlx_ptr, "sprites/quasar.xpm", &cub->bckgrnd.sprite.x, &cub->bckgrnd.sprite.y);
	cub->bckgrnd.sprite.addr = mlx_get_data_addr(cub->bckgrnd.sprite.image, &cub->bckgrnd.sprite.bits_per_pixel, &cub->bckgrnd.sprite.line_length, &cub->bckgrnd.sprite.endian);

	// INITIALIZE SPRITES
	cub->player.sprite.image = mlx_xpm_file_to_image(cub->mlx_ptr, "sprites/breno.xpm", &cub->player.sprite.x, &cub->player.sprite.y);
	cub->player.sprite.addr = mlx_get_data_addr(cub->player.sprite.image, &cub->player.sprite.bits_per_pixel, &cub->player.sprite.line_length, &cub->player.sprite.endian);
	cub->tile.sprite.image = mlx_xpm_file_to_image(cub->mlx_ptr, "sprites/tile.xpm", &cub->tile.sprite.x, &cub->tile.sprite.y);
	cub->tile.sprite.addr = mlx_get_data_addr(cub->tile.sprite.image, &cub->tile.sprite.bits_per_pixel, &cub->tile.sprite.line_length, &cub->tile.sprite.endian);
	cub->enemy.sprite.image = mlx_xpm_file_to_image(cub->mlx_ptr, "sprites/samus.xpm", &cub->enemy.sprite.x, &cub->enemy.sprite.y);
	cub->enemy.sprite.addr = mlx_get_data_addr(cub->enemy.sprite.image, &cub->enemy.sprite.bits_per_pixel, &cub->enemy.sprite.line_length, &cub->enemy.sprite.endian);
	cub->towel.sprite.image = mlx_xpm_file_to_image(cub->mlx_ptr, "sprites/towel.xpm", &cub->towel.sprite.x, &cub->towel.sprite.y);
	cub->towel.sprite.addr = mlx_get_data_addr(cub->towel.sprite.image, &cub->towel.sprite.bits_per_pixel, &cub->towel.sprite.line_length, &cub->towel.sprite.endian);
	cub->portal.sprite.image = mlx_xpm_file_to_image(cub->mlx_ptr, "sprites/offportal.xpm", &cub->portal.sprite.x, &cub->portal.sprite.y);
	cub->portal.sprite.addr = mlx_get_data_addr(cub->portal.sprite.image, &cub->portal.sprite.bits_per_pixel, &cub->portal.sprite.line_length, &cub->portal.sprite.endian);
	cub->portal.sprite2.image = mlx_xpm_file_to_image(cub->mlx_ptr, "sprites/portal.xpm", &cub->portal.sprite2.x, &cub->portal.sprite2.y);
	cub->portal.sprite2.addr = mlx_get_data_addr(cub->portal.sprite2.image, &cub->portal.sprite2.bits_per_pixel, &cub->portal.sprite2.line_length, &cub->portal.sprite2.endian);
	
	// INITIALIZE MAP
	cub->map = read_map();
	
	// INITIALIZE CAMERA
	cub->camera.x = cub->player.pos.x - SCREEN_SIZE_X / 2;
	cub->camera.y = cub->player.pos.y - SCREEN_SIZE_Y / 2;
}
