/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 03:16:35 by avieira-          #+#    #+#             */
/*   Updated: 2025/11/27 03:16:36 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "types.h"

int			key_pressed(int keysym, t_game *game);
int			key_released(int keysym, t_game *game);

#endif
