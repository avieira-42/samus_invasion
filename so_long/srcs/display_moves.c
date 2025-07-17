/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:13:29 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/17 18:05:28 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_moves(t_game *game)
{
	if (abs((int)PLAYER_POS_X - (int)PLAYER_TMP_POS_X) % PLAYER_WIDTH == 0)
		ft_printf("moves: %i\n", ++MOVEMENTS);
	if (abs((int)PLAYER_POS_Y - (int)PLAYER_TMP_POS_Y) % PLAYER_HEIGHT == 0)
		ft_printf("moves: %i\n", ++MOVEMENTS);
}
