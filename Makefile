# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/16 18:53:03 by kaye              #+#    #+#              #
#    Updated: 2020/12/17 16:19:09 by kaye             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILATION

CC = gcc
CFLAG = -Wall -Wextra -Werror
IFLAG = -I./inc -I./libft/inc -I./mlx
LFLAG = -Lmlx -lmlx -lm -framework OpenGL -framework AppKit

# DIRECTORY

BUILD 	= .build
INC_DIR = inc
SRC_DIR = src
LFT_DIR = libft
MLX_DIR = mlx
OBJ_DIR = $(BUILD)/obj
DIRS	= $(OBJ_DIR)

# FILE

NAME  := Cub3d
LIBFT := libft.a
MLX   := libmlx.dylib
SRC	  := main.c
OBJ	  := $(SRC:%.c=$(OBJ_DIR)/%.o)

# COLORS

DEFAULT_COLOR	= \033[0m
BLACK_COLOR		= \033[1;30m
RED_COLOR		= \033[1;31m
GREEN_COLOR		= \033[1;32m
YELLOW_COLOR	= \033[1;33m
BLUE_COLOR		= \033[1;34m
MAGENTA_COLOR 	= \033[1;35m
CYAN_COLOR 		= \033[1;36m
WHITE_COLOR 	= \033[1;107m

# Makefile

$(NAME): $(OBJ)
	$(CC) $(CFLAG) $(IFLAG) $(LFLAG) $^ -o $@

all: $(NAME)
	
clean:
	$(MAKE) -C $(LFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(BUILD)

fclean: clean
	$(MAKE) -C $(LFT_DIR) fclean
	rm -rf $(NAME) $(LIBFT) $(MLX)

re: fclean all

.PHONY: all clean fclean re
	
$(BUILD):
	mkdir $@ $(DIRS)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c | $(BUILD)
	$(MAKE) -C $(LFT_DIR)
	$(MAKE) -C $(MLX_DIR)
	cp ./$(LFT_DIR)/$(LIBFT) .
	cp ./$(MLX_DIR)/$(MLX) .
	$(CC) $(CFLAG) $(IFLAG) -c $< -o $@
