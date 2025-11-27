/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:51:54 by avieira-          #+#    #+#             */
/*   Updated: 2025/11/27 04:39:02 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../types.h"
#include "../rendering.h"

void	animate_player_jumping(t_game *game)
{
	int	i;

	game->player.falling.i = 0;
	game->player.falling.timer = 0;
	game->player.attack.i = 0;
	game->player.attack.timer = 0;
	if (++(game->player.jumping.timer) == 2)
	{
		game->player.jumping.timer = 0;
		if ((game->player.jumping.i) < 3)
			(game->player.jumping.i)++;
	}
	i = game->player.jumping.i;
	if (game->player.orientation == 1)
	{
		drawtexture(&game->image, &game->player.jumping.sprite[i],
			game->player.camera, 1);
	}
	else
	{
		draw_mirroredtexture(&game->image, &game->player.jumping.sprite[i],
			game->player.camera, 1);
	}
}

void	animate_player_falling(t_game *game)
{
	int	i;

	game->player.jumping.i = 0;
	game->player.jumping.timer = 0;
	game->player.attack.i = 0;
	game->player.attack.timer = 0;
	if (++(game->player.falling.timer) == 2)
	{
		game->player.falling.timer = 0;
		if ((game->player.falling.i) < 3)
			(game->player.falling.i)++;
	}
	i = game->player.falling.i;
	if (game->player.orientation == 1)
	{
		drawtexture(&game->image, &game->player.falling.sprite[i],
			game->player.camera, 1);
	}
	else
	{
		draw_mirroredtexture(&game->image, &game->player.falling.sprite[i],
			game->player.camera, 1);
	}
}

void	animate_player_attacking(t_game *game)
{
	int	i;

	game->player.jumping.i = 0;
	game->player.jumping.timer = 0;
	game->player.falling.i = 0;
	game->player.falling.timer = 0;
	if (++(game->player.attack.timer) == 3)
	{
		game->player.attack.timer = 0;
		if ((game->player.attack.i) < 12)
			(game->player.attack.i)++;
	}
	i = game->player.attack.i;
	if (game->player.orientation == 1)
	{
		drawtexture(&game->image, &game->player.attack.sprite[i],
			game->player.camera, 1);
	}
	else
	{
		draw_mirroredtexture(&game->image, &game->player.attack.sprite[i],
			game->player.camera, 1);
	}
}
