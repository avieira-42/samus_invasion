/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_render_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:01:59 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/25 03:16:41 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_enemy  *new_enemy(t_game* game)
{
    t_enemy  *new_enemy;

    new_enemy = (t_enemy *) malloc(sizeof(t_enemy));
    if (!new_enemy)
        return (NULL);
    new_enemy->next = NULL;
	new_enemy->sprite.addr = game->towel.sprite.addr;
	new_enemy->sprite.image = game->towel.sprite.image;
	new_enemy->pos = game->towel.pos;
	new_enemy->tmp_pos = game->towel.pos;
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
	t_enemy	*curr;
	t_enemy	*prev;
	t_enemy	*to_free;

	curr = game->enemies;
	prev = NULL;
	while (curr)
	{
		if ((PLAYER_POS_X <= curr->pos.x + 20 && PLAYER_POS_X >= curr->pos.x - 15)
			&& (PLAYER_POS_Y <= curr->pos.y + 20 && PLAYER_POS_Y >= curr->pos.y - 15))
		{
			to_free = curr;
			if (prev == NULL)
				game->enemies = curr->next;
			else
				prev->next = curr->next;
			curr = curr->next;
			free(to_free);
			return ;
		}
		prev = curr;
		curr = curr->next;
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
