/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 22:24:31 by avieira-          #+#    #+#             */
/*   Updated: 2025/08/05 19:11:25 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	game_loop(t_game *game)
{
	if (game->finish == 1)
		free_displays(game);
	mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr, game->bckgrnd.image, 0, 0);
	draw_map(game);
	return (0);
}
