/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 02:07:35 by avieira-          #+#    #+#             */
/*   Updated: 2025/07/29 23:59:25 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/so_long.h"

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
	if (game->player.direction.x == 1)
		drawtexture(&game->image, &game->player.running.sprite[i],
			game->player.camera, 1);
	else
		draw_mirroredtexture(&game->image, &game->player.running.sprite[i],
			game->player.camera, 1);
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
	if (game->player.orientation == 1)
		drawtexture(&game->image, &game->player.idle.sprite[i],
			game->player.camera, 1);
	else if (game->player.orientation == -1)
		draw_mirroredtexture(&game->image, &game->player.idle.sprite[i],
			game->player.camera, 1);
}

void	animate_player(t_game *game)
{
	if (game->player.touching_ground)
	{
		if (!game->player.direction.x)
			animate_player_idle(game);
		else
			animate_player_running(game);
	}
	else
	{
		if (game->player.velocity.y > 0)
		{
			if (game->player.attacking == TRUE)
				animate_player_attacking(game);
			else
				animate_player_falling(game);
		}
		else
			animate_player_jumping(game);
	}
}

void	animate(t_game *game)
{
	animate_enemies(game);
	animate_player(game);
}
