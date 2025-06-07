# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 08:56:06 by rsoo              #+#    #+#              #
#    Updated: 2025/06/07 21:58:33 by rsoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -I/usr/include -Imlx_linux -O3
FSAN = -fsanitize=address -fdiagnostics-color=always 
RM = rm -rf

SRCS_DIR = srcs/
SRCS = main map_parsing hooks map_drawing transform_utils_1 transform_utils_2 transform_utils_3 rendering utils color_1 color_2
SRCS_CFILES = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS)))
OBJS = $(SRCS_CFILES:.c=.o)

LIBFT_DIR = libft
LIBFT = libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	make bonus -C $(LIBFT_DIR)
	$(CC) $(FSAN) $(OBJS) -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(LIBFT_DIR)/$(LIBFT)

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY = clean fclean re all
