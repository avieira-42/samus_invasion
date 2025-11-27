/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 03:16:48 by avieira-          #+#    #+#             */
/*   Updated: 2025/11/27 04:42:44 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include "types.h"

void		load_sprite(void *mlx_ptr, t_image *sprite, char *filepath);
void		init_tile_sprite(t_game *game);
void		init_towel_sprite(t_game *game);
void		init_portal_sprite(t_game *game);
void		init_samus_sprites(t_game *game);
void		zero_sprites(t_image *sprites, int count);
void		init_breno_sprites(t_game *game);
void		init_breno_idle_sprites(t_game *game);
void		init_breno_jumping_sprites(t_game *game);
void		init_breno_attack_sprites(t_game *game);
void		init_breno_running_sprites(t_game *game);
void		init_breno_falling_sprites(t_game *game);
void		init_player_moves_sprites(t_game *game);
void		init_bckgrnd_sprite(t_game *game);
void		position_portal(t_game *game);
void		draw_portal(t_game *game);
void		position_wall(t_game *game);
void		draw_walls(t_game *game);
void		add_wall(t_tile **walls, t_tile *new_wall);
t_tile		*new_wall(t_game *game);
void		position_sprites(t_game *game, int x, int y);
void		drawobj(t_image *image, t_point pos, t_point size, int color);
int			ft_get_color(t_image *data, int x, int y);
void		ft_pixelput(t_image *data, int x, int y, int color);
void		drawline(t_game *game, t_point start, t_point dest);
void		drawtexture(t_image *image, t_image *texture, t_point pos,
				long double scale);
void		draw_mirroredtexture(t_image *image, t_image *texture, t_point pos,
				long double scale);
void		position_item(t_game *game);
void		draw_items(t_game *game);
void		update_item_orientation(t_game *game);
int			items_count(t_item *items);
void		add_item(t_item **items, t_item *new_item);
void		draw_map(t_game *game);
t_item		*new_item(t_game *game);
void		position_enemy(t_game *game);
void		update_enemy_orientation(t_enemy *enemy);
void		update_enemy_pos(t_game *game, t_enemy *enemy);
void		animate_enemy(t_game *game, t_enemy *enemy);
void		animate_enemy_falling(t_game *game, t_enemy *enemy);
void		animate_enemy_walking(t_game *game, t_enemy *enemy);
void		animate_enemies(t_game *game);
int			enemies(t_enemy *enemies);
void		add_enemy(t_enemy **enemies, t_enemy *new_enemy);
t_enemy		*new_enemy(t_game *game);
bool		is_enemy_hit(t_game *game, t_enemy *enemy);
void		display_moves(t_game *game);
void		put_moves(t_game *game);
void		draw_moves(t_game *game, int moves, t_point move_pos);
void		animate_player_running(t_game *game);
void		animate_player_idle(t_game *game);
void		animate_player(t_game *game);
void		animate(t_game *game);
void		animate_player_jumping(t_game *game);
void		animate_player_falling(t_game *game);
void		animate_player_attacking(t_game *game);
void		update_attack_timer(t_game *game);

#endif
