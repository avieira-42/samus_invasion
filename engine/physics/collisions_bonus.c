/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:17:13 by avieira-          #+#    #+#             */
/*   Updated: 2025/11/27 04:18:43 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../types.h"
#include "../macros.h"
#include "../physics.h"

int	player_touching_wall_left(t_game *game)
{
	t_tile	*walls;

	walls = game->walls;
	while (walls)
	{
		if (game->player.pos.x + PLAYER_WIDTH <= walls->pos.x
			+ TILE_SIZE_X * 0.4
			&& game->player.pos.x + PLAYER_WIDTH >= walls->pos.x - 10
			&& ((game->player.pos.y >= walls->pos.y + 2
					&& game->player.pos.y <= walls->pos.y + TILE_SIZE_Y - 2)
				|| (game->player.pos.y + PLAYER_HEIGHT <= walls->pos.y
					+ TILE_SIZE_Y + 2
					&& game->player.pos.y + PLAYER_HEIGHT >= walls->pos.y + 2)))
		{
			game->left_wall_pos = walls->pos.x - PLAYER_WIDTH - 2;
			return (1);
		}
		walls = walls->next;
	}
	return (0);
}

int	player_touching_wall_right(t_game *game)
{
	t_tile	*walls;

	walls = game->walls;
	while (walls)
	{
		if (game->player.pos.x >= walls->pos.x + TILE_SIZE_X * 0.4
			&& game->player.pos.x <= walls->pos.x + TILE_SIZE_X + 10
			&& ((game->player.pos.y >= walls->pos.y + 2
					&& game->player.pos.y <= walls->pos.y + TILE_SIZE_Y - 2)
				|| (game->player.pos.y + PLAYER_HEIGHT <= walls->pos.y
					+ TILE_SIZE_Y + 2
					&& game->player.pos.y + PLAYER_HEIGHT >= walls->pos.y + 2)))
		{
			game->right_wall_pos = walls->pos.x + TILE_SIZE_X + 2;
			return (1);
		}
		walls = walls->next;
	}
	return (0);
}

int	player_touching_floor(t_game *game)
{
	t_tile	*walls;

	walls = game->walls;
	while (walls)
	{
		if (game->player.pos.y + PLAYER_HEIGHT >= walls->pos.y - 5
			&& game->player.pos.y + PLAYER_HEIGHT <= walls->pos.y
			+ TILE_SIZE_Y * 0.5
			&& ((game->player.pos.x + PLAYER_WIDTH * 0.8 <= walls->pos.x
					+ TILE_SIZE_X
					&& game->player.pos.x + PLAYER_WIDTH * 0.8 >= walls->pos.x)
				|| (game->player.pos.x + 20 >= walls->pos.x
					&& game->player.pos.x + 20 <= walls->pos.x + TILE_SIZE_X))
			&& !contiguous_ceiling(game, walls->pos))
		{
			game->ground_pos = walls->pos.y - TILE_SIZE_Y;
			return (1);
		}
		walls = walls->next;
	}
	return (0);
}

int	player_touching_ceiling(t_game *game)
{
	t_tile	*walls;

	walls = game->walls;
	while (walls)
	{
		if (game->player.pos.y >= walls->pos.y + TILE_SIZE_Y * 0.7
			&& game->player.pos.y <= walls->pos.y + TILE_SIZE_Y - 2
			&& ((game->player.pos.x + PLAYER_WIDTH * 0.8 <= walls->pos.x
					+ TILE_SIZE_X
					&& game->player.pos.x + PLAYER_WIDTH * 0.8 >= walls->pos.x)
				|| (game->player.pos.x + 20 >= walls->pos.x
					&& game->player.pos.x + 20 <= walls->pos.x + TILE_SIZE_X))
			&& !contiguous_floor(game, walls->pos))
		{
			game->ceiling_pos = walls->pos.y + TILE_SIZE_Y;
			return (1);
		}
		walls = walls->next;
	}
	return (0);
}

int	player_touching_exit(t_game *game)
{
	if ((game->player.pos.x >= game->portal.pos.x
			&& game->player.pos.x <= game->portal.pos.x + TILE_SIZE_X)
		&& (game->player.pos.y >= game->portal.pos.y
			&& game->player.pos.y <= game->portal.pos.y + TILE_SIZE_X))
		return (1);
	return (0);
}
