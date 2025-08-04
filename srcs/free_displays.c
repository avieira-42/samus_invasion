/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_displays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:41:42 by avieira-          #+#    #+#             */
/*   Updated: 2025/08/04 20:53:27 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_sprites(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->towel.image);
	mlx_destroy_image(game->mlx_ptr, game->bckgrnd.image);
	mlx_destroy_image(game->mlx_ptr, game->tile.image);
	mlx_destroy_image(game->mlx_ptr, game->portal.image);
	mlx_destroy_image(game->mlx_ptr, game->player.image);
}

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
	mlx_loop_end(game->mlx_ptr);
	ft_free_matrix(game->map.text);
	free_sprites(game);
	mlx_destroy_window(game->mlx_ptr, (*game).win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	ft_printf("Closing Application!");
	exit(1);
}
