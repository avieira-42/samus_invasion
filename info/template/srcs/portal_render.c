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

#include "../includes/cub.h"

void	position_portal(t_cub *cub)
{
	cub->portal.pos.x = cub->portal.tmp_pos.x;
	cub->portal.pos.y = cub->portal.tmp_pos.y;
}

void	draw_portal(t_cub *cub)
{
	if (cub->items)
		drawtexture(&cub->image, &cub->portal.sprite, cub->portal.pos, 1);
	else
		drawtexture(&cub->image, &cub->portal.sprite2, cub->portal.pos, 1);
}
