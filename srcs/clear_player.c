/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 03:00:49 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/28 03:16:52 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	clear_player(t_game *game)
{
	t_enemy	*curr;

	curr = game->enemies;
	while (curr)
	{
		if (PLAYER_POS_X <= curr->pos.x + ENEMY_WIDTH
			&& PLAYER_POS_X >= curr->pos.x
			&& PLAYER_POS_Y + PLAYER_HEIGHT <= curr->pos.y + ENEMY_HEIGHT
			&& PLAYER_POS_Y + PLAYER_HEIGHT >= curr->pos.y - 20
			&& ATTACKING)
			free_displays(game);
		curr = curr->next;
	}
}
