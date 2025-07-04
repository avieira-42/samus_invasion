/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:07:16 by avieira-          #+#    #+#             */
/*   Updated: 2025/07/04 20:10:51 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	open_window(t_game *game)
{
	game->mlx_ptr = mlx.init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, SO_LONG);
}
