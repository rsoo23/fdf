# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 08:56:06 by rsoo              #+#    #+#              #
#    Updated: 2025/06/08 09:25:19 by rsoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
INCLUDE = -I/usr/include -Imlx_linux -Iincludes
LDFLAGS = -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
FSAN = -fsanitize=address -fdiagnostics-color=always 
RM = rm -rf

SRCS_DIR = srcs
OBJS_DIR = obj
SRCS = $(wildcard $(SRCS_DIR)/*.c)
# Automatically finds all .c files in srcs/ and maps them to obj/*.o
OBJS = $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS))

LIBFT_DIR = libft
LIBFT = libft.a

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	make bonus -C $(LIBFT_DIR)
	$(CC) $(FSAN) $(OBJS) $(LDFLAGS) -o $(NAME) $(LIBFT_DIR)/$(LIBFT)

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY = clean fclean re all
