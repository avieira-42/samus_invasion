/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 01:55:11 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/30 01:57:51 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	position_sprites(t_game *game, int x, int y)
{
	if (game->map.text[y][x] == 'P')
	{
		game->player.pos.x = x * TILE_SIZE_X;
		game->player.pos.y = y * TILE_SIZE_Y;
	}
	else if (game->map.text[y][x] == 'C')
		position_item(game);
	else if (game->map.text[y][x] == '1')
		position_wall(game);
	else if (game->map.text[y][x] == 'E')
		position_portal(game);
	else if (game->map.text[y][x] == 'X')
		position_enemy(game);
}
