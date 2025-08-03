/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_collisions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:17:13 by avieira-          #+#    #+#             */
/*   Updated: 2025/07/30 00:24:45 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/so_long.h"

int	enemy_touching_wall_left(t_game *game, t_enemy *enemy)
{
	t_tile	*walls;

	walls = game->walls;
	while (walls)
	{
		if (enemy->pos.x + ENEMY_WIDTH <= walls->pos.x + TILE_SIZE_X * 0.4
			&& enemy->pos.x + ENEMY_WIDTH >= walls->pos.x - 10
			&& ((enemy->pos.y >= walls->pos.y + 2
					&& enemy->pos.y <= walls->pos.y + TILE_SIZE_Y - 2)
				|| (enemy->pos.y + ENEMY_HEIGHT <= walls->pos.y
					+ TILE_SIZE_Y + 2
					&& enemy->pos.y + ENEMY_HEIGHT >= walls->pos.y + 2)))
		{
			enemy->pos.x = walls->pos.x - ENEMY_WIDTH - 10;
			return (1);
		}
		walls = walls->next;
	}
	return (0);
}

int	enemy_touching_wall_right(t_game *game, t_enemy *enemy)
{
	t_tile	*walls;

	walls = game->walls;
	while (walls)
	{
		if (enemy->pos.x >= walls->pos.x + TILE_SIZE_X * 0.4
			&& enemy->pos.x <= walls->pos.x + TILE_SIZE_X + 10
			&& ((enemy->pos.y >= walls->pos.y + 2
					&& enemy->pos.y <= walls->pos.y + TILE_SIZE_Y - 2)
				|| (enemy->pos.y + ENEMY_HEIGHT <= walls->pos.y
					+ TILE_SIZE_Y + 2
					&& enemy->pos.y + ENEMY_HEIGHT >= walls->pos.y + 2)))
		{
			enemy->pos.x = walls->pos.x + TILE_SIZE_X + 10;
			return (1);
		}
		walls = walls->next;
	}
	return (0);
}

int	enemy_touching_floor(t_game *game, t_enemy *enemy)
{
	t_tile	*walls;

	walls = game->walls;
	while (walls)
	{
		if (enemy->pos.y + ENEMY_HEIGHT >= walls->pos.y - 5
			&& enemy->pos.y + ENEMY_HEIGHT <= walls->pos.y + TILE_SIZE_Y * 0.5
			&& ((enemy->pos.x + ENEMY_WIDTH * 0.8 <= walls->pos.x + TILE_SIZE_X
					&& enemy->pos.x + ENEMY_WIDTH * 0.8 >= walls->pos.x)
				|| (enemy->pos.x + 20 >= walls->pos.x
					&& enemy->pos.x + 20 <= walls->pos.x + TILE_SIZE_X))
			&& !contiguous_ceiling(game, walls->pos))
		{
			enemy->pos.y = walls->pos.y - TILE_SIZE_Y;
			return (1);
		}
		walls = walls->next;
	}
	return (0);
}

int	enemy_touching_ceiling(t_game *game, t_enemy *enemy)
{
	t_tile	*walls;

	walls = game->walls;
	while (walls)
	{
		if (enemy->pos.y >= walls->pos.y + TILE_SIZE_Y * 0.5
			&& enemy->pos.y <= walls->pos.y + TILE_SIZE_Y
			&& ((enemy->pos.x + ENEMY_WIDTH <= walls->pos.x + TILE_SIZE_X
					&& enemy->pos.x + ENEMY_WIDTH >= walls->pos.x)
				|| (enemy->pos.x >= walls->pos.x
					&& enemy->pos.x <= walls->pos.x + TILE_SIZE_X))
			&& !contiguous_floor(game, walls->pos))
			return (1);
		walls = walls->next;
	}
	return (0);
}

int	enemy_touching_exit(t_game *game, t_enemy *enemy)
{
	if ((enemy->pos.x >= game->portal.pos.x
			&& enemy->pos.x <= game->portal.pos.x + TILE_SIZE_X)
		&& (enemy->pos.y >= game->portal.pos.y
			&& enemy->pos.y <= game->portal.pos.y + TILE_SIZE_X))
		return (1);
	return (0);
}
