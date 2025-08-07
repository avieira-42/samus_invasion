/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:15:09 by avieira-          #+#    #+#             */
/*   Updated: 2025/08/05 21:34:02 by avieira-         ###   ########.fr       */
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
			else if (game->map.text[y][x] == '0')
				draw_empty_space(game, &y, &x);
			x++;
		}
		y++;
	}
	if (game->finish == 1)
		free_displays(game);
}
