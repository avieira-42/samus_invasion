# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/03 20:38:39 by avieira-          #+#    #+#              #
#    Updated: 2025/07/03 21:13:54 by avieira-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = cc -Wall -Wextra -Werror -g
MLX = minilibx-linux/libmlx_Linux.a
MLXFLAGS = -lX11 -lXext -lm -lz
SRCS = srcs/so_long.c

compile:
	$(CFLAGS) $(SRCS) $(MLX) $(MLXFLAGS)

minilibx:
	make -C minilibx-linux/
