/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:34:13 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/07/26 09:50:02 by a-soeiro         ###   ########.fr       */
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
# define SCREEN_WIDTH game->map.width
# define SCREE_HEIGHT game->map.height
# define SCREEN_END_X 2304
# define CAMERA_END_X 1104
# define GROUND_LEVEL 624
# define LINE_COLOR 0xFFFFFF
# define TILE_SIZE_X 80
# define TILE_SIZE_Y 80
# define GRAVITY_ACC 800
# define GRAVITY game->gravity
# define WALL_VELOCITY -100
# define MAX_FALL_SPEED 500
# define DELTA_T game->delta
# define JUMP_VEL game->player.jump.velocity
# define ATTACK_COUNTER game->player.attack_counter
# define ATTACK_TIMER game->player.attack_timer
# define ATTACKING game->player.attacking
# define MOVEMENTS game->player.move.count
// enemy
# define ENEMY_WIDTH 80
# define ENEMY_HEIGHT 80
# define ENEMY_VELOCITY_X 200
# define ENEMY_VELOCITY_Y 600
# define ENEMY_POS_X enemy->pos.x
# define ENEMY_POS_Y enemy->pos.y
# define ENEMY_TOUCHING_FLOOR enemies->touching_floor
# define ENEMY_TOUCHING_LEFTWALL enemies->touching_leftwall
# define ENEMY_TOUCHING_RIGHTWALL enemies->touching_rightwall
# define ENEMY_TOUCHING_CEILING enemies->touching_ceiling
# define ENEMY_TOUCHING_EXIT enemies->touching_exit
//player
# define VELOCITY_X	400
# define VELOCITY_Y -600
# define PLAYER_WIDTH 80
# define PLAYER_HEIGHT 80
# define PLAYER_POS game->player.pos
# define PLAYER_VECT game->player.vect
# define PLAYER_VEL_X game->player.velocity.x
# define PLAYER_VEL_Y game->player.velocity.y
# define PLAYER_POS game->player.pos
# define PLAYER_POS_X game->player.pos.x
# define PLAYER_POS_Y game->player.pos.y
# define PLAYER_TMP_POS_X game->player.tmp_pos.x
# define PLAYER_TMP_POS_Y game->player.tmp_pos.y
# define PLAYER_DIR_X game->player.direction.x
# define PLAYER_DIR_Y game->player.direction.y
# define PLAYER_ORIENTATION game->player.orientation
# define PLAYER_TOUCHING_FLOOR game->player.touching_ground
# define PLAYER_TOUCHING_LEFTWALL game->player.touching_leftwall
# define PLAYER_TOUCHING_RIGHTWALL game->player.touching_rightwall
# define PLAYER_TOUCHING_CEILING game->player.touching_ceiling
# define PLAYER_TOUCHING_EXIT game->player.touching_exit

typedef struct s_map
{
	char 	**text;
	int		height;
	int		width;
	int		C_count;
	int		P_count;
	int		E_count;
	int		X_count;
}	t_map;

typedef struct s_iterator
{
	int	y;
	int	x;
}	t_iterator;

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
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*image;
	char	*addr;
}	t_image;

typedef struct s_item
{
	int				orientation;
	t_point			tmp_pos;
	t_point			pos;
	t_image			sprite;
	struct s_item	*next;
}	t_item;

typedef struct s_bckgrnd
{
	t_point		pos;
	t_image		sprite;
	long double	scale;
}	t_bckgrnd;

typedef struct s_tile
{
	t_image			sprite;
	t_point			pos;
	t_vect			vect;
	struct s_tile	*next;
}	t_tile;

typedef struct s_portal
{
	t_image	sprite;
	t_image	sprite2;
	t_point	pos;
	t_point	tmp_pos;
}	t_portal;

typedef struct s_animation
{
	int				i;
	int				timer;
	t_image			sprite[14];
}	t_animation;

typedef struct s_move
{
	int		count;
	t_image sprite[10];
}	t_move;

typedef struct s_attack
{
	int			timer;
	int			counter;
	bool		is_attacking;
	t_animation attack;
}	t_attack;

typedef struct s_enemy
{
	bool			touching_exit;
	bool			touching_floor;
	bool			touching_wallright;
	bool			touching_wallleft;
	bool			touching_ceiling;
	int				orientation;
	t_point			tmp_pos;
	t_point			pos;
	t_animation		walking;
	struct s_enemy	*next;
}	t_enemy;

typedef struct s_player
{
	int				orientation;
	int				attack_timer;
	int				attack_counter;
	bool			attacking;
	bool			touching_ground;
	bool			touching_leftwall;
	bool			touching_rightwall;
	bool			touching_ceiling;
	bool			touching_exit;
	t_point 		pos;
	t_point			tmp_pos;
	t_point 		direction;
	t_point 		velocity;
	t_jump 			jump;
	t_vect			vect;
	t_animation		idle;
	t_animation		running;
	t_animation		jumping;
	t_animation		falling;
	t_animation		attack;
	t_point			camera;
	t_move			move;
}	t_player;

typedef struct s_game
{
	int			fd;
	int			gravity;
	bool		game_start;
	void		*mlx_ptr;
	void		*win_ptr;
	float		delta;
	float		ground_pos;
	float		ceiling_pos;
	float		right_wall_pos;
	float		left_wall_pos;
	long long	last_frame_time;
	t_map		map;
	t_image		image;
	t_bckgrnd	bckgrnd;
	t_tile		tile;
	t_tile		*walls;
	t_item		towel;
	t_item		*items;
	t_enemy		samus;
	t_enemy		*enemies;
	t_player	player;
	t_portal	portal;
	t_point		camera;
}	t_game;

// parse
int	parse(t_game *game, int argc, char **argv);


// displays
int			free_displays(t_game *game);
void		init_window(t_game *game);

//map parse
void	init_map(t_game *game, char *argv1);
int		is_allowed_char(t_game *game);
int		is_one_PE(t_game *game);
int		is_at_least_one_CPEX(t_game *game);
int		is_rectangular(t_game *game);
int		map_parse(t_game *game, char *argv1);

//map parse utils
void		get_map_height(t_game *game);
void		get_map_width(t_game *game);
int		is_only_1(char *map_line);
int		is_surrounded_by_1(t_game *game);

//gameloop
int		game_loop(t_game *game);
void	calculate_Delta(t_game *game);

//init
void	init_game(t_game *game);

//input
int	key_pressed(int keysym, t_game *game);
int	key_released(int keysym, t_game *game);

//map
int		ft_load_map(char *map, t_game *game);
char	**read_map(char *file_name);
void	draw_map(t_game *game);

//render utils
void		drawobj(t_image *image, t_point pos, t_point size, int color);
int			ft_get_color(t_image *data, int x, int y);
void		ft_pixelput(t_image *data, int x, int y, int color);
void		drawline(t_game *game, t_point start, t_point dest);
void		drawtexture(t_image *image, t_image *texture, t_point pos, long double scale);
void		draw_mirroredtexture(t_image *image, t_image *texture, t_point pos, long double scale);


//item render
void    position_item(t_game *game);
void    draw_items(t_game *game);
void	update_item_orientation(t_game *game);

//item render utils
int		items_count(t_item *items);
void	clear_item(t_game *game);
void	add_item(t_item **items, t_item *new_item);
void	free_items(t_item *items);
t_item	*new_item(t_game* game);

//enemy render
void    position_enemy(t_game *game);
void    draw_enemy(t_game *game, t_enemy *enemy);
void	update_enemy_orientation(t_game *game);

//enemy render utils
int		enemies(t_enemy *enemies);
void	clear_enemy(t_game *game);
void	add_enemy(t_enemy **enemies, t_enemy *new_enemy);
void	free_enemies(t_enemy *enemies);
t_enemy	*new_enemy(t_game* game);

//enemy collisions
int		enemy_touching_floor(t_game *game, t_enemy *enemy);
int		enemy_touching_ceiling(t_game *game, t_enemy *enemy);
int		enemy_touching_wall_left(t_game *game, t_enemy *enemy);
int		enemy_touching_wall_right(t_game *game, t_enemy *enemy);
int		enemy_touching_exit(t_game *game, t_enemy *enemy);

//wall render
void	position_wall(t_game *game);
void	draw_walls(t_game *game);
void	add_wall(t_tile **walls, t_tile *new_wall);
void	free_walls(t_tile *walls);
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

//display moves
void	display_moves(t_game *game);
void	put_moves(t_game *game);
void	draw_moves(t_game *game, int moves, t_point move_pos);

//collisions
int		player_touching_floor(t_game *game);
int		player_touching_ceiling(t_game *game);
int		player_touching_wall_left(t_game *game);
int		player_touching_wall_right(t_game *game);
int		player_touching_exit(t_game *game);

//collisions utils
int	contiguous_ceiling(t_game *game, t_point floor_pos);
int	contiguous_floor(t_game *game, t_point ceiling_pos);

//animate player
void	animate_player_running(t_game *game);
void	animate_player_idle(t_game *game);
void	animate_player(t_game *game);
void	animate(t_game *game);

//animate player utils
void	animate_player_jumping(t_game *game);
void	animate_player_falling(t_game *game);
void	animate_player_attacking(t_game *game);

// timers
void update_attack_timer(t_game *game);

//free utils
void	ft_free_arr(char **arr);

// free split
void	ft_freesplit(char **str);

// free sprites
void	free_sprites(t_game *game);
void	free_player_sprites(t_game *game);
void	free_player_idle(t_game *game);
void	free_player_running(t_game *game);

#endif
