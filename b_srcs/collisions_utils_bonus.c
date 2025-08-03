/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:00:57 by avieira-          #+#    #+#             */
/*   Updated: 2025/07/30 00:16:20 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/so_long.h"

int	contiguous_ceiling(t_game *game, t_point floor_pos)
{
	t_tile	*walls;

	walls = game->walls;
	while (walls)
	{
		if (floor_pos.y <= walls->pos.y + TILE_SIZE_Y + 10
			&& floor_pos.y >= walls->pos.y + TILE_SIZE_Y
			&& floor_pos.x == walls->pos.x)
			return (1);
		walls = walls->next;
	}
	return (0);
}

int	contiguous_floor(t_game *game, t_point ceiling_pos)
{
	t_tile	*walls;

	walls = game->walls;
	while (walls)
	{
		if (ceiling_pos.y + TILE_SIZE_Y >= walls->pos.y - 10
			&& ceiling_pos.y + TILE_SIZE_Y <= walls->pos.y
			&& ceiling_pos.x == walls->pos.x)
			return (1);
		walls = walls->next;
	}
	return (0);
}
