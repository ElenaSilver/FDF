# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/25 17:32:52 by eserebry          #+#    #+#              #
#    Updated: 2017/09/29 02:46:09 by eserebry         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror -Ofast
CC = gcc

CMP = -L minilibx -lmlx -framework OpenGL -framework AppKit

SRC = 	color_mgmt.c\
		draw_map.c\
		init_map.c\
		main.c\
		usage.c

OBJ = $(SRCS:.c=.o)
 
SRCDIR = srcs
OBJDIR = objs

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))

HEADER = fdf.h

RM = rm -rf

GREEN = \033[32m
RED = \033[31m

all: $(NAME)


$(NAME): $(OBJ)
		@make -C libft/
		@$(CC) -o $(NAME) $(SRCS) $(CMP) $(FLAG) libft/libft.a 
		@echo "$(GREEN)fdf: creating object files"

clean: 
		@/bin/$(RM) $(OBJ)
		@make -C libft/ clean

fclean: clean
		@make -C libft/ fclean
		@/bin/$(RM) $(NAME)
		@echo "$(RED)fdf: deleting object files"

re: fclean all

.PHONY: all clean fclean re
.SUFFIXES: .c .o