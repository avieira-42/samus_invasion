/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:00:15 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/16 22:21:55 by a-soeiro         ###   ########.fr       */
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

void	position_wall(t_cub *cub)
{
	t_tile	*wall;
	
	wall = new_wall(cub);
	add_wall(&cub->walls, wall);
}

void	draw_walls(t_cub *cub)
{
	t_tile	*walls;
	t_point	pos;

	walls = cub->walls;
	while (walls)
	{
		pos.y = walls->pos.y;
		pos.x = walls->pos.x - cub->camera.x;
		drawtexture(&cub->image, &cub->tile.sprite, pos, 1);
		walls = walls->next;
	}
}
