/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 02:02:37 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/30 02:27:54 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_window(t_game *game)
{
	game->map.height = game->map.height * TILE_SIZE_Y;
	game->map.width = game->map.width * TILE_SIZE_X;
	(*game).mlx_ptr = mlx_init();
	(*game).win_ptr = mlx_new_window((*game).mlx_ptr,
			SCREEN_SIZE_X, SCREEN_SIZE_Y, "game3d");
}

void	init_main_struct(t_game *game)
{
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
	game->enemies = NULL;
}

void	init_image(t_game *game)
{
	game->image.x = 0;
	game->image.y = 0;
	game->image.bits_per_pixel = 0;
	game->image.line_length = 0;
	game->image.endian = 0;
	game->image.image = NULL;
	game->image.addr = NULL;
}

void	init_background(t_game *game)
{
	game->bckgrnd.pos.x = 0;
	game->bckgrnd.pos.y = 0;
	game->bckgrnd.scale = 0.7;
	game->bckgrnd.sprite.image = mlx_xpm_file_to_image(game->mlx_ptr,
		"sprites/quasar.xpm", &game->bckgrnd.sprite.x, &game->bckgrnd.sprite.y);
	game->bckgrnd.sprite.addr = mlx_get_data_addr(game->bckgrnd.sprite.image,
		&game->bckgrnd.sprite.bits_per_pixel, &game->bckgrnd.sprite.line_length,
		&game->bckgrnd.sprite.endian);
}

void	init_game(t_game *game)
{
	init_window(game);
	init_main_struct(game);
	init_image(game);
	init_background(game);
	
}
