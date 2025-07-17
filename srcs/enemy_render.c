/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:43:10 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/17 15:45:24 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	position_enemy(t_game *game)
{
	game->enemy.pos.x = game->enemy.tmp_pos.x;
	game->enemy.pos.y = game->enemy.tmp_pos.y;
}

void	draw_enemy(t_game *game)
{
	t_point	pos;

	pos.x = game->enemy.pos.x - game->camera.x;
	pos.y = game->enemy.pos.y;
	drawtexture(&game->image, &game->enemy.sprite, pos, 1);
}  
