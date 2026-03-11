/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_render_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:01:59 by avieira-          #+#    #+#             */
/*   Updated: 2026/03/11 03:24:38 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../types.h"
#include "../rendering.h"

t_item	*new_item(t_game *game)
{
	t_item	*new_item;

	new_item = (t_item *) malloc(sizeof(t_item));
	if (!new_item)
		return (NULL);
	new_item->next = NULL;
	new_item->pos = game->towel.pos;
	new_item->tmp_pos = game->towel.pos;
	new_item->sprite.x = 0;
	new_item->sprite.y = 0;
	new_item->sprite.bits_per_pixel = 0;
	new_item->sprite.line_length = 0;
	new_item->sprite.endian = 0;
	new_item->sprite.addr = NULL;
	new_item->sprite.image = NULL;
	return (new_item);
}

void	add_item(t_item **items, t_item *new_item)
{
	t_item	*items_iter;

	items_iter = (*items);
	if (*items == NULL)
	{
		*items = new_item;
		return ;
	}
	while (items_iter->next)
		items_iter = items_iter->next;
	items_iter->next = new_item;
}

int	items_count(t_item *items)
{
	int	count;

	count = 0;
	while (items)
	{
		items = items->next;
		count++;
	}
	return (count);
}

void	clear_item(t_game *game)
{
	t_item	*curr;
	t_item	*prev;
	t_item	*to_free;

	curr = game->items;
	prev = NULL;
	while (curr)
	{
		if ((game->player.pos.x <= curr->pos.x + 40
				&& game->player.pos.x >= curr->pos.x - 30)
			&& (game->player.pos.y <= curr->pos.y + 25
				&& game->player.pos.y >= curr->pos.y - 15))
		{
			to_free = curr;
			if (prev == NULL)
				game->items = curr->next;
			else
				prev->next = curr->next;
			curr = curr->next;
			return (free(to_free));
		}
		prev = curr;
		curr = curr->next;
	}
}

void	free_items(t_item *items)
{
	t_item	*tmp;

	while (items)
	{
		tmp = items->next;
		free(items);
		items = tmp;
	}
}
