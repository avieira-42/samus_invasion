/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 20:46:09 by avieira-          #+#    #+#             */
/*   Updated: 2025/07/04 23:20:54 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_G_H
# define SO_LONG_G_H

# include "../include/libft/include/libft.h"
# include <stdbool.h>
# include <math.h>
# include <sys/time.h>

// SCREEN //
# define WIDTH 1920
# define HEIGHT 1080

// SQUARE //
# define LINE_COLOR 0xFFFFFF
# define TILE_SIZE 32

// PHYSICS //
# define GRAVITY 250
# define MAX_SPEED 500
# define ACCEL 500

// KEYS //
# define W 119
# define A 97
# define S 115
# define D 100
# define Q 113 // projectile
# define E 101 // attack
# define ESC 65307
# define SPACE 32 // jump
# define SHIFT 65505 // dash
# define L_ARROW 65361 // left
# define U_ARROW 65362  // up
# define D_ARROW 65364 // down
# define R_ARROW 65363 // right
# define PRESS_EVENT 2
# define RELEASE_EVENT 3
# define PRESS_MASK 1L<<0
# define RELEASE_MASK 1L<<1

// MESSAGES //
# define ESC_INFO_MESSAGE "Press ESC to exit window"
# define ESC_PRESSED "ESC pressed: Exiting\n"
# define SO_LONG "SO_LONG"

typedef struct s_point
{
	float x;
	float y;
}	t_point;

typedef struct s_player
{
	t_point	pos;
	t_point	direction;
	t_point	velocity;
	int		jump;
	int		dash;
	int		slash;
	int		projectile;
}	t_player;

typedef struct t_patrol
{
	t_point	pos;
	t_point	direction;
	t_point	velocity;
	bool		attack;
}	t_patrol;

typedef struct t_boss
{
	t_point pos;
	t_point	direction;
	t_point	velocity;
	bool	jump;
	bool	attack;
	bool	projectile;
	bool	dash;
	bool	damaged;
}	t_boss;

typedef	struct s_image
{
	void	image;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct t_game
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
	t_image		image;
}	t_game;

void	start_game(t_game *game);
void	pixel_render(t_image *sprite, int x, int y, int color);
void	get_time(void);
void	get_delta(t_game *game);
void	close_game(t_game *game);
void	key_pressed(int key_symb, t_game *game);
void	open_window(t_game *game);
