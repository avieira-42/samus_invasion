/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearing.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 03:16:31 by avieira-          #+#    #+#             */
/*   Updated: 2025/11/27 04:41:28 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEARING_H
# define CLEARING_H

# include "types.h"

int			free_displays(t_game *game);
void		init_window(t_game *game);
void		open_death_screen(t_game *game);
void		open_victory_screen(t_game *game);
void		free_death_screen(t_game *game);
void		free_victory_screen(t_game *game);
void		ft_free_arr(char **arr);
void		ft_freesplit(char **str);
void		free_sprites(t_game *game);
void		free_player_sprites(t_game *game);
void		free_player_moves(t_game *game);
void		free_samus_sprites(t_game *game);
void		free_player_idle(t_game *game);
void		free_player_running(t_game *game);
void		free_player_jumping(t_game *game);
void		free_player_attack(t_game *game);
void		free_player_falling(t_game *game);
void		clear_enemy(t_game *game);
void		clear_player(t_game *game);
void		free_enemies(t_enemy *enemies);
void		free_walls(t_tile *walls);
void		clear_item(t_game *game);
void		free_items(t_item *items);

#endif
