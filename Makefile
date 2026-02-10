# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/27 21:49:52 by avieira-          #+#    #+#              #
#    Updated: 2026/02/10 18:02:53 by avieira-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = samus_invasion

CC = cc
CFLAGS = -g -Wall -Wextra -Werror -O3

LIBFT_DIR = libs/libft/
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = libs/minilibx-linux/
MLX = $(MLX_DIR)/libmlx.a

LDFLAGS = -L $(LIBFT_DIR) -lft \
          -L $(MLX_DIR) -lmlx \
          -lX11 -lbsd -lXext -lX11 -lm

# ===================== SOURCE FILES ===================== #

PARSING = engine/parsing/map_parse_bonus.c \
		  engine/parsing/map_parse_utils2_bonus.c \
		  engine/parsing/map_parse_utils_bonus.c \
		  engine/parsing/parse_bonus.c

INPUT = engine/input/input_handler_bonus.c

PHYSICS = engine/physics/collisions_bonus.c \
		  engine/physics/collisions_utils_bonus.c \
		  engine/physics/delta_bonus.c \
		  engine/physics/enemy_collision.c \
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

ENGINE = $(PARSING) $(INPUT) $(PHYSICS) $(RENDERING) $(CLEARING)
SRCS = $(ENGINE) $(MAIN)
OBJS = $(SRCS:.c=.o)

# ===================== PROGRESS BAR ===================== #

TOTAL := $(words $(SRCS))
BAR_LENGTH = 30
COUNTER = 0

define progress_bar
	$(eval COUNTER=$(shell echo $$(($(COUNTER)+1))))
	@percent=$$((100 * $(COUNTER) / $(TOTAL))); \
	filled=$$(( $(BAR_LENGTH) * $(COUNTER) / $(TOTAL) )); \
	empty=$$(( $(BAR_LENGTH) - $$filled )); \
	bar="$$(printf '%0.s#' $$(seq 1 $$filled))$$(printf '%0.s-' $$(seq 1 $$empty))"; \
	printf "Compiling samus_invasion objects [%s] %3d%%\r" "$$bar" $$percent;
endef

# ===================== TARGETS ===================== #

all: $(LIBFT) $(MLX) $(NAME) logo

$(LIBFT):
	@echo "Building libft..."
	@make -C $(LIBFT_DIR) --no-print-directory > /dev/null 2>&1

$(MLX):
	@echo "Building MinilibX..."
	@make -C $(MLX_DIR) --no-print-directory > /dev/null 2>&1

$(NAME): $(OBJS)
	@echo "\n\033[32mLinking $(NAME)...\033[0m"
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "\033[32mBuild complete!\033[0m"

%.o: %.c
	@$(call progress_bar)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "Cleaning object files... "
	@rm -rf $(OBJS)
	@make clean -C $(LIBFT_DIR) --no-print-directory > /dev/null 2>&1
	@make clean -C $(MLX_DIR) --no-print-directory > /dev/null 2>&1
	@echo "Done."

fclean: clean
	@printf "Removing executable and libft... "
	@rm -rf $(NAME)
	@rm -f $(LIBFT)          # <-- remove the libft.a archive
	@echo "Done."

re: fclean all logo

# ===================== ASCII LOGO ===================== #

logo:
	@printf "[95m\n"
	@printf "  ██████  ▄▄▄       ███▄ ▄███▓ █    ██   ██████           ██▓ ███▄    █ ██▒   █▓ ▄▄▄        ██████  ██▓ ▒█████   ███▄    █ \n"
	@printf "▒██    ▒ ▒████▄    ▓██▒▀█▀ ██▒ ██  ▓██▒▒██    ▒          ▓██▒ ██ ▀█   █▓██░   █▒▒████▄    ▒██    ▒ ▓██▒▒██▒  ██▒ ██ ▀█   █ \n"
	@printf "░ ▓██▄   ▒██  ▀█▄  ▓██    ▓██░▓██  ▒██░░ ▓██▄            ▒██▒▓██  ▀█ ██▒▓██  █▒░▒██  ▀█▄  ░ ▓██▄   ▒██▒▒██░  ██▒▓██  ▀█ ██▒\n"
	@printf "  ▒   ██▒░██▄▄▄▄██ ▒██    ▒██ ▓▓█  ░██░  ▒   ██▒         ░██░▓██▒  ▐▌██▒ ▒██ █░░░██▄▄▄▄██   ▒   ██▒░██░▒██   ██░▓██▒  ▐▌██▒\n"
	@printf "▒██████▒▒ ▓█   ▓██▒▒██▒   ░██▒▒▒█████▓ ▒██████▒▒         ░██░▒██░   ▓██░  ▒▀█░   ▓█   ▓██▒▒██████▒▒░██░░ ████▓▒░▒██░   ▓██░\n"
	@printf "▒ ▒▓▒ ▒ ░ ▒▒   ▓▒█░░ ▒░   ░  ░░▒▓▒ ▒ ▒ ▒ ▒▓▒ ▒ ░         ░▓  ░ ▒░   ▒ ▒   ░ ▐░   ▒▒   ▓▒█░▒ ▒▓▒ ▒ ░░▓  ░ ▒░▒░▒░ ░ ▒░   ▒ ▒ \n"
	@printf "░ ░▒  ░ ░  ▒   ▒▒ ░░  ░      ░░░▒░ ░ ░ ░ ░▒  ░ ░          ▒ ░░ ░░   ░ ▒░  ░ ░░    ▒   ▒▒ ░░ ░▒  ░ ░ ▒ ░  ░ ▒ ▒░ ░ ░░   ░ ▒░\n"
	@printf "░  ░  ░    ░   ▒   ░      ░    ░░░ ░ ░ ░  ░  ░            ▒ ░   ░   ░ ░     ░░    ░   ▒   ░  ░  ░   ▒ ░░ ░ ░ ▒     ░   ░ ░ \n"
	@printf "      ░        ░  ░       ░      ░           ░            ░           ░      ░        ░  ░      ░   ░      ░ ░           ░ \n"
	@printf "                                                                            ░                                              \n"
	@printf "\n\033[0m"

.PHONY: all clean fclean re logo
