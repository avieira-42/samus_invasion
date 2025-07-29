# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: a-soeiro <marvavieira-@student.42porto.com +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/27 21:49:52 by a-soeiro          #+#    #+#              #
#    Updated: 2025/07/29 00:08:03 by a-soeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	NAME= cub3d
CC= cc
CFLAGS = -g -Wall -Wextra -Werror -std=c99 -I $(INCLUDES)
LDFLAGS =  -L $(LIBFT_DIR) -lft -L $(MLX_DIR) -Lmlx -lmlx -lXext -lX11 -lbsd -lXext -lX11 -lm 
INCLUDES= ./includes
LIBFT_DIR= ./libs/libft
MLX_DIR= ./libs/mlx
MLX= $(MLX_DIR)/libmlx.a
LIBFT= $(LIBFT_DIR)/libft.a
SRCS_DIR= ./srcs

SRCS= $(SRCS_DIR)/main.c \
$(SRCS_DIR)/free_displays.c \
$(SRCS_DIR)/init_game.c \
$(SRCS_DIR)/map_render.c \
$(SRCS_DIR)/map_render_utils.c \
$(SRCS_DIR)/ft_free.c \
$(SRCS_DIR)/init_map.c \
$(SRCS_DIR)/init_window.c \
$(SRCS_DIR)/map_parse.c \
$(SRCS_DIR)/map_parse_utils.c \
$(SRCS_DIR)/input_handler.c \
$(SRCS_DIR)/game_loop.c \
$(SRCS_DIR)/parse.c

#$(SRCS_DIR)/physics_utils.c \

OBJS=$(SRCS:.c=.o)

all: $(NAME) clean

$(NAME) : $(MLX) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(MLX) -o $(NAME)

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
	@make clean -C $(LIBFT_DIR) --no-print-directory
	if [ -d "$(MLX_DIR)" ]; then \
		make clean -C $(MLX_DIR) --no-print-directory; \
	fi

	@echo "Cleaning Objects!"
fclean: clean
	@rm -rf $(NAME)
	if [ -d "$(MLX_DIR)" ]; then \
		rm -rf $(MLX_DIR); \
	fi

	@make fclean -C $(LIBFT_DIR) --no-print-directory
	@echo "Cleaning Objects and executable"

re: fclean all

.PHONY: all clean fclean re


