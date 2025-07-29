/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:15:09 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/29 16:15:12 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_map(t_game *game)
{
	int		y;
	int		x;

	y = 0;
	while (game->map.text[y])
	{
		x = 0;
		while (game->map.text[y][x])
		{
			if (game->map.text[y][x] == 'P')
				draw_player(game, &y, &x);
			else if (game->map.text[y][x] == 'C')
				draw_towel(game, &y, &x);
			else if (game->map.text[y][x] == '1')
				draw_tile(game, &y, &x);
			else if (game->map.text[y][x] == 'E')
				draw_portal(game, &y, &x);
			x++;
		}
		y++;
	}
}
