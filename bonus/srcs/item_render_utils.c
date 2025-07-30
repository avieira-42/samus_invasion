/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_render_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:01:59 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/30 01:15:33 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_item	*new_item(t_game *game)
{
	t_item	*new_item;

	new_item = (t_item *) malloc(sizeof(t_item));
	if (!new_item)
		return (NULL);
	new_item->next = NULL;
	new_item->sprite.addr = game->towel.sprite.addr;
	new_item->sprite.image = game->towel.sprite.image;
	new_item->pos = game->towel.pos;
	new_item->tmp_pos = game->towel.pos;
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
		if ((game->player.pos.x <= curr->pos.x + 20
				&& game->player.pos.x >= curr->pos.x - 15)
			&& (game->player.pos.y <= curr->pos.y + 20
				&& game->player.pos.y >= curr->pos.y - 15))
		{
			to_free = curr;
			if (prev == NULL)
				game->items = curr->next;
			else
				prev->next = curr->next;
			curr = curr->next;
			free(to_free);
			return ;
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
