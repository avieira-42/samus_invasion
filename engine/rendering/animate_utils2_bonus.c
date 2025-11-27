/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 00:14:20 by avieira-          #+#    #+#             */
/*   Updated: 2025/11/27 04:21:43 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../types.h"
#include "../math.h"
#include "../physics.h"
#include "../rendering.h"

void	animate_enemy(t_game *game, t_enemy *enemy)
{
	if (enemy->touching_floor)
		animate_enemy_walking(game, enemy);
	else
		animate_enemy_falling(game, enemy);
}

void	update_enemy_orientation(t_enemy *enemy)
{
	if ((ft_abs(enemy->tmp_pos.x - enemy->pos.x) >= 400
			|| enemy->touching_wallright
			|| enemy->touching_wallleft)
		&& enemy->touching_floor)
	{
		enemy->tmp_pos.x = enemy->pos.x;
		enemy->orientation *= -1;
	}
}

void	update_enemy_pos(t_game *game, t_enemy *enemy)
{
	enemy->touching_wallleft = enemy_touching_wall_left(game, enemy);
	enemy->touching_wallright = enemy_touching_wall_right(game, enemy);
	enemy->touching_floor = enemy_touching_floor(game, enemy);
	enemy->touching_exit = enemy_touching_exit(game, enemy);
	update_enemy_orientation(enemy);
	if (!enemy->touching_floor)
		enemy->pos.y += enemy->velocity.y * game->delta;
	else
		enemy->pos.x += enemy->velocity.x * enemy->orientation * game->delta;
}

void	animate_enemies(t_game *game)
{
	t_enemy	*enemies;

	enemies = game->enemies;
	while (enemies)
	{
		update_enemy_pos(game, enemies);
		animate_enemy(game, enemies);
		enemies = enemies->next;
	}
}
