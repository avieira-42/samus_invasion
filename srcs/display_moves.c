/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:13:29 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/26 11:52:24 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

/*void put_moves(t_game *game)
{
    int moved = 0;

    if (ft_abs((int)(PLAYER_POS_X - PLAYER_TMP_POS_X)) >= PLAYER_WIDTH)
    {
        PLAYER_TMP_POS_X = PLAYER_POS_X;
        moved = 1;
    }
    if (ft_abs((int)(PLAYER_POS_Y - PLAYER_TMP_POS_Y)) >= PLAYER_HEIGHT)
    {
        PLAYER_TMP_POS_Y = PLAYER_POS_Y;
        moved = 1;
    }
    if (moved)
    {
		MOVEMENTS++;
        printf("Movements: %d\n", game->player.movements);
    }
}*/

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
    int			moved = 0;
	t_point		move_pos;

	move_pos.x = TILE_SIZE_X * 16 ;
	move_pos.y = 0;
    if (ft_abs((int)(PLAYER_POS_X - PLAYER_TMP_POS_X)) >= PLAYER_WIDTH)
    {
        PLAYER_TMP_POS_X = PLAYER_POS_X;
        moved = 1;
    }
    if (ft_abs((int)(PLAYER_POS_Y - PLAYER_TMP_POS_Y)) >= PLAYER_HEIGHT)
    {
        PLAYER_TMP_POS_Y = PLAYER_POS_Y;
        moved = 1;
    }
    if (moved)
		MOVEMENTS++;
	draw_moves(game, MOVEMENTS, move_pos);
}
