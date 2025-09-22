/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:02:30 by avieira-          #+#    #+#             */
/*   Updated: 2025/09/22 18:02:34 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_empty_space(t_game *game)
{
	game->empty_space.image = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/empty_space.xpm", &game->empty_space.x,
			&game->empty_space.y);
	if (game->empty_space.image)
		game->empty_space.addr = mlx_get_data_addr(game->empty_space.image,
				&game->empty_space.bits_per_pixel,
				&game->empty_space.line_length,
				&game->empty_space.endian);
	else
		free_displays(game);
}

void	init_tile(t_game *game)
{
	game->tile.image = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/tile.xpm", &game->tile.x, &game->tile.y);
	if (game->tile.image)
		game->tile.addr = mlx_get_data_addr(game->tile.image,
				&game->tile.bits_per_pixel, &game->tile.line_length,
				&game->tile.endian);
	else
		free_displays(game);
}

void	init_towel(t_game *game)
{
	game->towel.image = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/towel.xpm", &game->towel.x, &game->towel.y);
	if (game->towel.image)
		game->towel.addr = mlx_get_data_addr(game->towel.image,
				&game->towel.bits_per_pixel, &game->towel.line_length,
				&game->towel.endian);
	else
		free_displays(game);
}

void	init_portal(t_game *game)
{
	game->portal.image = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/portal.xpm", &game->portal.x, &game->portal.y);
	if (game->portal.image)
		game->portal.addr = mlx_get_data_addr(game->portal.image,
				&game->portal.bits_per_pixel, &game->portal.line_length,
				&game->portal.endian);
	else
		free_displays(game);
}

void	init_player(t_game *game)
{
	game->player.image = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/breno.xpm", &game->player.x, &game->player.y);
	if (game->player.image)
		game->player.addr = mlx_get_data_addr(game->player.image,
				&game->player.bits_per_pixel, &game->player.line_length,
				&game->player.endian);
	else
		free_displays(game);
}
