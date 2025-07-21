/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:39:19 by avieira-          #+#    #+#             */
/*   Updated: 2025/07/21 21:24:24 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_map(t_game *game, char *argv1)
{
	game->map.height = 0;
	game->map.width = 0;
	game->map.C_count = 0;
	game->map.P_count = 0;
	game->map.E_count = 0;
	game->map.X_count = 0;
	game->map.text = read_map(argv1);
	if (game->map.text == NULL)
		return ;
	read_map(argv1);
}
