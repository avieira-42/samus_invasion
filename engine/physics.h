/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physics.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 03:16:56 by avieira-          #+#    #+#             */
/*   Updated: 2025/11/27 04:18:23 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHYSICS_H
# define PHYSICS_H

# include "types.h"

int			enemy_touching_floor(t_game *game, t_enemy *enemy);
int			enemy_touching_ceiling(t_game *game, t_enemy *enemy);
int			enemy_touching_wall_left(t_game *game, t_enemy *enemy);
int			enemy_touching_wall_right(t_game *game, t_enemy *enemy);
int			enemy_touching_exit(t_game *game, t_enemy *enemy);
int			player_touching_floor(t_game *game);
int			player_touching_ceiling(t_game *game);
int			player_touching_wall_left(t_game *game);
int			player_touching_wall_right(t_game *game);
int			player_touching_exit(t_game *game);
long long	get_time(void);
float		clamp(float value, float min, float max);
t_point		normalize(t_point point);
int			contiguous_ceiling(t_game *game, t_point floor_pos);
int			contiguous_floor(t_game *game, t_point ceiling_pos);

#endif
