/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:13:29 by avieira-          #+#    #+#             */
/*   Updated: 2025/07/30 00:21:14 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../b_includes/so_long.h"

void	draw_moves(t_game *game, int moves, t_point move_pos)
{
	move_pos.x -= TILE_SIZE_X;
	if (moves > 9)
	{
		draw_moves(game, moves / 10, move_pos);
		moves = moves % 10;
	}
	drawtexture(&game->image, &game->player.move.sprite[moves], move_pos, 1);
}

void	display_moves(t_game *game)
{
	int		moved;
	t_point	move_pos;

	moved = 0;
	move_pos.x = TILE_SIZE_X * 16 ;
	move_pos.y = 0;
	if (ft_abs((int)(game->player.pos.x - game->player.tmp_pos.x))
			>= PLAYER_WIDTH)
	{
		game->player.tmp_pos.x = game->player.pos.x;
		moved = 1;
	}
	if (ft_abs((int)(game->player.pos.y - game->player.tmp_pos.y))
			>= PLAYER_HEIGHT)
	{
		game->player.tmp_pos.y = game->player.pos.y;
		moved = 1;
	}
	if (moved)
		game->player.move.count++;
	draw_moves(game, game->player.move.count, move_pos);
}
