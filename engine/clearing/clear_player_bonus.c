/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_player_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 03:00:49 by avieira-          #+#    #+#             */
/*   Updated: 2025/11/27 03:58:50 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../types.h"
#include "../macros.h"
#include "../clearing.h"

void	clear_player(t_game *game)
{
	t_enemy	*enemy;

	enemy = game->enemies;
	while (enemy)
	{
		if (((game->player.pos.x <= enemy->pos.x + ENEMY_WIDTH * 0.2
					&& game->player.pos.x >= enemy->pos.x)
				|| (game->player.pos.x + PLAYER_WIDTH * 0.3 <= enemy->pos.x
					+ ENEMY_WIDTH * 0.3
					&& game->player.pos.x + PLAYER_WIDTH * 0.3 >= enemy->pos.x))
			&& ((game->player.pos.y + PLAYER_HEIGHT * 0.3 <= enemy->pos.y
					+ ENEMY_HEIGHT
					&& game->player.pos.y + PLAYER_HEIGHT * 0.3 >= enemy->pos.y)
				|| (game->player.pos.y <= enemy->pos.y + ENEMY_HEIGHT
					&& game->player.pos.y >= enemy->pos.y + 20))
			&& !game->player.attacking)
			open_death_screen(game);
		enemy = enemy->next;
	}
}
