/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:00:15 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/16 02:18:26 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

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

int	is_touching_floor(t_cub *cub)
{
	t_tile *walls;

	walls = cub->walls;
	while (walls)
	{
		if (PLAYER_POS_Y >= walls->pos.y - 70
			&& PLAYER_POS_Y <= walls->pos.y - 48
			&& PLAYER_POS_X >= walls->pos.x - 47
			&& PLAYER_POS_X <= walls->pos.x + 47)
		{
			cub->ground_pos = walls->pos.y - 48;
			return (1);
		}
		walls = walls->next;
	}
	return (0);
}
