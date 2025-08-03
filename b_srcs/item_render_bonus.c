/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:00:15 by avieira-          #+#    #+#             */
/*   Updated: 2025/07/30 01:13:28 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/so_long.h"

void	position_item(t_game *game)
{
	t_item	*item;

	item = new_item(game);
	add_item(&game->items, item);
}

void	update_item_orentation(t_game *game)
{
	if (ft_abs(game->towel.tmp_pos.y - game->towel.pos.y) > 18)
	{
		game->towel.tmp_pos.y = game->towel.pos.y;
		game->towel.orientation *= -1;
	}
	game->towel.pos.y += game->towel.orientation;
}

void	draw_items(t_game *game)
{
	t_item	*items;
	t_point	pos;

	items = game->items;
	update_item_orentation(game);
	while (items)
	{
		items->pos.y += game->towel.orientation;
		pos.y = items->pos.y;
		pos.x = items->pos.x - game->camera.x;
		drawtexture(&game->image, &game->towel.sprite, pos, 1.6);
		items = items->next;
	}
}
