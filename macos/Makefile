# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ginger <ginger@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/22 13:50:30 by ginger            #+#    #+#              #
#    Updated: 2020/05/14 19:11:17 by ginger           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = main.c \
		init.c \
		utils.c \
		digit_utils.c \
		read_map.c \
		utils_2.c \
		strcturing.c \
		colors.c \
		draw.c \
		visual.c \
		controls.c \
		rotation.c \
		menu.c \
		processing_controls.c \
		utils_3.c

CC = gcc
FLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
INCLUDES = -I./libft/ \
	-I./minilibx_macos/

LIBSINC = -L../libft/ \
	-L./minilibx_macos/

LIBFTPATH = ../libft/
MINILIBXPATH = ./minilibx_macos/

LIBSNAME = libft.a \
	libmlx.a

HEADERS = fdf.h \
			errors.h \
			colors.h \
			mac_controls.h

all: $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFTPATH)
	@$(MAKE) -C $(MINILIBXPATH)
	@$(CC) -o $(NAME) $(OBJS) $(LIBSINC) -lmlx -lm -lft -framework OpenGL -framework AppKit

clean:
	$(MAKE) fclean -C $(LIBFTPATH)
	$(MAKE) clean -C $(MINILIBXPATH)
	/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
