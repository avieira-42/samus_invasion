/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_render_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:01:59 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/15 15:00:31 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

t_tile  *new_wall(t_cub *cub)
{
    t_tile  *new_wall;

    new_wall = (t_tile *) malloc(sizeof(t_tile));
    if (!new_wall)
        return (NULL);
    new_wall->next = NULL;
	new_wall->sprite.addr = cub->tile.sprite.addr;
	new_wall->sprite.image = cub->tile.sprite.image;
	new_wall->pos = cub->tile.pos;
    return (new_wall);
}

void	add_wall(t_tile **walls, t_tile *new_wall)
{
	t_tile	*wall_iter;

	wall_iter = (*walls);
	if (*walls == NULL)
	{
		*walls = new_wall;
		return ;
	}
	while (wall_iter->next)
		wall_iter = wall_iter->next;
	wall_iter->next = new_wall;
}

int	is_touching_wall_left(t_cub *cub)
{
	t_tile *walls;

	walls = cub->walls;
	while (walls)
	{
		if (PLAYER_POS_X >= walls->pos.x - 48
			&& PLAYER_POS_X <= walls->pos.x
			&& PLAYER_POS_Y >= walls->pos.y - 30
			&& PLAYER_POS_Y <= walls->pos.y + 48)
			return (1);
		walls = walls->next;
	}
	return (0);
}

int	is_touching_wall_right(t_cub *cub)
{
	t_tile *walls;

	walls = cub->walls;
	while (walls)
	{
		if (PLAYER_POS_X <= walls->pos.x + 48
			&& PLAYER_POS_X >= walls->pos.x
			&& PLAYER_POS_Y >= walls->pos.y - 30
			&& PLAYER_POS_Y <= walls->pos.y + 48)
			return (1);
		walls = walls->next;
	}
	return (0);
}

void	free_walls(t_tile *walls)
{
	t_tile	*tmp;

	while (walls)
	{
		tmp = walls->next;
		free(walls);
		walls = tmp;
	}
}
