/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:00:15 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/17 03:43:16 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	position_portal(t_game *game)
{
	game->portal.pos.x = game->portal.tmp_pos.x;
	game->portal.pos.y = game->portal.tmp_pos.y;
}

void	draw_portal(t_game *game)
{
	if (game->items)
		drawtexture(&game->image, &game->portal.sprite, game->portal.pos, 1);
	else
		drawtexture(&game->image, &game->portal.sprite2, game->portal.pos, 1);
}
