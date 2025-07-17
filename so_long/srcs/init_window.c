/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 18:26:08 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/05/21 17:13:10 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_window(t_game *game)
{
	(*game).mlx_ptr = mlx_init();
	(*game).win_ptr = mlx_new_window((*game).mlx_ptr, SCREEN_SIZE_X, SCREEN_SIZE_Y, "game3d");
}
