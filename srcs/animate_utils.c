/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:51:54 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/23 20:43:14 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	animate_player_jumping(t_game *game)
{
	int	i;

	game->player.falling.i = 0;
	game->player.falling.timer = 0;
	game->player.attack.i = 0;
	game->player.attack.timer = 0;
	if (++(game->player.jumping.timer) == 3)
	{
		game->player.jumping.timer = 0;
		if ((game->player.jumping.i) < 2)
			(game->player.jumping.i)++;
	}
	i = game->player.jumping.i;
	if (PLAYER_ORIENTATION == 1)
		drawtexture(&game->image, &game->player.jumping.sprite[i], game->player.camera, 1);
	else
		draw_mirroredtexture(&game->image, &game->player.jumping.sprite[i], game->player.camera, 1);
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
		if ((game->player.falling.i) < 2)
			(game->player.falling.i)++;
	}
	i = game->player.falling.i;
	if (PLAYER_ORIENTATION == 1)
		drawtexture(&game->image, &game->player.falling.sprite[i], game->player.camera, 1);
	else
		draw_mirroredtexture(&game->image, &game->player.falling.sprite[i], game->player.camera, 1);
}

void	animate_player_attacking(t_game *game)
{
	int	i;

	game->player.jumping.i = 0;
	game->player.jumping.timer = 0;
	game->player.falling.i = 0;
	game->player.falling.timer = 0;
	if (++(game->player.attack.timer) == 1)
	{
		game->player.attack.timer = 0;
		if ((game->player.attack.i) < 11)
			(game->player.attack.i)++;
	}
	i = game->player.attack.i;
	if (PLAYER_ORIENTATION == 1)
		drawtexture(&game->image, &game->player.attack.sprite[i], game->player.camera, 1);
	else
		draw_mirroredtexture(&game->image, &game->player.attack.sprite[i], game->player.camera, 1);
}
