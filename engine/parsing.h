/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 03:16:54 by avieira-          #+#    #+#             */
/*   Updated: 2025/11/27 04:42:32 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include "types.h"

int			parse(t_game *game, int argc, char **argv);
int			error_message(char *message, int error_code);
int			ft_load_map(char *map, t_game *game);
char		**read_map(char *file_name);
int			check_args(char *str);
int			is_allowed_char(t_game *game);
int			init_map(t_game *game, char *argv1);
int			is_rectangular(t_game *game);
int			map_parse(t_game *game, char *argv1);
void		get_map_height(t_game *game);
void		get_map_width(t_game *game);
int			is_only_1(char *map_line);
int			is_surrounded_by_1(t_game *game);
int			is_valid_path(char **map, int width, int height);
char		**copy_map(char **map, int height);
void		set_path(char **map, int x, int y, t_point size);
t_point		set_player_pos(char **map, int width, int height);

#endif
