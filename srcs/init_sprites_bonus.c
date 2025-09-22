/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <marvavieira-@student.42porto.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:15:03 by avieira-          #+#    #+#             */
/*   Updated: 2025/08/04 21:39:21 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/samus_invasion.h"

void	init_tile_sprite(t_game *game)
{
	load_sprite(game->mlx_ptr, &game->tile.sprite, "textures/tile.xpm");
}

void	init_towel_sprite(t_game *game)
{
	load_sprite(game->mlx_ptr, &game->towel.sprite, "textures/towel.xpm");
}

void	init_portal_sprite(t_game *game)
{
	load_sprite(game->mlx_ptr, &game->portal.sprite,
		"textures/offportal.xpm");
	load_sprite(game->mlx_ptr, &game->portal.sprite2,
		"textures/portal.xpm");
}

void	zero_sprites(t_image *sprites, int count)
{
	int	i;

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
	samus_sprite_paths[0] = "textures/samus1.xpm";
	samus_sprite_paths[1] = "textures/samus2.xpm";
	samus_sprite_paths[2] = "textures/samus3.xpm";
	samus_sprite_paths[3] = "textures/samus4.xpm";
	samus_sprite_paths[4] = "textures/samus5.xpm";
	samus_sprite_paths[5] = "textures/samusfalling.xpm";
	while (i < 6)
	{
		load_sprite(game->mlx_ptr, &game->samus.sprite[i],
			samus_sprite_paths[i]);
		i++;
	}
}
