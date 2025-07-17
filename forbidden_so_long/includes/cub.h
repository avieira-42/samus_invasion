/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:34:13 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/07/17 03:44:35 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef cub_H
# define cub_H
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
# define GRAVITY cub->gravity
# define VELOCITY_Y -900
# define WALL_VELOCITY -100
# define VELOCITY_X	400
# define MAX_SPEED 500
# define PLAYER_WIDTH 48
# define PLAYER_HEIGHT 48
# define PLAYER_POS cub->player.pos
# define PLAYER_VECT cub->player.vect
# define PLAYER_VEL_X cub->player.velocity.x
# define PLAYER_VEL_Y cub->player.velocity.y
# define JUMP_VEL cub->player.jump.velocity
# define PLAYER_POS cub->player.pos
# define PLAYER_POS_X cub->player.pos.x
# define PLAYER_POS_Y cub->player.pos.y
# define PLAYER_DIR_X cub->player.direction.x
# define PLAYER_DIR_Y cub->player.direction.y
# define TOUCHING_FLOOR cub->player.touching_ground
# define TOUCHING_LEFTWALL cub->player.touching_leftwall
# define TOUCHING_RIGHTWALL cub->player.touching_rightwall
# define TOUCHING_CEILING cub->player.touching_ceiling
# define TOUCHING_EXIT cub->player.touching_exit
# define DELTA_T cub->delta

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

typedef struct s_cub
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
}	t_cub;

int			free_displays(t_cub *cub);
void		init_window(t_cub *cub);

//gameloop
int		game_loop(t_cub *cub);
void	calculate_Delta(t_cub *cub);

//init
void	cub_init(t_cub *cub);

//input
int	key_pressed(int keysym, t_cub *cub);
int	key_released(int keysym, t_cub *cub);

//map
int		ft_load_map(char *map, t_cub *cub);
char	**read_map(void);
void	draw_map(t_cub *cub);

//render utils
void		drawobj(t_image *image, t_point pos, t_point size, int color);
void		ft_pixelput(t_image *data, int x, int y, int color);
void		drawline(t_cub *cub, t_point start, t_point dest);
void		drawtexture(t_image *image, t_image *texture, t_point pos, long double scale);

//item render
void    position_item(t_cub *cub);
void    draw_items(t_cub *cub);

//item render utils
int		items_count(t_item *items);
void	clear_item(t_cub *cub);
void	add_item(t_item **items, t_item *new_item);
void	free_item(t_item *items);
t_item	*new_item(t_cub* cub);

//wall render
void	position_wall(t_cub *cub);
void	draw_walls(t_cub *cub);
void	add_wall(t_tile **walls, t_tile *new_wall);
t_tile *new_wall(t_cub *cub);

//portal render
void	position_portal(t_cub *cub);
void	draw_portal(t_cub *cub);

//struct utils
int			check_args(char *str);

//math
int			ft_abs(int num);
long long	get_time(void);
float		 clamp(float value, float min, float max);
t_point		normalize(t_point point);

//collisions
int		is_touching_floor(t_cub *cub);
int		is_touching_ceiling(t_cub *cub);
int		is_touching_wall_left(t_cub *cub);
int		is_touching_wall_right(t_cub *cub);
int		is_touching_exit(t_cub *cub);

//free utils

void	ft_free_arr(char **arr);


#endif
