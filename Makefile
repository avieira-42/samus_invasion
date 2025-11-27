# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/27 21:49:52 by avieira-          #+#    #+#              #
#    Updated: 2025/11/27 05:03:11 by avieira-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = samus_invasion

LIBFT_DIR = libs/libft/

CC = cc

CFLAGS = -g -Wall -Wextra -Werror

LDFLAGS =  -L $(LIBFT_DIR) -lft -L $(MLX_DIR) -Lmlx -lmlx -lX11 -lbsd -lXext -lX11 -lm 

MLX_DIR = libs/minilibx-linux/

MLX = libs/minilibx-linux/libmlx.a

LIBFT = libs/libft/libft.a


PARSING = engine/parsing/map_parse_bonus.c \
		  engine/parsing/map_parse_utils2_bonus.c \
		  engine/parsing/map_parse_utils_bonus.c \
		  engine/parsing/parse_bonus.c

INPUT = engine/input/input_handler_bonus.c

PHYSICS = engine/physics/collisions_bonus.c \
		  engine/physics/collisions_utils_bonus.c \
		  engine/physics/delta_bonus.c \
		  engine/physics/enemy_collision.c\
		  engine/physics/enemy_collisions_bonus.c \
		  engine/physics/get_time_bonus.c \
		  engine/physics/math_bonus.c


RENDERING = engine/rendering/animate_bonus.c \
			engine/rendering/animate_utils2_bonus.c \
			engine/rendering/animate_utils3_bonus.c \
			engine/rendering/animate_utils_bonus.c \
			engine/rendering/display_moves_bonus.c \
			engine/rendering/enemy_render_bonus.c \
			engine/rendering/enemy_render_utils_bonus.c \
			engine/rendering/ft_pixelput_bonus.c \
			engine/rendering/init_sprites_bonus.c \
			engine/rendering/init_sprites_utils2_bonus.c \
			engine/rendering/init_sprites_utils_bonus.c \
			engine/rendering/item_render_bonus.c \
			engine/rendering/item_render_utils_bonus.c \
			engine/rendering/portal_render_bonus.c \
			engine/rendering/render_bonus.c \
			engine/rendering/render_utils2_bonus.c \
			engine/rendering/render_utils_bonus.c \
			engine/rendering/timers_bonus.c \
			engine/rendering/wall_render_bonus.c


CLEARING = engine/clearing/clear_player_bonus.c \
		   engine/clearing/free_displays_bonus.c \
		   engine/clearing/free_sprites_bonus.c \
		   engine/clearing/free_sprites_utils_bonus.c

MAIN = main/game_loop_bonus.c \
	   main/game_loop_utils2_bonus.c \
	   main/game_loop_utils_bonus.c \
	   main/init_game_bonus.c \
	   main/init_game_utils2_bonus.c \
	   main/init_game_utils_bonus.c \
	   main/init_map_bonus.c \
	   main/main_bonus.c

ENGINE = $(PARSING) \
		 $(INPUT) \
		 $(PHYSICS) \
		 $(RENDERING) \
		 $(CLEARING)

SRCS = $(ENGINE) \
	   $(MAIN)

OBJS=$(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(MLX) -o $(NAME)

%.o : %.c $(CC) $(CFLAGS) -c $^ -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX):
	@make -C $(MLX_DIR)

clean:
	@rm -rf $(OBJS)
	@make clean -C $(LIBFT_DIR) --no-print-directory
	@make clean -C $(MLX_DIR) --no-print-directory
	@echo "Cleaning Objects!"

fclean: clean
	@rm -rf $(LIBFT)
	@rm -rf $(NAME)
	@rm -rf $(MLX)
	@echo "Cleaning Objects and executable"

re: fclean all

.PHONY: all clean fclean re
