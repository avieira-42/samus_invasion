/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:19:00 by avieira-          #+#    #+#             */
/*   Updated: 2025/11/27 04:40:20 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "../engine/types.h"

int			game_loop(t_game *game);
int			renderer(t_game *game);
void		game_start(t_game *game);
void		calculate_delta(t_game *game);
int			update(t_game *game);
void		update_loop_variables(t_game *game);
void		is_play_area(t_game *game);
void		is_jumping(t_game *game);
void		is_falling(t_game *game);
void		clamp_falling_velocity(t_game *game);
void		move_player(t_game *game);
void		end_game(t_game *game);
void		update_camera(t_game *game);
void		load_image(t_game *game);
void		draw_background(t_game *game);
void		init_game(t_game *game);
void		init_window(t_game *game);
void		init_main_struct(t_game *game);
void		init_image(t_game *game);
void		init_background(t_game *game);
void		init_tile(t_game *game);
void		init_item(t_game *game);
void		init_exit(t_game *game);
void		init_enemy(t_game *game);
void		init_player(t_game *game);
void		init_finish_screens(t_game *game);
void		init_death_screen(t_game *game);
void		init_victory_screen(t_game *game);

#endif
