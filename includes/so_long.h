/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 03:07:10 by avieira-          #+#    #+#             */
/*   Updated: 2025/08/01 03:07:40 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libs/libft/include/libft.h"
# include "../libs/mlx/mlx.h"
# include "../libs/mlx/mlx_int.h"
# include <strings.h>
# include <limits.h>
# include <math.h>
# include <sys/time.h>

# define SPRITE_SIZE 50
# define ESC 65307
# define A 97
# define D 100
# define W 119
# define S 115

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_map
{
	char	**text;
	int		height;
	int		width;
	int		c_count;
	int		p_count;
	int		e_count;
}	t_map;

typedef struct s_iterator
{
	int	y;
	int	x;
}	t_iterator;

typedef struct s_image
{
	int		x;
	int		y;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*image;
	char	*addr;
}	t_image;

typedef struct s_game
{
	int			fd;
	int			finish;
	int			moves;
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_point		p;
	t_image		image;
	t_image		bckgrnd;
	t_image		tile;
	t_image		towel;
	t_image		portal;
	t_image		player;
}	t_game;

// parse
int		parse(t_game *game, int argc, char **argv);

// displays
int		free_displays(t_game *game);

// init game
void	init_game(t_game *game);
void	init_window(t_game *game);
void	init_player(t_game *game);
void	init_tile(t_game *game);
void	init_towel(t_game *game);
void	init_portal(t_game *game);
void	init_main_struct(t_game *game);
void	init_image(t_game *game);
void	init_background(t_game *game);

//map parse
void	init_map(t_game *game, char *argv1);
int		is_allowed_char(t_game *game);
int		is_one_pe(t_game *game);
int		is_at_least_one_cpe(t_game *game);
int		is_rectangular(t_game *game);
int		map_parse(t_game *game, char *argv1);

//map parse utils
void	get_map_height(t_game *game);
void	get_map_width(t_game *game);
int		is_only_1(char *map_line);
int		is_surrounded_by_1(t_game *game);

//map parse utils 2
int		is_valid_path(char **map, int width, int height);
char	**copy_map(char **map, int height);
void	set_path(char **map, int x, int y, t_point size);
t_point	set_player_pos(char **map, int width, int height);

//gameloop
int		game_loop(t_game *game);
void	calculate_Delta(t_game *game);

//map
char	**read_map(char *file_name);
void	draw_map(t_game *game);

//render utils
void	draw_player(t_game *game, int *y, int *x);
void	draw_portal(t_game *game, int *y, int *x);
void	draw_towel(t_game *game, int *y, int *x);
void	draw_tile(t_game *game, int *y, int *x);

//struct utils
int		check_args(char *str);

//free utils
void	ft_free_arr(char **arr);

// free split
void	ft_freesplit(char **str);

// free sprites
void	free_sprites(t_game *game);
void	free_player_sprites(t_game *game);
void	free_player_idle(t_game *game);
void	free_player_running(t_game *game);

// moving
int		key_pressed(int keycode, t_game *game);
#endif
