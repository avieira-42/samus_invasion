/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_render_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:01:59 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/15 13:29:04 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

t_item  *new_item(t_cub* cub)
{
    t_item  *new_item;

    new_item = (t_item *) malloc(sizeof(t_item));
    if (!new_item)
        return (NULL);
    new_item->next = NULL;
	new_item->sprite.addr = cub->towel.sprite.addr;
	new_item->sprite.image = cub->towel.sprite.image;
	new_item->pos = cub->towel.pos;
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

void	clear_item(t_cub *cub)
{
	t_item	*tmp;
	t_item	*items;

	items = cub->items;
	while (items)
	{
		if ((PLAYER_POS_X <= items->pos.x + 20 && PLAYER_POS_X >= items->pos.x - 15)
			&& (PLAYER_POS_Y <= items->pos.y + 20 && PLAYER_POS_Y >= items->pos.y - 15))
		{
			tmp = items;
			items = items->next;
			free(tmp);
		}
		else
			items = items->next;
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
