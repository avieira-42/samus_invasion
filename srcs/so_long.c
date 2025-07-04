/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:56:31 by avieira-          #+#    #+#             */
/*   Updated: 2025/07/04 18:06:46 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* SO_LONG

Game objectives:

1. Gather all collectibles
2. Use WASD to move in four directions: up, down, left and right
3. Player can't pass through walls
4. At everymove, the current number of movements must be displayed in the shell
5. The player loses if the character touches an enemy patrol
6. Sprite animations
7. Display movement count directly on screen instead of writing it in the shell

Mandatory functionalities:

1. Program has to display the image in a window
2. Winow management must remain smooth(switching to another window, minimizing, etc.)
4. Pressing ESC must close the window and quit the program in a clean way.
5. CLicking on the cross of the window must do the same as the ESC.
6. Use of images of the MiniLibX is mandatory.(???)

Map functionalities:

1. Map bust be contructed with 3 components (walls, collectibles and free space)
2. The map can be composed of these 5 characters (like in map_chars.png)
	2.1. 0 for empty spcae
	2.2. 1 for a wall
	2.3. C for a collectible
	2.4. E for a map exit (no duplicates)
	2.5. P for the player's starting position (no duplicates)
3. Map must be rectangular
4. The map must be encolsed by walls. If not, it must return an error
5. There must be a verification for a valid map path
6. Any kind of map must be parsed if it respects the above rules
7. Another example of a minimal .ber map2.png
8. If any misconfig is encountered in the files, the program must exit cleanly and return 'Error\n' followed by an explicit error message of your choice. */

#include <math.h>
#include "../include/libft/include/libft.h"
#include "../minilibx-linux/mlx.h"

int	main(void)
{
}
