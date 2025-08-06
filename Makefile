# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/27 21:49:52 by avieira-          #+#    #+#              #
#    Updated: 2025/08/06 03:32:20 by a-soeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= so_long
B_NAME= so_long_bonus
CC= cc
CFLAGS = -g -Wall -Wextra -Werror -std=c99 -I$(INCLUDES)
LDFLAGS =  -L $(LIBFT_DIR) -lft -L $(MLX_DIR) -Lmlx -lmlx -lXext -lX11 -lbsd -lXext -lX11 -lm 
INCLUDES= ./includes
LIBFT_DIR= ./libs/libft
MLX_DIR= ./libs/mlx
MLX= $(MLX_DIR)/libmlx.a
LIBFT= $(LIBFT_DIR)/libft.a
SRCS_DIR= ./srcs
B_SRCS_DIR= ./b_srcs

SRCS= $(SRCS_DIR)/main.c \
$(SRCS_DIR)/init_map.c \
$(SRCS_DIR)/parse.c \
$(SRCS_DIR)/map_parse.c \
$(SRCS_DIR)/map_parse_utils.c \
$(SRCS_DIR)/map_parse_utils2.c \
$(SRCS_DIR)/init_game.c \
$(SRCS_DIR)/init_game_utils.c \
$(SRCS_DIR)/map_render.c \
$(SRCS_DIR)/map_render_utils.c \
$(SRCS_DIR)/input_handler.c \
$(SRCS_DIR)/game_loop.c \
$(SRCS_DIR)/free_displays.c

B_SRCS= $(B_SRCS_DIR)/delta_bonus.c \
$(B_SRCS_DIR)/game_loop_bonus.c \
$(B_SRCS_DIR)/game_loop_utils_bonus.c \
$(B_SRCS_DIR)/game_loop_utils2_bonus.c \
$(B_SRCS_DIR)/main_bonus.c \
$(B_SRCS_DIR)/get_time_bonus.c \
$(B_SRCS_DIR)/math_bonus.c \
$(B_SRCS_DIR)/free_displays_bonus.c \
$(B_SRCS_DIR)/init_game_bonus.c \
$(B_SRCS_DIR)/init_game_utils_bonus.c \
$(B_SRCS_DIR)/render_bonus.c \
$(B_SRCS_DIR)/render_utils_bonus.c \
$(B_SRCS_DIR)/render_utils2_bonus.c \
$(B_SRCS_DIR)/ft_pixelput_bonus.c \
$(B_SRCS_DIR)/input_handler_bonus.c \
$(B_SRCS_DIR)/item_render_bonus.c \
$(B_SRCS_DIR)/item_render_utils_bonus.c \
$(B_SRCS_DIR)/wall_render_bonus.c \
$(B_SRCS_DIR)/portal_render_bonus.c \
$(B_SRCS_DIR)/display_moves_bonus.c \
$(B_SRCS_DIR)/collisions_bonus.c \
$(B_SRCS_DIR)/collisions_utils_bonus.c\
$(B_SRCS_DIR)/clear_player_bonus.c\
$(B_SRCS_DIR)/init_sprites_bonus.c\
$(B_SRCS_DIR)/init_sprites_utils_bonus.c\
$(B_SRCS_DIR)/init_sprites_utils2_bonus.c\
$(B_SRCS_DIR)/init_map_bonus.c \
$(B_SRCS_DIR)/map_parse_bonus.c \
$(B_SRCS_DIR)/map_parse_utils_bonus.c \
$(B_SRCS_DIR)/map_parse_utils2_bonus.c \
$(B_SRCS_DIR)/parse_bonus.c \
$(B_SRCS_DIR)/animate_bonus.c \
$(B_SRCS_DIR)/animate_utils_bonus.c \
$(B_SRCS_DIR)/animate_utils2_bonus.c \
$(B_SRCS_DIR)/animate_utils3_bonus.c \
$(B_SRCS_DIR)/timers_bonus.c \
$(B_SRCS_DIR)/enemy_render_bonus.c \
$(B_SRCS_DIR)/enemy_render_utils_bonus.c \
$(B_SRCS_DIR)/enemy_render_utils2_bonus.c \
$(B_SRCS_DIR)/free_sprites_bonus.c \
$(B_SRCS_DIR)/free_sprites_utils_bonus.c \
$(B_SRCS_DIR)/enemy_collisions_bonus.c

OBJS=$(SRCS:.c=.o)
B_OBJS=$(B_SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME) : $(MLX) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(MLX) -o $(NAME)

bonus: .bonus

.bonus: $(MLX) $(LIBFT) $(B_OBJS)
	$(CC) $(CFLAGS) $(B_OBJS) $(LDFLAGS) $(MLX) -o $(B_NAME)
	touch .bonus

%.o : %.c $(CC) $(CFLAGS) -I $(INCLUDES) -c $^ -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR) --no-print-directory

$(MLX):
	if [ ! -d "$(MLX_DIR)" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR); \
	fi
	@$(MAKE) -C $(MLX_DIR)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(B_OBJS)
	@rm -rf .bonus
	@make clean -C $(LIBFT_DIR) --no-print-directory
	if [ -f "$(MLX_DIR)" ]; then \
		make clean -C $(MLX_DIR) --no-print-directory; \
	fi

	@echo "Cleaning Objects!"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(B_NAME)
	if [ -d "$(MLX_DIR)" ]; then \
		rm -rf $(MLX_DIR); \
	fi

	@make fclean -C $(LIBFT_DIR) --no-print-directory
	@echo "Cleaning Objects and executable"

re: fclean all

.PHONY: all clean fclean re


