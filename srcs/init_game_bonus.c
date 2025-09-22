/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 02:02:37 by avieira-          #+#    #+#             */
/*   Updated: 2025/08/08 02:51:23 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/samus_invasion.h"

void	init_window(t_game *game)
{
	if (game->reset == FALSE)
	{
		game->map.height = game->map.height * TILE_SIZE_Y;
		game->map.width = game->map.width * TILE_SIZE_X;
		(*game).mlx_ptr = mlx_init();
		(*game).win_ptr = mlx_new_window((*game).mlx_ptr,
				SCREEN_SIZE_X, SCREEN_SIZE_Y, "so_long_bonus");
	}
}

void	init_main_struct(t_game *game)
{
	game->game_start = FALSE;
	game->reset = TRUE;
	game->end = FALSE;
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
	game->camera.x = game->player.pos.x - SCREEN_SIZE_X / 2;
	game->camera.y = game->player.pos.y - SCREEN_SIZE_Y / 2;
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
	zero_sprites(&game->bckgrnd.sprite, 1);
	init_bckgrnd_sprite(game);
}

void	init_game(t_game *game)
{
	init_window(game);
	init_image(game);
	init_background(game);
	init_item(game);
	init_tile(game);
	init_exit(game);
	init_enemy(game);
	init_player(game);
	init_main_struct(game);
	init_finish_screens(game);
}
