/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites_utils2_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <marvavieira-@student.42porto.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:13:27 by avieira-          #+#    #+#             */
/*   Updated: 2025/08/08 02:34:17 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/so_long_bonus.h"

void	load_sprite(void *mlx_ptr, t_image *sprite, char *filepath)
{
	sprite->image = mlx_xpm_file_to_image(mlx_ptr, filepath, &sprite->x,
			&sprite->y);
	if (!sprite->image)
	{
		sprite->addr = NULL;
		return ;
	}
	sprite->addr = mlx_get_data_addr(sprite->image,
			&sprite->bits_per_pixel, &sprite->line_length, &sprite->endian);
}

void	init_breno_idle_sprites(t_game *game)
{
	int		i;
	char	*player_idle_sprite_paths[4];

	i = 0;
	game->player.idle.i = 0;
	game->player.idle.timer = 0;
	player_idle_sprite_paths[0] = "b_textures/brenoidle1.xpm";
	player_idle_sprite_paths[1] = "b_textures/brenoidle2.xpm";
	player_idle_sprite_paths[2] = "b_textures/brenoidle3.xpm";
	player_idle_sprite_paths[3] = "b_textures/brenoidle4.xpm";
	while (i < 4)
	{
		load_sprite(game->mlx_ptr, &game->player.idle.sprite[i],
			player_idle_sprite_paths[i]);
		i++;
	}
}

void	init_breno_falling_sprites(t_game *game)
{
	int		i;
	char	*player_falling_sprite_paths[4];

	i = 0;
	game->player.falling.i = 0;
	game->player.falling.timer = 0;
	player_falling_sprite_paths[0] = "b_textures/brenofalling1.xpm";
	player_falling_sprite_paths[1] = "b_textures/brenofalling2.xpm";
	player_falling_sprite_paths[2] = "b_textures/brenofalling3.xpm";
	player_falling_sprite_paths[3] = "b_textures/brenofalling4.xpm";
	while (i < 4)
	{
		load_sprite(game->mlx_ptr, &game->player.falling.sprite[i],
			player_falling_sprite_paths[i]);
		i++;
	}
}

void	init_bckgrnd_sprite(t_game *game)
{
	load_sprite(game->mlx_ptr, &game->bckgrnd.sprite,
		"b_textures/quasar.xpm");
}

void	init_player_moves_sprites(t_game *game)
{
	int		i;
	char	*player_moves_sprite_paths[10];

	i = 0;
	player_moves_sprite_paths[0] = "b_textures/0.xpm";
	player_moves_sprite_paths[1] = "b_textures/1.xpm";
	player_moves_sprite_paths[2] = "b_textures/2.xpm";
	player_moves_sprite_paths[3] = "b_textures/3.xpm";
	player_moves_sprite_paths[4] = "b_textures/4.xpm";
	player_moves_sprite_paths[5] = "b_textures/5.xpm";
	player_moves_sprite_paths[6] = "b_textures/6.xpm";
	player_moves_sprite_paths[7] = "b_textures/7.xpm";
	player_moves_sprite_paths[8] = "b_textures/8.xpm";
	player_moves_sprite_paths[9] = "b_textures/9.xpm";
	while (i < 10)
	{
		load_sprite(game->mlx_ptr, &game->player.move.sprite[i],
			player_moves_sprite_paths[i]);
		i++;
	}
}
