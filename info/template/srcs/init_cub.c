/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:03:20 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/07/07 00:14:04 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	cub_init(t_cub *cub)
{
	//INITIALIZE ALL MEHCANICS FIELDS//
	//SEPERATE INIT PER FIELD//
	cub->fd = 0;
	cub->delta = 0;
	cub->last_frame_time = get_time();
	cub->player.direction.x = 0;
	cub->player.direction.y = 0;
	cub->player.pos.x  = SCREEN_SIZE_X / 2;
	cub->player.pos.y = SCREEN_SIZE_Y / 2;
	cub->player.velocity.x = 0;
	cub->player.velocity.y = 0;

	// INITIALIZE JUMP (jump_init())
	cub->player.jump.active = false;
	cub->player.jump.duration = 0.5f;
	cub->player.jump.t_elapsed = 0;

	// INITIALIZE DASH (dash_init())
	cub->player.dash.active = false;
	cub->player.dash.duration = 0.5f;
	cub->player.dash.t_elapsed = 0;

	// INITIALIZE PROJECTILE (projectile_init())
	cub->player.projectile.active = false;
	cub->player.projectile.duration = 6.0f;
	cub->player.projectile.t_elapsed = 0;

	// INITIALIZE ATTACK (attack_init())
	cub->player.attack.active = false;
	cub->player.attack.duration = 4.0f;
	cub->player.attack.t_elapsed = 0;

	// INITIALIZE BACKGROUND (bckgrnd_init())
	cub->bckgrnd.image = mlx_xpm_file_to_image(cub->mlx_ptr, "sprites/quasar.xpm", &cub->bckgrnd.x, &cub->bckgrnd.y);
	cub->bckgrnd.addr = mlx_get_data_addr(cub->bckgrnd.image, &cub->bckgrnd.bits_per_pixel, &cub->bckgrnd.line_length, &cub->bckgrnd.endian);

	// INITIALIZE SPRITES
	cub->player.sprite.image = mlx_xpm_file_to_image(cub->mlx_ptr, "sprites/breno.xpm", &cub->player.sprite.x, &cub->player.sprite.y);
	cub->player.sprite.addr = mlx_get_data_addr(cub->player.sprite.image, &cub->player.sprite.bits_per_pixel, &cub->player.sprite.line_length, &cub->player.sprite.endian);
	cub->tile.image = mlx_xpm_file_to_image(cub->mlx_ptr, "sprites/tile.xpm", &cub->tile.x, &cub->image.y);
	cub->tile.addr = mlx_get_data_addr(cub->tile.image, &cub->tile.bits_per_pixel, &cub->tile.line_length, &cub->tile.endian);
	
	//INITIALIZE MAP
	cub->map = draw_map();
}
