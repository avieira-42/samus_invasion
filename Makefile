# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/27 21:49:52 by avieira-          #+#    #+#              #
#    Updated: 2025/09/22 22:48:48 by avieira-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=game
CC= cc
CFLAGS = -g -Wall -Wextra -Werror -I $(INCLUDES)
LDFLAGS =  -L $(LIBFT_DIR) -lft -L $(MLX_DIR) -Lmlx -lmlx -lXext -lX11 -lbsd -lXext -lX11 -lm 
INCLUDES= includes
LIBFT_DIR= libs/libft
MLX_DIR= libs/minilibx-linux/
MLX= libs/minilibx-linux/libmlx.a
LIBFT= libs/libft/libft.a
SRCS_DIR= srcs

SRCS= $(SRCS_DIR)/delta_bonus.c \
$(SRCS_DIR)/game_loop_bonus.c \
$(SRCS_DIR)/game_loop_utils_bonus.c \
$(SRCS_DIR)/game_loop_utils2_bonus.c \
$(SRCS_DIR)/main_bonus.c \
$(SRCS_DIR)/get_time_bonus.c \
$(SRCS_DIR)/math_bonus.c \
$(SRCS_DIR)/free_displays_bonus.c \
$(SRCS_DIR)/init_game_bonus.c \
$(SRCS_DIR)/init_game_utils_bonus.c \
$(SRCS_DIR)/init_game_utils2_bonus.c \
$(SRCS_DIR)/render_bonus.c \
$(SRCS_DIR)/render_utils_bonus.c \
$(SRCS_DIR)/render_utils2_bonus.c \
$(SRCS_DIR)/ft_pixelput_bonus.c \
$(SRCS_DIR)/input_handler_bonus.c \
$(SRCS_DIR)/item_render_bonus.c \
$(SRCS_DIR)/item_render_utils_bonus.c \
$(SRCS_DIR)/wall_render_bonus.c \
$(SRCS_DIR)/portal_render_bonus.c \
$(SRCS_DIR)/display_moves_bonus.c \
$(SRCS_DIR)/collisions_bonus.c \
$(SRCS_DIR)/collisions_utils_bonus.c\
$(SRCS_DIR)/clear_player_bonus.c\
$(SRCS_DIR)/init_sprites_bonus.c\
$(SRCS_DIR)/init_sprites_utils_bonus.c\
$(SRCS_DIR)/init_sprites_utils2_bonus.c\
$(SRCS_DIR)/init_map_bonus.c \
$(SRCS_DIR)/map_parse_bonus.c \
$(SRCS_DIR)/map_parse_utils_bonus.c \
$(SRCS_DIR)/map_parse_utils2_bonus.c \
$(SRCS_DIR)/parse_bonus.c \
$(SRCS_DIR)/animate_bonus.c \
$(SRCS_DIR)/animate_utils_bonus.c \
$(SRCS_DIR)/animate_utils2_bonus.c \
$(SRCS_DIR)/animate_utils3_bonus.c \
$(SRCS_DIR)/timers_bonus.c \
$(SRCS_DIR)/enemy_render_bonus.c \
$(SRCS_DIR)/enemy_render_utils_bonus.c \
$(SRCS_DIR)/enemy_render_utils2_bonus.c \
$(SRCS_DIR)/free_sprites_bonus.c \
$(SRCS_DIR)/free_sprites_utils_bonus.c \
$(SRCS_DIR)/enemy_collisions_bonus.c

OBJS=$(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(MLX) -o $(NAME)

%.o : %.c $(CC) $(CFLAGS) -I $(INCLUDES) -c $^ -o $@

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
