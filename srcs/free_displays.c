/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_displays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 03:06:51 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/09/08 17:10:07 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_sprites(t_game *game)
{
	if (game->towel.image)
		mlx_destroy_image(game->mlx_ptr, game->towel.image);
	if (game->bckgrnd.image)
		mlx_destroy_image(game->mlx_ptr, game->bckgrnd.image);
	if (game->tile.image)
		mlx_destroy_image(game->mlx_ptr, game->tile.image);
	if (game->portal.image)
		mlx_destroy_image(game->mlx_ptr, game->portal.image);
	if (game->player.image)
		mlx_destroy_image(game->mlx_ptr, game->player.image);
	if (game->empty_space.image)
		mlx_destroy_image(game->mlx_ptr, game->empty_space.image);
}

int	free_displays(t_game *game)
{
	if (game->mlx_ptr && game->win_ptr)
		mlx_loop_end(game->mlx_ptr);
	if (game->map.text)
		ft_free_matrix(game->map.text);
	if (game)
		free_sprites(game);
	if (game->mlx_ptr && game->win_ptr)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	ft_printf("Closing Application!");
	exit(1);
}
