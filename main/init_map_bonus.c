/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:39:19 by avieira-          #+#    #+#             */
/*   Updated: 2025/11/27 04:54:03 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../libs/libft/include/libft.h"
#include "../engine/types.h"
#include "../engine/parsing.h"

int	init_map(t_game *game, char *argv1)
{
	game->map.height = 0;
	game->map.width = 0;
	game->map.c_count = 0;
	game->map.p_count = 0;
	game->map.e_count = 0;
	game->map.x_count = 0;
	game->map.text = read_map(argv1);
	if (game->map.text == NULL)
		return (0);
	if (game->map.text[0] == NULL)
		return (ft_free_matrix(game->map.text),
			error_message("map must be a file not a directory\n", 0));
	return (1);
}
