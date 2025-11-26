/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   samus_invasion.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:19:00 by avieira-          #+#    #+#             */
/*   Updated: 2025/11/26 05:35:17 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMUS_INVASION_H
# define SAMUS_INVASION_H
# include "../libs/libft/include/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/minilibx-linux/mlx_int.h"
# include <strings.h>
# include <limits.h>
# include <math.h>
# include <sys/time.h>

# define SCREEN_SIZE_X 1296
# define SCREEN_SIZE_Y 720
# define SCREEN_END_X 2304
# define CAMERA_END_X 1104
# define SCREEN_END_Y 1500
# define CAMERA_END_Y 680
# define GROUND_LEVEL 624
# define LINE_COLOR 0xFFFFFF
# define TILE_SIZE_X 80
# define TILE_SIZE_Y 80
# define GRAVITY_ACC 800
# define WALL_VELOCITY -100
# define MAX_FALL_SPEED 500
// enemy
# define ENEMY_WIDTH 80
# define ENEMY_HEIGHT 80
# define ENEMY_VELOCITY_X 50
# define ENEMY_VELOCITY_Y 150
//player
# define VELOCITY_X	400
# define VELOCITY_Y -600
# define PLAYER_WIDTH 80
# define PLAYER_HEIGHT 80
//sprites
# define TILE "sprites/tile.xpm"
# define TOWEL "sprites/towel.xpm"
# define QUASAR "sprites/quasar.xpm"
# define PORTAL "sprites/portal.xpm"
# define OFFPORTAL "sprites/offportal.xpm"
# define SAMUS1 "sprites/samus1.xpm"
# define SAMUS2 "sprites/samus2.xpm"
# define SAMUS3 "sprites/samus3.xpm"
# define SAMUS4 "sprites/samus4.xpm"
# define SAMUS5 "sprites/samus5.xpm"

typedef struct s_map
{
	char	**text;
	int		height;
	int		width;
	int		c_count;
	int		p_count;
	int		e_count;
	int		x_count;
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

typedef struct s_jump
{
	int		max_count;
	int		count;
	t_bool	active;
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
	t_point			tmp_pos;
	t_image			sprite[14];
}	t_animation;

typedef struct s_move
{
	int		count;
	t_image	sprite[10];
}	t_move;

typedef struct s_attack
{
	int			timer;
	int			counter;
	t_bool		is_attacking;
	t_animation	attack;
}	t_attack;

typedef struct s_enemy
{
	int				i;
	int				timer;
	int				orientation;
	t_bool			touching_exit;
	t_bool			touching_floor;
	t_bool			touching_wallright;
	t_bool			touching_wallleft;
	t_bool			touching_ceiling;
	t_point			pos;
	t_point			tmp_pos;
	t_point			velocity;
	struct s_enemy	*next;
}	t_enemy;

typedef struct s_player
{
	int				orientation;
	int				attack_timer;
	int				attack_counter;
	t_bool			attacking;
	t_bool			touching_ground;
	t_bool			touching_leftwall;
	t_bool			touching_rightwall;
	t_bool			touching_ceiling;
	t_bool			touching_exit;
	t_point			pos;
	t_point			tmp_pos;
	t_point			direction;
	t_point			velocity;
	t_jump			jump;
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
	t_bool		game_start;
	t_bool		reset;
	t_bool		end;
	void		*mlx_ptr;
	void		*win_ptr;
	float		delta;
	float		ground_pos;
	float		ceiling_pos;
	float		right_wall_pos;
	float		left_wall_pos;
	long long	last_frame_time;
	t_map		map;
	t_image		death_screen;
	t_image		victory_screen;
	t_image		image;
	t_bckgrnd	bckgrnd;
	t_tile		tile;
	t_tile		*walls;
	t_item		towel;
	t_item		*items;
	t_animation	samus;
	t_enemy		*enemies;
	t_player	player;
	t_portal	portal;
	t_point		camera;
}	t_game;

// parse
int			parse(t_game *game, int argc, char **argv);
int			error_message(char *message, int error_code);

// displays
int			free_displays(t_game *game);
void		init_window(t_game *game);
void		open_death_screen(t_game *game);
void		open_victory_screen(t_game *game);
void		free_death_screen(t_game *game);
void		free_victory_screen(t_game *game);

//map parse
int			init_map(t_game *game, char *argv1);
int			is_allowed_char(t_game *game);
int			is_one_PE(t_game *game);
int			is_at_least_one_CPEX(t_game *game);
int			is_rectangular(t_game *game);
int			map_parse(t_game *game, char *argv1);

//map parse utils
void		get_map_height(t_game *game);
void		get_map_width(t_game *game);
int			is_only_1(char *map_line);
int			is_surrounded_by_1(t_game *game);

//map parse utils 2
int			is_valid_path(char **map, int width, int height);
char		**copy_map(char **map, int height);
void		set_path(char **map, int x, int y, t_point size);
t_point		set_player_pos(char **map, int width, int height);

//game loop
int			game_loop(t_game *game);
int			renderer(t_game *game);
void		game_start(t_game *game);
void		calculate_delta(t_game *game);
int			update(t_game *game);

//game loop utils
void		update_loop_variables(t_game *game);
void		is_play_area(t_game *game);
void		is_jumping(t_game *game);
void		is_falling(t_game *game);
void		clamp_falling_velocity(t_game *game);

//game loop utils 2
void		move_player(t_game *game);
void		end_game(t_game *game);
void		update_camera(t_game *game);
void		load_image(t_game *game);
void		draw_background(t_game *game);

//init game
void		init_game(t_game *game);
void		init_window(t_game *game);
void		init_main_struct(t_game *game);
void		init_image(t_game *game);
void		init_background(t_game *game);

//init game utils
void		init_tile(t_game *game);
void		init_item(t_game *game);
void		init_exit(t_game *game);
void		init_enemy(t_game *game);
void		init_player(t_game *game);

// init game utils
void		init_finish_screens(t_game *game);
void		init_death_screen(t_game *game);
void		init_victory_screen(t_game *game);

// init sprites
void		load_sprite(void *mlx_ptr, t_image *sprite, char *filepath);
void		init_tile_sprite(t_game *game);
void		init_towel_sprite(t_game *game);
void		init_portal_sprite(t_game *game);
void		init_samus_sprites(t_game *game);

void		zero_sprites(t_image *sprites, int count);

// init sprites utils
void		init_breno_sprites(t_game *game);
void		init_breno_idle_sprites(t_game *game);
void		init_breno_jumping_sprites(t_game *game);
void		init_breno_attack_sprites(t_game *game);
void		init_breno_running_sprites(t_game *game);

// init sprites utils 2
void		init_breno_falling_sprites(t_game *game);
void		init_player_moves_sprites(t_game *game);
void		init_bckgrnd_sprite(t_game *game);

// init sprites utils

//input
int			key_pressed(int keysym, t_game *game);
int			key_released(int keysym, t_game *game);

//map
int			ft_load_map(char *map, t_game *game);
char		**read_map(char *file_name);
void		draw_map(t_game *game);

// render
void		position_sprites(t_game *game, int x, int y);

//render utils
void		drawobj(t_image *image, t_point pos, t_point size, int color);
int			ft_get_color(t_image *data, int x, int y);
void		ft_pixelput(t_image *data, int x, int y, int color);
void		drawline(t_game *game, t_point start, t_point dest);
void		drawtexture(t_image *image, t_image *texture, t_point pos,
				long double scale);
void		draw_mirroredtexture(t_image *image, t_image *texture, t_point pos,
				long double scale);

//item render
void		position_item(t_game *game);
void		draw_items(t_game *game);
void		update_item_orientation(t_game *game);

//item render utils
int			items_count(t_item *items);
void		clear_item(t_game *game);
void		add_item(t_item **items, t_item *new_item);
void		free_items(t_item *items);
t_item		*new_item(t_game *game);

//animate utils 2
void		position_enemy(t_game *game);
void		update_enemy_orientation(t_enemy *enemy);
void		update_enemy_pos(t_game *game, t_enemy *enemy);
void		animate_enemy(t_game *game, t_enemy *enemy);
void		animate_enemy_falling(t_game *game, t_enemy *enemy);
void		animate_enemy_walking(t_game *game, t_enemy *enemy);
void		animate_enemies(t_game *game);

//enemy render utils
int			enemies(t_enemy *enemies);
void		clear_enemy(t_game *game);
void		add_enemy(t_enemy **enemies, t_enemy *new_enemy);
void		free_enemies(t_enemy *enemies);
t_enemy		*new_enemy(t_game *game);

//enemy render utils 2
t_bool		is_enemy_hit(t_game *game, t_enemy *enemy);

//enemy collisions
int			enemy_touching_floor(t_game *game, t_enemy *enemy);
int			enemy_touching_ceiling(t_game *game, t_enemy *enemy);
int			enemy_touching_wall_left(t_game *game, t_enemy *enemy);
int			enemy_touching_wall_right(t_game *game, t_enemy *enemy);
int			enemy_touching_exit(t_game *game, t_enemy *enemy);

//wall render
void		position_wall(t_game *game);
void		draw_walls(t_game *game);
void		add_wall(t_tile **walls, t_tile *new_wall);
void		free_walls(t_tile *walls);
t_tile		*new_wall(t_game *game);

//portal render
void		position_portal(t_game *game);
void		draw_portal(t_game *game);

//struct utils
int			check_args(char *str);

//math
int			ft_abs(int num);
long long	get_time(void);
float		clamp(float value, float min, float max);
t_point		normalize(t_point point);

//display moves
void		display_moves(t_game *game);
void		put_moves(t_game *game);
void		draw_moves(t_game *game, int moves, t_point move_pos);

//collisions
int			player_touching_floor(t_game *game);
int			player_touching_ceiling(t_game *game);
int			player_touching_wall_left(t_game *game);
int			player_touching_wall_right(t_game *game);
int			player_touching_exit(t_game *game);
void		clear_player(t_game *game);

//collisions utils
int			contiguous_ceiling(t_game *game, t_point floor_pos);
int			contiguous_floor(t_game *game, t_point ceiling_pos);

//animate player
void		animate_player_running(t_game *game);
void		animate_player_idle(t_game *game);
void		animate_player(t_game *game);
void		animate(t_game *game);

//animate player utils
void		animate_player_jumping(t_game *game);
void		animate_player_falling(t_game *game);
void		animate_player_attacking(t_game *game);

// timers
void		update_attack_timer(t_game *game);

//free utils
void		ft_free_arr(char **arr);

// free split
void		ft_freesplit(char **str);

// free sprites
void		free_sprites(t_game *game);
void		free_player_sprites(t_game *game);
void		free_player_moves(t_game *game);
void		free_samus_sprites(t_game *game);

// free sprites utils
void		free_player_idle(t_game *game);
void		free_player_running(t_game *game);
void		free_player_jumping(t_game *game);
void		free_player_attack(t_game *game);
void		free_player_falling(t_game *game);
#endif
