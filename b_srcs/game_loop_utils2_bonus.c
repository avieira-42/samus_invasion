/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_utils2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 21:50:14 by avieira-          #+#    #+#             */
/*   Updated: 2025/08/06 13:52:17 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/so_long_bonus.h"

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
	game->camera.x = game->player.pos.x - SCREEN_SIZE_X / 2;
	if (game->camera.x < 0)
		game->camera.x = 0;
	if (game->camera.x > CAMERA_END_X)
		game->camera.x = CAMERA_END_X;
	game->player.camera.x = game->player.pos.x - game->camera.x;
	game->player.camera.y = game->player.pos.y;
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
