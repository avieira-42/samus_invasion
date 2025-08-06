/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_utils2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:34:44 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/08/06 13:47:59 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/so_long_bonus.h"

void	init_victory_screen(t_game *game)
{
	load_sprite(game->mlx_ptr, &game->victory_screen,
		"b_textures/victory_screen.xpm");
}

void	init_death_screen(t_game *game)
{
	load_sprite(game->mlx_ptr, &game->death_screen,
		"b_textures/death_screen.xpm");
}

void	init_finish_screens(t_game *game)
{
	init_victory_screen(game);
	init_death_screen(game);
}
