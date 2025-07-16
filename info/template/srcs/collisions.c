/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:17:13 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/16 17:41:07 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	aabb_overlap(t_point apos, t_vect avect, t_point bpos, t_vect bvect)
{
	return (apos.x < bpos.x + bvect.width
			&& apos.x + avect.width > bpos.x
			&& apos.y < bpos.y + bvect.height 
			&& apos.y + avect.height > bpos.y);
}

int	is_touching_wall_left(t_cub *cub)
{
	t_tile *walls;

	walls = cub->walls;
	while (walls)
	{
		if (aabb_overlap(PLAYER_POS, PLAYER_VECT, walls->pos, walls->vect)
			&& PLAYER_POS_X <= walls->pos.x)
		{
			return (1);
		}
		walls = walls->next;
	}
	return (0);
}

int is_touching_wall_right(t_cub *cub)
{
	t_tile *walls;

	walls = cub->walls;
	while (walls)
	{
		if (aabb_overlap(PLAYER_POS, PLAYER_VECT, walls->pos, walls->vect)
				&& PLAYER_POS_X >= walls->pos.x + walls->vect.width)
		{
			return (1);
		}
		walls = walls->next;
	}
	return (0);
}

int	is_touching_floor(t_cub *cub)
{
	t_tile *walls;

	walls = cub->walls;
	while (walls)
	{
		if (aabb_overlap(PLAYER_POS, PLAYER_VECT, walls->pos, walls->vect)
			&& PLAYER_POS_Y <= walls->pos.y)
		{
			cub->ground_pos = walls->pos.y - 100;
			return (1);
		}
		walls = walls->next;
	}
	return (0);
}
