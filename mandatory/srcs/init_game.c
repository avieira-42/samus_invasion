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
	//init_main_struct(game);
	init_window(game);
	game->finish = 0;
	game->fd = 0;
	game->moves = 0;
	game->p.x = 0;
	game->p.y = 0;

	// init_map(game);
	game->map.height = game->map.height * SPRITE_SIZE;
	game->map.width = game->map.width * SPRITE_SIZE;

	// init_image(game);
	game->image.x = 0;
	game->image.y = 0;
	game->image.bits_per_pixel = 0;
	game->image.line_length = 0;
	game->image.endian = 0;
	game->image.image = NULL;
	game->image.addr = NULL;

	// init_background(game);
	game->bckgrnd.image = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/quasar.xpm", &game->bckgrnd.x, &game->bckgrnd.y);
	game->bckgrnd.addr = mlx_get_data_addr(game->bckgrnd.image, &game->bckgrnd.bits_per_pixel, &game->bckgrnd.line_length, &game->bckgrnd.endian);

	// init_tile(game);
	game->tile.image = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/tile.xpm", &game->tile.x, &game->tile.y);
	game->tile.addr = mlx_get_data_addr(game->tile.image, &game->tile.bits_per_pixel, &game->tile.line_length, &game->tile.endian);

	//init_towel(game);
	game->towel.image = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/towel.xpm", &game->towel.x, &game->towel.y);
	game->towel.addr = mlx_get_data_addr(game->towel.image, &game->towel.bits_per_pixel, &game->towel.line_length, &game->towel.endian);

	//init_portal(game);
	game->portal.image = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/portal.xpm", &game->portal.x, &game->portal.y);
	game->portal.addr = mlx_get_data_addr(game->portal.image, &game->portal.bits_per_pixel, &game->portal.line_length, &game->portal.endian);

	// init_player(game);
	game->player.image = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/breno.xpm", &game->player.x, &game->player.y);
	game->player.addr = mlx_get_data_addr(game->player.image, &game->player.bits_per_pixel, &game->player.line_length, &game->player.endian);
}
