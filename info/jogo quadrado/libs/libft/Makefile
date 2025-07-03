# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/01 16:45:58 by rafaelfe          #+#    #+#              #
#    Updated: 2024/11/01 16:45:58 by rafaelfe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR = ./libft
PRINTF_DIR = ./ft_printf
GET_DIR = ./get_next_line

SRCS = $(LIBFT_DIR)/ft_atoi.c $(LIBFT_DIR)/ft_bzero.c $(LIBFT_DIR)/ft_calloc.c $(LIBFT_DIR)/ft_isalnum.c $(LIBFT_DIR)/ft_isalpha.c \
$(LIBFT_DIR)/ft_isascii.c $(LIBFT_DIR)/ft_isdigit.c $(LIBFT_DIR)/ft_isprint.c $(LIBFT_DIR)/ft_itoa.c $(LIBFT_DIR)/ft_memchr.c $(LIBFT_DIR)/ft_memcmp.c \
$(LIBFT_DIR)/ft_memcpy.c $(LIBFT_DIR)/ft_memmove.c $(LIBFT_DIR)/ft_memset.c $(LIBFT_DIR)/ft_putchar_fd.c $(LIBFT_DIR)/ft_putendl_fd.c \
$(LIBFT_DIR)/ft_putnbr_fd.c $(LIBFT_DIR)/ft_putstr_fd.c $(LIBFT_DIR)/ft_split.c $(LIBFT_DIR)/ft_strchr.c $(LIBFT_DIR)/ft_strdup.c $(LIBFT_DIR)/ft_striteri.c \
$(LIBFT_DIR)/ft_strjoin.c $(LIBFT_DIR)/ft_strlcat.c $(LIBFT_DIR)/ft_strlcpy.c $(LIBFT_DIR)/ft_strlen.c $(LIBFT_DIR)/ft_strmapi.c $(LIBFT_DIR)/ft_strncmp.c \
$(LIBFT_DIR)/ft_strnstr.c $(LIBFT_DIR)/ft_strrchr.c $(LIBFT_DIR)/ft_strtrim.c $(LIBFT_DIR)/ft_substr.c $(LIBFT_DIR)/ft_tolower.c $(LIBFT_DIR)/ft_toupper.c \
$(LIBFT_DIR)/ft_lstnew.c $(LIBFT_DIR)/ft_lstsize.c $(LIBFT_DIR)/ft_lstadd_front.c $(LIBFT_DIR)/ft_lstlast.c $(LIBFT_DIR)/ft_lstadd_back.c \
$(LIBFT_DIR)/ft_lstdelone.c $(LIBFT_DIR)/ft_lstclear.c $(LIBFT_DIR)/ft_lstiter.c $(LIBFT_DIR)/ft_lstmap.c $(PRINTF_DIR)/ft_printf.c $(PRINTF_DIR)/ft_putchars.c \
$(PRINTF_DIR)/ft_putnbrs.c $(GET_DIR)/get_next_line.c $(GET_DIR)/get_next_line_utils.c


CC = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = includes/

OBJS = $(SRCS:.c=.o)

NAME = libft.a

all : $(NAME)
	@echo "libft compiled!!!"

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $^ -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY = all clean fclean re bonus
