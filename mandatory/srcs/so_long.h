/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshonta <lshonta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:38:42 by lshonta           #+#    #+#             */
/*   Updated: 2025/07/28 20:15:03 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/includes/libft.h"
# include "../libs/mlx/mlx.h"
# include "../libs/mlx/mlx_int.h"
# include <strings.h>
# include <limits.h>
# include <math.h>
# include <sys/time.h>
# include <stdbool.h>

# define WALL "./pictures/tile.xpm"
# define PLAYER "./pictures/player.xpm"
# define EXIT "./pictures/portal.xpm"
# define COLLECT "./pictures/towel.xpm"

typedef struct s_graph
{
	void	*wall;
	void	*collect;
	void	*exit;
	void	*player;
}	t_graph;

typedef struct s_init_map
{
	int		hight;
	int		lenght;
	int		x;
	int		y;
	int		player;
	int		escape;
	int		count;
	int		step;
	char	**map;
	void	*wall;
	void	*mlx;
	void	*win;
	char	*fn;
	t_graph	*graph;

}	t_init_map;

void	ft_read_map(t_init_map *data);
void	ft_map_hight(t_init_map *data);
void	ft_map_data(t_init_map *data, char *name);
void	ft_parse_map(t_init_map *render);
int		ft_frame(t_init_map *data);
void	ft_create_map(t_init_map *data);
int		ft_exit(t_init_map *data);
int		press_key(int keycode, t_init_map *data);

void	ft_char_set(t_init_map *data);
void	ft_check_char(t_init_map *data);
void	ft_check_format(t_init_map *data);
void	ft_check_wall(t_init_map *data);
void	ft_game_result(t_init_map *data);

#endif
