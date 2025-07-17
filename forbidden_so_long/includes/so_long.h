/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:34:13 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/07/17 03:44:35 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef game_H
# define game_H
# include "../libs/libft/includes/libft.h"
# include "../libs/mlx/mlx.h"
# include "../libs/mlx/mlx_int.h"
# include <strings.h>
# include <limits.h>
# include <math.h>
# include <sys/time.h>
# include <stdbool.h>

# define SCREEN_SIZE_X 1296
# define SCREEN_SIZE_Y 720
# define SCREEN_END_X 2304
# define CAMERA_END_X 1104
# define GROUND_LEVEL 624
# define LINE_COLOR 0xFFFFFF
# define TILE_SIZE_X 48
# define TILE_SIZE_Y 48
# define GRAVITY_ACC 800
# define GRAVITY game->gravity
# define VELOCITY_Y -900
# define WALL_VELOCITY -100
# define VELOCITY_X	400
# define MAX_SPEED 500
# define PLAYER_WIDTH 48
# define PLAYER_HEIGHT 48
# define PLAYER_POS game->player.pos
# define PLAYER_VECT game->player.vect
# define PLAYER_VEL_X game->player.velocity.x
# define PLAYER_VEL_Y game->player.velocity.y
# define JUMP_VEL game->player.jump.velocity
# define PLAYER_POS game->player.pos
# define PLAYER_POS_X game->player.pos.x
# define PLAYER_POS_Y game->player.pos.y
# define PLAYER_DIR_X game->player.direction.x
# define PLAYER_DIR_Y game->player.direction.y
# define TOUCHING_FLOOR game->player.touching_ground
# define TOUCHING_LEFTWALL game->player.touching_leftwall
# define TOUCHING_RIGHTWALL game->player.touching_rightwall
# define TOUCHING_CEILING game->player.touching_ceiling
# define TOUCHING_EXIT game->player.touching_exit
# define DELTA_T game->delta

typedef struct s_point
{
	float	x;
	float	y;
}	t_point;

typedef struct s_vect
{
	float	height;
	float	width;
}	t_vect;

typedef struct s_jump
{
	bool	active;
	float	t_started;
	float	t_elapsed;
	float	velocity;
}	t_jump;

typedef struct s_image
{
	int		x;
	int		y;
	void	*image;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_item
{
	t_point			pos;
	t_image			sprite;
	struct s_item	*next;
}	t_item;

typedef struct s_enemy
{
	t_point	pos;
	t_image	sprite;
}	t_enemy;

typedef struct s_bckgrnd
{
	t_point		pos;
	t_image		sprite;
	long double	scale;
}	t_bckgrnd;

typedef struct s_player
{
	bool			touching_ground;
	bool			touching_leftwall;
	bool			touching_rightwall;
	bool			touching_ceiling;
	bool			touching_exit;
	t_point 		pos;
	t_point 		direction;
	t_point 		velocity;
	t_jump 			jump;
	t_image			sprite;
	t_point			camera;
	t_vect			vect;
}	t_player;

typedef struct s_tile
{
	t_image			sprite;
	t_point			pos;
	struct s_tile	*next;
	t_vect			vect;
}	t_tile;

typedef struct s_portal
{
	t_image	sprite;
	t_image	sprite2;
	t_point	tmp_pos;
	t_point	pos;
}	t_portal;

typedef struct s_game
{
	bool		game_start;
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	int			fd;
	int			map_height;
	int			map_width;
	int			gravity;
	float		delta;
	float		ground_pos;
	float		right_wall_pos;
	float		left_wall_pos;
	long long	last_frame_time;
	t_image		image;
	t_bckgrnd	bckgrnd;
	t_tile		tile;
	t_tile		*walls;
	t_item		towel;
	t_item		*items;
	t_point		camera;
	t_enemy		enemy;
	t_player	player;
	t_portal	portal;
}	t_game;

int			free_displays(t_game *game);
void		init_window(t_game *game);

//gameloop
int		game_loop(t_game *game);
void	calculate_Delta(t_game *game);

//init
void	game_init(t_game *game);

//input
int	key_pressed(int keysym, t_game *game);
int	key_released(int keysym, t_game *game);

//map
int		ft_load_map(char *map, t_game *game);
char	**read_map(void);
void	draw_map(t_game *game);

//render utils
void		drawobj(t_image *image, t_point pos, t_point size, int color);
void		ft_pixelput(t_image *data, int x, int y, int color);
void		drawline(t_game *game, t_point start, t_point dest);
void		drawtexture(t_image *image, t_image *texture, t_point pos, long double scale);

//item render
void    position_item(t_game *game);
void    draw_items(t_game *game);

//item render utils
int		items_count(t_item *items);
void	clear_item(t_game *game);
void	add_item(t_item **items, t_item *new_item);
void	free_item(t_item *items);
t_item	*new_item(t_game* game);

//wall render
void	position_wall(t_game *game);
void	draw_walls(t_game *game);
void	add_wall(t_tile **walls, t_tile *new_wall);
t_tile *new_wall(t_game *game);

//portal render
void	position_portal(t_game *game);
void	draw_portal(t_game *game);

//struct utils
int			check_args(char *str);

//math
int			ft_abs(int num);
long long	get_time(void);
float		 clamp(float value, float min, float max);
t_point		normalize(t_point point);

//collisions
int		is_touching_floor(t_game *game);
int		is_touching_ceiling(t_game *game);
int		is_touching_wall_left(t_game *game);
int		is_touching_wall_right(t_game *game);
int		is_touching_exit(t_game *game);

//free utils

void	ft_free_arr(char **arr);


#endif
