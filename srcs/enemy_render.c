/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:00:15 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/25 03:13:27 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	position_enemy(t_game *game)
{
	t_enemy	*enemy;
	
	enemy = new_enemy(game);
	add_enemy(&game->enemies, enemy);
}

void	update_enemy_orientation(t_game *game)
{
	t_enemy	*enemies;
	t_point	pos;

	enemies = game->enemies;
	while (enemies)
	{
		if (ft_abs(enemies.tmp_pos.y - enemies.pos.y) > 400
			|| enemies.touching )
		{
			enemies.tmp_pos.y = enemies.pos.y;
			enemies.orientation *= -1;
		}
		enemies.pos.y += enemies.orientation;
		enemies = enemies->next;
	}
}

void	draw_enemies(t_game *game)
{
	t_enemy	*enemies;
	t_point	pos;

	enemies = game->enemies;
	update_enemy_orentation(game);
	while (enemies)
	{
		enemies->pos.y += game->enemy.orientation;
		pos.y = enemies->pos.y;
		pos.x = enemies->pos.x - game->camera.x;
		drawtexture(&game->image, &game->enemy.sprite, pos, 1.6);
		enemies = enemies->next;
	}
}
