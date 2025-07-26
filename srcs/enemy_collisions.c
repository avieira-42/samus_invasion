/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_collisions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:17:13 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/25 14:36:20 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	enemy_touching_wall_left(t_game *game, t_enemy *enemy)
{
	t_tile *walls;

	walls = game->walls;
	while (walls)
	{
		if (ENEMY_POS_X + ENEMY_WIDTH <= walls->pos.x + TILE_SIZE_X * 0.6
			&& ENEMY_POS_X + ENEMY_WIDTH >= walls->pos.x - 10
			&& ENEMY_POS_Y >= walls->pos.y - TILE_SIZE_Y + 2
			&& ENEMY_POS_Y <= walls->pos.y)
		{
			game->left_wall_pos = walls->pos.x - ENEMY_WIDTH - 2;
			return (1);
		}
		walls = walls->next;
	}
	return (0);
}

int	enemy_touching_wall_right(t_game *game, t_enemy *enemy)
{
	t_tile *walls;

	walls = game->walls;
	while (walls)
	{
		if (ENEMY_POS_X >= walls->pos.x + TILE_SIZE_X * 0.6
			&& ENEMY_POS_X <= walls->pos.x + TILE_SIZE_X + 10
			&& ENEMY_POS_Y >= walls->pos.y - TILE_SIZE_Y + 2
			&& ENEMY_POS_Y <= walls->pos.y)
		{
			game->right_wall_pos = walls->pos.x + TILE_SIZE_X + 2;
			return (1);
		}
		walls = walls->next;
	}
	return (0);
}

int	enemy_touching_floor(t_game *game, t_enemy *enemy)
{
	t_tile *walls;

	walls = game->walls;
	while (walls)
	{
		if (ENEMY_POS_Y + ENEMY_HEIGHT >= walls->pos.y - 5
			&& ENEMY_POS_Y + ENEMY_HEIGHT <= walls->pos.y + TILE_SIZE_Y * 0.5
			&& ((ENEMY_POS_X + ENEMY_WIDTH <= walls->pos.x + TILE_SIZE_X
			&& ENEMY_POS_X + ENEMY_WIDTH >= walls->pos.x)
			|| (ENEMY_POS_X >= walls->pos.x
			&& ENEMY_POS_X <= walls->pos.x + TILE_SIZE_X))
			&& !contiguous_ceiling(game, walls->pos))
		{
			game->ground_pos = walls->pos.y - TILE_SIZE_Y;
			return (1);
		}
		walls = walls->next;
	}
	return (0);
}

int	enemy_touching_ceiling(t_game *game, t_enemy *enemy)
{
	t_tile *walls;

	walls = game->walls;
	while (walls)
	{
		if (ENEMY_POS_Y >= walls->pos.y + TILE_SIZE_Y * 0.5
			&& ENEMY_POS_Y <= walls->pos.y + TILE_SIZE_Y
			&& ((ENEMY_POS_X + ENEMY_WIDTH <= walls->pos.x + TILE_SIZE_X
			&& ENEMY_POS_X + ENEMY_WIDTH >= walls->pos.x)
			|| (ENEMY_POS_X >= walls->pos.x
			&& ENEMY_POS_X <= walls->pos.x + TILE_SIZE_X))
			&& !contiguous_floor(game, walls->pos))
		{
			game->ceiling_pos = walls->pos.y + TILE_SIZE_Y;
			return (1);
		}
		walls = walls->next;
	}
	return (0);
}

int enemy_touching_exit(t_game *game, t_enemy *enemy)
{
	if ((ENEMY_POS_X >= game->portal.pos.x
		&& ENEMY_POS_X <= game->portal.pos.x + TILE_SIZE_X)
		&& (ENEMY_POS_Y >= game->portal.pos.y
		&& ENEMY_POS_Y <= game->portal.pos.y + TILE_SIZE_X))
		return (1);
	return (0);
}
