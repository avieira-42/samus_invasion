/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:13:29 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/18 12:34:30 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

void display_moves(t_game *game)
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
}
