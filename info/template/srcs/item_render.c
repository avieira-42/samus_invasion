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

#include "../includes/cub.h"

void	position_item(t_cub *cub)
{
	t_item	*item;
	
	item = new_item(cub);
	add_item(&cub->items, item);
}

void	draw_items(t_cub *cub)
{
	t_item	*items;
	t_point	pos;

	items = cub->items;
	while (items)
	{
		pos.y = items->pos.y;
		pos.x = items->pos.x - cub->camera.x;
		drawtexture(&cub->image, &cub->towel.sprite, pos, 1);
		items = items->next;
	}
}
