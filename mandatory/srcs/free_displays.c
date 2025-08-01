/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_displays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:41:42 by avieira-          #+#    #+#             */
/*   Updated: 2025/07/29 14:15:55 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_freesplit(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free(str);
}

int	free_displays(t_game *game)
{
	ft_free_matrix(game->map.text);
	mlx_loop_end((*game).mlx_ptr);
	mlx_destroy_window((*game).mlx_ptr, (*game).win_ptr);
	mlx_destroy_display((*game).mlx_ptr);
	free(game->mlx_ptr);
	ft_printf("Closing Application!");
	exit(1);
	return (0);
}
