/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 20:50:26 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/29 16:17:17 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_player(t_game *game, int *y, int *x)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player.image,
		*x * SPRITE_SIZE, *y * SPRITE_SIZE);
	game->p.x = *x;
	game->p.y = *y;
}

void	draw_tile(t_game *game, int *y, int *x)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->tile.image,
		*x * SPRITE_SIZE, *y * SPRITE_SIZE);
}

void	draw_portal(t_game *game, int *y, int *x)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->portal.image,
		*x * SPRITE_SIZE, *y * SPRITE_SIZE);
}

void	draw_towel(t_game *game, int *y, int *x)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->towel.image,
		*x * SPRITE_SIZE, *y * SPRITE_SIZE);
}
