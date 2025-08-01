/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <marvavieira-@student.42porto.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:15:03 by avieira-          #+#    #+#             */
/*   Updated: 2025/07/31 17:08:57 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_sprite(void *mlx_ptr, t_image *sprite, char *filepath)
{
	sprite->image = mlx_xpm_file_to_image(mlx_ptr, filepath, &sprite->x,
			&sprite->y);
	sprite->addr = mlx_get_data_addr(sprite->image,
			&sprite->bits_per_pixel, &sprite->line_length, &sprite->endian);
}

void	init_tile_sprite(t_game *game)
{
	load_sprite(game->mlx_ptr, &game->tile.sprite, "sprites/tile.xpm");
}

void	init_towel_sprite(t_game *game)
{
	load_sprite(game->mlx_ptr, &game->towel.sprite, "sprites/towel.xpm");
}

void	init_portal_sprite(t_game *game)
{
	load_sprite(game->mlx_ptr, &game->portal.sprite, "sprites/offportal.xpm");
	load_sprite(game->mlx_ptr, &game->portal.sprite2, "sprites/portal.xpm");
}

void	init_samus_sprites(t_game *game)
{
	int		i;
	char	*samus_sprite_paths[6];

	i = 0;
	samus_sprite_paths[0] = "sprites/samus1.xpm";
	samus_sprite_paths[1] = "sprites/samus2.xpm";
	samus_sprite_paths[2] = "sprites/samus3.xpm";
	samus_sprite_paths[3] = "sprites/samus4.xpm";
	samus_sprite_paths[4] = "sprites/samus5.xpm";
	samus_sprite_paths[5] = "sprites/samusfalling.xpm";
	while (i < 6)
	{
		load_sprite(game->mlx_ptr, &game->samus.sprite[i],
			samus_sprite_paths[i]);
		i++;
	}
}
