/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_utils2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 21:50:14 by avieira-          #+#    #+#             */
/*   Updated: 2025/11/27 04:48:09 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../libs/minilibx-linux/mlx.h"
#include "../engine/macros.h"
#include "../engine/clearing.h"
#include "../engine/rendering.h"
#include "main.h"

void	move_player(t_game *game)
{
	if (game->player.attack_timer > 24)
		game->player.pos.y += game->player.velocity.y * game->delta;
	game->player.pos.x += game->player.direction.x
		* game->player.velocity.x * game->delta;
}

void	end_game(t_game *game)
{
	if (game->player.touching_exit && game->items == NULL)
		open_victory_screen(game);
}

void	update_camera(t_game *game)
{
	game->camera.x = game->player.pos.x - SCREEN_SIZE_X / 2.0;
	game->camera.y = game->player.pos.y - SCREEN_SIZE_Y / 1.3;
	if (game->camera.x < 0)
		game->camera.x = 0;
	if (game->camera.x > CAMERA_END_X)
		game->camera.x = CAMERA_END_X;
	if (game->camera.y < 0)
		game->camera.y = 0;
	if (game->camera.y > CAMERA_END_Y)
		game->camera.y = CAMERA_END_Y;
	game->player.camera.x = game->player.pos.x - game->camera.x;
	game->player.camera.y = game->player.pos.y - game->camera.y;
}

void	load_image(t_game *game)
{
	(*game).image.image = mlx_new_image((*game).mlx_ptr, SCREEN_SIZE_X,
			SCREEN_SIZE_Y);
	(*game).image.addr = mlx_get_data_addr((*game).image.image,
			&(*game).image.bits_per_pixel, &(*game).image.line_length,
			&(*game).image.endian);
}

void	draw_background(t_game *game)
{
	drawtexture(&game->image, &game->bckgrnd.sprite,
		game->bckgrnd.pos, game->bckgrnd.scale);
}
