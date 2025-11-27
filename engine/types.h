/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 03:16:44 by avieira-          #+#    #+#             */
/*   Updated: 2025/11/27 04:11:16 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

#include <stdbool.h>

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
	bool		is_attacking;
	t_animation	attack;
}	t_attack;

typedef struct s_enemy
{
	int				i;
	int				timer;
	int				orientation;
	bool			touching_exit;
	bool			touching_floor;
	bool			touching_wallright;
	bool			touching_wallleft;
	bool			touching_ceiling;
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
	bool			attacking;
	bool			touching_ground;
	bool			touching_leftwall;
	bool			touching_rightwall;
	bool			touching_ceiling;
	bool			touching_exit;
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
	bool		game_start;
	bool		reset;
	bool		end;
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

#endif
