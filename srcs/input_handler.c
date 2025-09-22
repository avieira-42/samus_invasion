/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:11:02 by lshonta           #+#    #+#             */
/*   Updated: 2025/09/15 10:48:33 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_game *game)
{
	if (game->map.text[game->p.y - 1][game->p.x] != '1')
	{
		if (game->map.text[game->p.y - 1][game->p.x] == 'C')
		{
			game->map.text[game->p.y][game->p.x] = '0';
			game->map.text[game->p.y - 1][game->p.x] = 'P';
			game->map.c_count--;
		}
		else if (game->map.text[game->p.y - 1][game->p.x] == '0')
		{
			game->map.text[game->p.y][game->p.x] = '0';
			game->map.text[game->p.y - 1][game->p.x] = 'P';
		}
		else if (game->map.text[game->p.y - 1][game->p.x] == 'E'
				&& game->map.c_count == 0)
			game->finish = 1;
		if (game->map.text[game->p.y - 1][game->p.x] != 'E'
				|| (game->map.text[game->p.y - 1][game->p.x] == 'E'
					&& game->map.c_count == 0))
			update_info(game);
	}
}

void	move_down(t_game *game)
{
	if (game->map.text[game->p.y + 1][game->p.x] != '1'
			|| (game->map.text[game->p.y + 1][game->p.x] == 'E'
				&& game->map.c_count == 0))
	{
		if (game->map.text[game->p.y + 1][game->p.x] == 'C')
		{
			game->map.text[game->p.y][game->p.x] = '0';
			game->map.text[game->p.y + 1][game->p.x] = 'P';
			game->map.c_count--;
		}
		else if (game->map.text[game->p.y + 1][game->p.x] == '0')
		{
			game->map.text[game->p.y][game->p.x] = '0';
			game->map.text[game->p.y + 1][game->p.x] = 'P';
		}
		else if (game->map.text[game->p.y + 1][game->p.x] == 'E'
				&& game->map.c_count == 0)
			game->finish = 1;
		if (game->map.text[game->p.y + 1][game->p.x] != 'E'
				|| (game->map.text[game->p.y + 1][game->p.x] == 'E'
					&& game->map.c_count == 0))
			update_info(game);
	}
}

void	move_left(t_game *game)
{
	if (game->map.text[game->p.y][game->p.x - 1] != '1'
			|| (game->map.text[game->p.y][game->p.x - 1] == 'E'
				&& game->map.c_count == 0))
	{
		if (game->map.text[game->p.y][game->p.x - 1] == 'C')
		{
			game->map.text[game->p.y][game->p.x] = '0';
			game->map.text[game->p.y][game->p.x - 1] = 'P';
			game->map.c_count--;
		}
		else if (game->map.text[game->p.y][game->p.x - 1] == '0')
		{
			game->map.text[game->p.y][game->p.x] = '0';
			game->map.text[game->p.y][game->p.x - 1] = 'P';
		}
		else if (game->map.text[game->p.y][game->p.x - 1] == 'E'
				&& game->map.c_count == 0)
			game->finish = 1;
		if (game->map.text[game->p.y][game->p.x - 1] != 'E'
				|| (game->map.text[game->p.y][game->p.x - 1] == 'E'
					&& game->map.c_count == 0))
			update_info(game);
	}
}

void	move_right(t_game *game)
{
	if (game->map.text[game->p.y][game->p.x + 1] != '1'
			|| (game->map.text[game->p.y][game->p.x + 1] == 'E'
				&& game->map.c_count == 0))
	{
		if (game->map.text[game->p.y][game->p.x + 1] == 'C')
		{
			game->map.text[game->p.y][game->p.x] = '0';
			game->map.text[game->p.y][game->p.x + 1] = 'P';
			game->map.c_count--;
		}
		else if (game->map.text[game->p.y][game->p.x + 1] == '0')
		{
			game->map.text[game->p.y][game->p.x] = '0';
			game->map.text[game->p.y][game->p.x + 1] = 'P';
		}
		else if (game->map.text[game->p.y][game->p.x + 1] == 'E'
				&& game->map.c_count == 0)
			game->finish = 1;
		if (game->map.text[game->p.y][game->p.x + 1] != 'E'
				|| (game->map.text[game->p.y][game->p.x + 1] == 'E'
					&& game->map.c_count == 0))
			update_info(game);
	}
}

int	key_pressed(int keycode, t_game *game)
{
	if (keycode == ESC)
		free_displays(game);
	else if (keycode == W)
		move_up(game);
	else if (keycode == A)
		move_left(game);
	else if (keycode == S)
		move_down(game);
	else if (keycode == D)
		move_right(game);
	return (0);
}
