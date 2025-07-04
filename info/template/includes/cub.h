/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:34:13 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/06/27 15:25:12 by rafaelfe         ###   ########.fr       */
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

# define SCREEN_SIZE_X 1200
# define SCREEN_SIZE_Y 600
# define LINE_COLOR 0xFFFFFF
# define TILE_SIZE 32
# define GRAVITY 250
# define MAX_SPEED 500
# define ACCEL 500

typedef struct s_point
{
	float	x;
	float	y;
}	t_point;

typedef struct s_player
{
	t_point pos;
	t_point direction;
	t_point velocity;
	bool 	jump;

}	t_player;


typedef struct s_drawline
{
	int	dx;
	int	dy;
	int	xi;
	int	yi;
	int	d;
	int	color;
}	t_drawline;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_cub
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	int			fd;
	int			map_height;
	int			map_width;
	t_image		north_texture;
	t_image		south_texture;
	t_image		east_texture;
	t_image		west_texture;
	long long	last_frame_time;
	float		delta;
	t_player	player;
	t_image	image;
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
int	ft_load_map(char *map, t_cub *cub);

//render utils
void		drawrect(t_image *image, t_point pos, t_point size, int color);
t_image		*get_wall_color_from_direction(t_cub *cub, int side, float ray_x, float ray_y);
void		ft_pixelput(t_image *data, int x, int y, int color);
void		drawline(t_cub *cub, t_point start, t_point dest);
void		circleBres(t_cub *cub, int xc, int yc, int r);

t_point		get_mouse_position(t_cub *cub);
//struct utils
int			check_args(char *str);

//math
int			ft_abs(int num);
long long	get_time(void);
float		 clamp(float value, float min, float max);
t_point		normalize(t_point point);

//free utils

void	ft_free_arr(char **arr);


#endif
