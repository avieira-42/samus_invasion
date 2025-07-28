/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 00:14:20 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/28 12:53:46 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	animate_enemy(t_game *game, t_enemy *enemy)
{
	if (ENEMY_TOUCHING_FLOOR)
		animate_enemy_walking(game, enemy);
	else
		animate_enemy_falling(game, enemy);
}

void    update_enemy_orientation(t_enemy *enemy)
{
	if ((ft_abs(enemy->tmp_pos.x - enemy->pos.x) >= 400
		|| ENEMY_TOUCHING_RIGHTWALL
		|| ENEMY_TOUCHING_LEFTWALL)
		&& ENEMY_TOUCHING_FLOOR)
	{
		enemy->tmp_pos.x = enemy->pos.x;
		enemy->orientation *= -1;
	}
}

void	update_enemy_pos(t_game *game, t_enemy *enemy)
{
	ENEMY_TOUCHING_LEFTWALL = enemy_touching_wall_left(game, enemy);
	ENEMY_TOUCHING_RIGHTWALL = enemy_touching_wall_right(game, enemy);
	ENEMY_TOUCHING_FLOOR = enemy_touching_floor(game, enemy);
	ENEMY_TOUCHING_EXIT = enemy_touching_exit(game, enemy);
	update_enemy_orientation(enemy);
	if (!ENEMY_TOUCHING_FLOOR)
		ENEMY_POS_Y += enemy->velocity.y * game->delta;
	else
	ENEMY_POS_X += enemy->velocity.x * enemy->orientation * game->delta;
}

void	animate_enemies(t_game *game)
{
	t_enemy *enemies;

	enemies = game->enemies;
	while (enemies)
	{
		update_enemy_pos(game, enemies);
		animate_enemy(game, enemies);
		enemies = enemies->next;
	}
}
