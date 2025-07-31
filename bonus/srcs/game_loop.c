/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 21:50:14 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/31 17:17:58 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	update(t_game *game)
{
	update_loop_variables(game);
	is_play_area(game);
	is_jumping(game);
	is_falling(game);
	clamp_falling_velocity(game);
	move_player(game);
	clear_item(game);
	clear_enemy(game);
	clear_player(game);
	end_game(game);
	update_attack_timer(game);
	update_camera(game);
	return (1);
}

int	renderer(t_game *game)
{
	load_image(game);
	draw_background(game);
	draw_map(game);
	draw_items(game);
	draw_walls(game);
	draw_portal(game);
	animate(game);
	display_moves(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->image.image, 0, 0);
	mlx_destroy_image(game->mlx_ptr, game->image.image);
	return (1);
}

void	game_start(t_game *game)
{
	if (game->game_start == FALSE)
		game->game_start = TRUE;
}

int	game_loop(t_game *game)
{
	renderer(game);
	update(game);
	game_start(game);
	return (1);
}
