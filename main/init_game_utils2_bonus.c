/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_utils2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:34:44 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/11/27 04:48:04 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../engine/rendering.h"
#include "main.h"

void	init_victory_screen(t_game *game)
{
	load_sprite(game->mlx_ptr, &game->victory_screen,
		"textures/victory_screen.xpm");
}

void	init_death_screen(t_game *game)
{
	load_sprite(game->mlx_ptr, &game->death_screen,
		"textures/death_screen.xpm");
}

void	init_finish_screens(t_game *game)
{
	init_victory_screen(game);
	init_death_screen(game);
}
