/* ************************************************************************** */
/*    */
/*  :::::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*    +:+ +:+   +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+ +#+  */
/*+#+#+#+#+#+   +#+     */
/*   Created: 2025/01/25 17:42:20 by rafaelfe    #+#    #+# */
/*   Updated: 2025/07/03 22:45:44 by avieira-         ###   ########.fr       */
/*    */
/* ************************************************************************** */

#include "../includes/cub.h"

int	main(void)
{
	t_cub	cub;

	cub_init(&cub);
	init_window(&cub);
	mlx_hook(cub.win_ptr, 02, (1L<<0), key_pressed, &cub); // Listen for key presses
	mlx_hook(cub.win_ptr, 03, (1L<<1), key_released, &cub); // Listen for key releases
	mlx_loop_hook(cub.mlx_ptr, game_loop, &cub);
	mlx_loop(cub.mlx_ptr);
}



