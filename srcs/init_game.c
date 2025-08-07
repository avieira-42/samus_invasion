/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 20:27:37 by avieira-          #+#    #+#             */
/*   Updated: 2025/08/05 21:55:17 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_window(t_game *game)
{
	game->map.width *= SPRITE_SIZE;
	game->map.height *= SPRITE_SIZE;
	(*game).mlx_ptr = mlx_init();
	(*game).win_ptr = mlx_new_window((*game).mlx_ptr,
			game->map.width, game->map.height, "game3d");
}

void	init_main_struct(t_game *game)
{
	game->finish = 0;
	game->fd = 0;
	game->moves = 0;
	game->p.x = 0;
	game->p.y = 0;
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
	game->bckgrnd.image = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/quasar.xpm", &game->bckgrnd.x, &game->bckgrnd.y);
	game->bckgrnd.addr = mlx_get_data_addr(game->bckgrnd.image,
			&game->bckgrnd.bits_per_pixel, &game->bckgrnd.line_length,
			&game->bckgrnd.endian);
}

void	init_game(t_game *game)
{
	init_window(game);
	init_main_struct(game);
	init_image(game);
	init_background(game);
	init_empty_space(game);
	init_tile(game);
	init_towel(game);
	init_portal(game);
	init_player(game);
}
