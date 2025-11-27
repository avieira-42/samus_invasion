/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal_render_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:00:15 by avieira-          #+#    #+#             */
/*   Updated: 2025/11/27 04:37:40 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../types.h"
#include "../rendering.h"

void	position_portal(t_game *game)
{
	game->portal.pos.x = game->portal.tmp_pos.x;
	game->portal.pos.y = game->portal.tmp_pos.y;
}

void	draw_portal(t_game *game)
{
	t_point	pos;

	pos.x = game->portal.pos.x - game->camera.x;
	pos.y = game->portal.pos.y;
	if (game->items)
		drawtexture(&game->image, &game->portal.sprite, pos, 1.6);
	else
		drawtexture(&game->image, &game->portal.sprite2, pos, 1.6);
}
