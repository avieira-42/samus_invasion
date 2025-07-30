/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_render_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <marvavieira-@student.42porto.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 00:29:43 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/30 00:36:35 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	is_enemy_hit(t_game *game, t_enemy *enemy)
{
	bool	x_overlap;
	bool	y_overlap;

	x_overlap = (game->player.pos.x <= enemy->pos.x + ENEMY_WIDTH * 0.2
			&& game->player.pos.x >= enemy->pos.x)
		|| (game->player.pos.x + PLAYER_WIDTH * 0.4 <= enemy->pos.x
			+ ENEMY_WIDTH * 0.4
			&& game->player.pos.x + PLAYER_WIDTH * 0.4 >= enemy->pos.x);
	y_overlap = (game->player.pos.y + PLAYER_HEIGHT * 0.4 <= enemy->pos.y
			+ ENEMY_HEIGHT
			&& game->player.pos.y + PLAYER_HEIGHT * 0.4 >= enemy->pos.y)
		|| (game->player.pos.y <= enemy->pos.y + ENEMY_HEIGHT
			&& game->player.pos.y >= enemy->pos.y + 10);
	return (x_overlap && y_overlap && game->player.attacking);
}
