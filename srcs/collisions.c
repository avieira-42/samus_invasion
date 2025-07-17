/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:17:13 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/17 03:38:25 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_touching_wall_left(t_game *game)
{
	t_tile *walls;

	walls = game->walls;
	while (walls)
	{
		if (PLAYER_POS_X + PLAYER_WIDTH <= walls->pos.x + TILE_SIZE_X / 2
			&& PLAYER_POS_X + PLAYER_WIDTH >= walls->pos.x - 10
			&& PLAYER_POS_Y >= walls->pos.y - 40
			&& PLAYER_POS_Y <= walls->pos.y)
		{
			game->left_wall_pos = walls->pos.x - PLAYER_WIDTH - 7;
			return (1);
		}
		walls = walls->next;
	}
	return (0);
}

int	is_touching_wall_right(t_game *game)
{
	t_tile *walls;

	walls = game->walls;
	while (walls)
	{
		if (PLAYER_POS_X >= walls->pos.x + TILE_SIZE_X / 2
			&& PLAYER_POS_X <= walls->pos.x + TILE_SIZE_X + 10
			&& PLAYER_POS_Y >= walls->pos.y - 40
			&& PLAYER_POS_Y <= walls->pos.y)
		{
			game->right_wall_pos = walls->pos.x + TILE_SIZE_X + 7;
			return (1);
		}
		walls = walls->next;
	}
	return (0);
}

int	is_touching_floor(t_game *game)
{
	t_tile *walls;

	walls = game->walls;
	while (walls)
	{
		if (PLAYER_POS_Y + PLAYER_HEIGHT + 23 >= walls->pos.y
			&& PLAYER_POS_Y + PLAYER_HEIGHT / 2 <= walls->pos.y
			&& ((PLAYER_POS_X + PLAYER_WIDTH <= walls->pos.x + TILE_SIZE_X
			&& PLAYER_POS_X + PLAYER_WIDTH >= walls->pos.x)
			|| (PLAYER_POS_X >= walls->pos.x
			&& PLAYER_POS_X <= walls->pos.x + TILE_SIZE_X)))
		{
			game->ground_pos = walls->pos.y - 48;
			return (1);
		}
		walls = walls->next;
	}
	return (0);
}

int	is_touching_ceiling(t_game *game)
{
	t_tile *walls;

	walls = game->walls;
	while (walls)
	{
		if (PLAYER_POS_Y >= walls->pos.y + TILE_SIZE_Y * 0.7
			&& PLAYER_POS_Y <= walls->pos.y + TILE_SIZE_Y
			&& ((PLAYER_POS_X + PLAYER_WIDTH <= walls->pos.x + TILE_SIZE_X
			&& PLAYER_POS_X + PLAYER_WIDTH >= walls->pos.x)
			|| (PLAYER_POS_X >= walls->pos.x
			&& PLAYER_POS_X <= walls->pos.x + TILE_SIZE_X)))
			return (1);
		walls = walls->next;
	}
	return (0);
}

int	is_touching_exit(t_game *game)
{
	if ((PLAYER_POS_X >= game->portal.pos.x && PLAYER_POS_X <= game->portal.pos.x + 48)
		&& (PLAYER_POS_Y >= game->portal.pos.y && PLAYER_POS_Y <= game->portal.pos.y + 48))
		return (1);
	return (0);
}
