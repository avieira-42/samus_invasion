/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_utils3_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 02:26:28 by avieira-          #+#    #+#             */
/*   Updated: 2025/11/27 04:21:54 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../types.h"
#include "../rendering.h"

void	animate_enemy_walking(t_game *game, t_enemy *enemy)
{
	int		i;
	t_point	pos;

	pos.y = enemy->pos.y - game->camera.y;
	pos.x = enemy->pos.x - game->camera.x;
	if (++(enemy->timer) == 4)
	{
		enemy->timer = 0;
		if ((enemy->i)++ == 3)
			enemy->i = 0;
	}
	i = enemy->i;
	if (enemy->orientation == 1)
		drawtexture(&game->image, &game->samus.sprite[i], pos, 1.6);
	else
		draw_mirroredtexture(&game->image, &game->samus.sprite[i], pos, 1.6);
}

void	animate_enemy_falling(t_game *game, t_enemy *enemy)
{
	t_point	pos;

	pos.y = enemy->pos.y - game->camera.y;
	pos.x = enemy->pos.x - game->camera.x;
	if (enemy->orientation == -1)
		drawtexture(&game->image, &game->samus.sprite[5], pos, 1.6);
	else
		draw_mirroredtexture(&game->image, &game->samus.sprite[5], pos, 1.6);
}
