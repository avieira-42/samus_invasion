/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_render_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:00:15 by avieira-          #+#    #+#             */
/*   Updated: 2025/08/04 16:08:44 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/samus_invasion.h"

t_tile	*new_wall(t_game *game)
{
	t_tile	*new_wall;

	new_wall = (t_tile *) malloc(sizeof(t_tile));
	if (!new_wall)
		return (NULL);
	new_wall->next = NULL;
	new_wall->sprite.x = 0;
	new_wall->sprite.y = 0l;
	new_wall->sprite.bits_per_pixel = 0;
	new_wall->sprite.line_length = 0;
	new_wall->sprite.endian = 0;
	new_wall->sprite.addr = NULL;
	new_wall->sprite.image = NULL;
	new_wall->pos = game->tile.pos;
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

void	position_wall(t_game *game)
{
	t_tile	*wall;

	wall = new_wall(game);
	add_wall(&game->walls, wall);
}

void	draw_walls(t_game *game)
{
	t_tile	*walls;
	t_point	pos;

	walls = game->walls;
	while (walls)
	{
		pos.y = walls->pos.y;
		pos.x = walls->pos.x - game->camera.x;
		drawtexture(&game->image, &game->tile.sprite, pos, 1.6);
		walls = walls->next;
	}
}
