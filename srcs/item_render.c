/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:00:15 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/15 02:33:37 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	position_item(t_game *game)
{
	t_item	*item;
	
	item = new_item(game);
	add_item(&game->items, item);
}

void	draw_items(t_game *game)
{
	t_item	*items;
	t_point	pos;

	items = game->items;
	while (items)
	{
		pos.y = items->pos.y;
		pos.x = items->pos.x - game->camera.x;
		drawtexture(&game->image, &game->towel.sprite, pos, 1);
		items = items->next;
	}
}
