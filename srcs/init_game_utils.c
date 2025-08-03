/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <marvin@4avieira-@student.42porto.com  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 20:21:22 by avieira-          #+#    #+#             */
/*   Updated: 2025/07/29 20:42:21 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_tile(t_game *game)
{
	game->tile.image = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/tile.xpm", &game->tile.x, &game->tile.y);
	game->tile.addr = mlx_get_data_addr(game->tile.image,
			&game->tile.bits_per_pixel, &game->tile.line_length,
			&game->tile.endian);
}

void	init_towel(t_game *game)
{
	game->towel.image = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/towel.xpm", &game->towel.x, &game->towel.y);
	game->towel.addr = mlx_get_data_addr(game->towel.image,
			&game->towel.bits_per_pixel, &game->towel.line_length,
			&game->towel.endian);
}

void	init_portal(t_game *game)
{
	game->portal.image = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/portal.xpm", &game->portal.x, &game->portal.y);
	game->portal.addr = mlx_get_data_addr(game->portal.image,
			&game->portal.bits_per_pixel, &game->portal.line_length,
			&game->portal.endian);
}

void	init_player(t_game *game)
{
	game->player.image = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/breno.xpm", &game->player.x, &game->player.y);
	game->player.addr = mlx_get_data_addr(game->player.image,
			&game->player.bits_per_pixel, &game->player.line_length,
			&game->player.endian);
}
