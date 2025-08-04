/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <marvavieira-@student.42porto.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:15:03 by avieira-          #+#    #+#             */
/*   Updated: 2025/08/04 13:22:44 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/so_long.h"

void	load_sprite(void *mlx_ptr, t_image *sprite, char *filepath)
{
	sprite->image = mlx_xpm_file_to_image(mlx_ptr, filepath, &sprite->x,
			&sprite->y);
	if (!sprite->image)
	{
		sprite->addr = NULL;
		return;
	}
	sprite->addr = mlx_get_data_addr(sprite->image,
			&sprite->bits_per_pixel, &sprite->line_length, &sprite->endian);
}

void	init_tile_sprite(t_game *game)
{
	load_sprite(game->mlx_ptr, &game->tile.sprite, "b_textures/tile.xpm");
}

void	init_towel_sprite(t_game *game)
{
	load_sprite(game->mlx_ptr, &game->towel.sprite, "b_textures/towel.xpm");
}

void	init_portal_sprite(t_game *game)
{
	load_sprite(game->mlx_ptr, &game->portal.sprite,
		"b_textures/offportal.xpm");
	load_sprite(game->mlx_ptr, &game->portal.sprite2,
		"b_textures/portal.xpm");
}

void zero_sprites(t_image *sprites, int count)
{
    int i;

    i = 0;
    while (i < count)
    {
        ft_bzero(&sprites[i], sizeof(t_image));
        i++;
    }
}

void	init_samus_sprites(t_game *game)
{
	int		i;
	char	*samus_sprite_paths[6];

	i = 0;
	samus_sprite_paths[0] = "b_textures/samus1.xpm";
	samus_sprite_paths[1] = "b_textures/samus2.xpm";
	samus_sprite_paths[2] = "b_textures/samus3.xpm";
	samus_sprite_paths[3] = "b_textures/samus4.xpm";
	samus_sprite_paths[4] = "b_textures/samus5.xpm";
	samus_sprite_paths[5] = "b_textures/samusfalling.xpm";
	while (i < 6)
	{
		load_sprite(game->mlx_ptr, &game->samus.sprite[i],
			samus_sprite_paths[i]);
		i++;
	}
}
