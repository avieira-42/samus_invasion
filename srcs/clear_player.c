/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 03:00:49 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/28 15:50:53 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	clear_player(t_game *game)
{
	t_enemy	*enemy;

	enemy = game->enemies;
	while (enemy)
	{
		if (((PLAYER_POS_X <= enemy->pos.x + ENEMY_WIDTH * 0.2
			&& PLAYER_POS_X >= enemy->pos.x)
			|| (PLAYER_POS_X + PLAYER_WIDTH * 0.3 <= enemy->pos.x + ENEMY_WIDTH * 0.3
			&& PLAYER_POS_X + PLAYER_WIDTH * 0.3 >= enemy->pos.x))
			&& ((PLAYER_POS_Y + PLAYER_HEIGHT * 0.3 <= enemy->pos.y + ENEMY_HEIGHT
			&& PLAYER_POS_Y + PLAYER_HEIGHT * 0.3 >= enemy->pos.y)
			|| (PLAYER_POS_Y <= enemy->pos.y + ENEMY_HEIGHT
			&& PLAYER_POS_Y >= enemy->pos.y + 20)))
		{
			printf("CLEAR_ENEMY\n");
			printf("player pos.x: %f \n", game->player.pos.x);
			printf("player pos.y: %f \n", game->player.pos.y);
			printf("enemy_pos.x: %f\n", game->enemies->pos.x);
			printf("enemy_pos.y: %f\n", game->enemies->pos.y);
			free_displays(game);
		}
		enemy = enemy->next;
	}
}
