/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 22:24:31 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/29 01:21:53 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	game_loop(t_game *game)
{
	if (game->finish == 1)
		free_displays(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->bckgrnd.image, 0, 0);
	draw_map(game);
	return (0);
}	
