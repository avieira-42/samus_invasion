/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_render_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:01:59 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/28 15:54:18 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_enemy  *new_enemy(t_game* game)
{
    t_enemy  *new_enemy;
new_enemy = (t_enemy *) malloc(sizeof(t_enemy));
	if (!new_enemy)
		return (NULL);
	new_enemy->i = 0;
	new_enemy->timer = 0;
	new_enemy->orientation = -1;
	new_enemy->touching_exit = false;
	new_enemy->touching_floor = false;
	new_enemy->touching_wallright = false;
	new_enemy->touching_wallleft = false;
	new_enemy->touching_ceiling = false;
	new_enemy->pos = game->samus.tmp_pos;
	new_enemy->tmp_pos = game->samus.tmp_pos;
	new_enemy->velocity.x = ENEMY_VELOCITY_X;
	new_enemy->velocity.y = ENEMY_VELOCITY_Y;
	new_enemy->next = NULL;
	return (new_enemy);
}

void	add_enemy(t_enemy **enemies, t_enemy *new_enemy)
{
	t_enemy	*enemies_iter;

	enemies_iter = (*enemies);
	if (*enemies == NULL)
	{
		*enemies = new_enemy;
		return ;
	}
	while (enemies_iter->next)
		enemies_iter = enemies_iter->next;
	enemies_iter->next = new_enemy;
}

int	enemies_count(t_enemy *enemies)
{
	int	count;

	count = 0;
	while (enemies)
	{
		enemies = enemies->next;
		count++;
	}
	return (count);
}

void	clear_enemy(t_game *game)
{
	t_enemy	*enemy;
	t_enemy	*prev;
	t_enemy	*to_free;

	enemy = game->enemies;
	prev = NULL;
	while (enemy)
	{
		if (((PLAYER_POS_X <= enemy->pos.x + ENEMY_WIDTH * 0.2
			&& PLAYER_POS_X >= enemy->pos.x)
			|| (PLAYER_POS_X + PLAYER_WIDTH * 0.4 <= enemy->pos.x + ENEMY_WIDTH * 0.4
			&& PLAYER_POS_X + PLAYER_WIDTH * 0.4 >= enemy->pos.x))
			&& ((PLAYER_POS_Y + PLAYER_HEIGHT * 0.4 <= enemy->pos.y + ENEMY_HEIGHT
			&& PLAYER_POS_Y + PLAYER_HEIGHT * 0.4 >= enemy->pos.y)
			|| (PLAYER_POS_Y <= enemy->pos.y + ENEMY_HEIGHT
			&& PLAYER_POS_Y >= enemy->pos.y + 10))
			&& ATTACKING)
		{
			to_free = enemy;
			if (prev == NULL)
				game->enemies = enemy->next;
			else
				prev->next = enemy->next;
			enemy = enemy->next;
			free(to_free);
			return ;
		}
		prev = enemy;
		enemy = enemy->next;
	}
}

void	free_enemies(t_enemy *enemies)
{
	t_enemy	*tmp;

	while (enemies)
	{
		tmp = enemies->next;
		free(enemies);
		enemies = tmp;
	}
}
