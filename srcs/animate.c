/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 02:07:35 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/22 19:33:15 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	animate_player_running(t_game *game)
{
	int	i;

	game->player.idle.i = 0;
	game->player.idle.timer = 0;
	if (++(game->player.running.timer) == 2)
	{
		game->player.running.timer = 0;
		if ((game->player.running.i)++ == 13)
			game->player.running.i = 0;
	}
	i = game->player.running.i;
	drawtexture(&game->image, &game->player.running.sprite[i], game->player.camera, 1);
}

void	animate_player_idle(t_game *game)
{
	int	i;

	i = 0;
	game->player.running.i = 0;
	game->player.running.timer = 0;
	/*if (++(game->player.idle.timer) == 2)
		if ((game->player.idle.i)++ == 1)
			game->player.idle.i = 0;
	i = game->player.idle.i;*/
	drawtexture(&game->image, &game->player.idle.sprite[i], game->player.camera, 1);
}

void	animate_player(t_game *game)
{
	if (TOUCHING_FLOOR)
	{
		if (!PLAYER_DIR_X)
			animate_player_idle(game);
		else	
		animate_player_running(game);
	}
}

void	animate(t_game *game)
{
	animate_player(game);
}
