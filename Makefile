# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/16 18:53:03 by kaye              #+#    #+#              #
#    Updated: 2021/01/16 20:34:34 by kaye             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILATION

CC = gcc
CFLAG = -Wall -Wextra -Werror
IFLAG = -I./inc -I./libft/inc -I./mlx
LFLAG = -Lmlx -lmlx -lm -framework OpenGL -framework AppKit
IFLAGS_LINUX = -I./inc -I./libft_linux/inc -I./mlx_linux
LFLAG_LINUX = -Lmlx -lmlx -lXext -lX11 -lm

# DIRECTORY

BUILD 	:= .build
INC_DIR := inc
SRC_DIR := src
SUB_DIR := engine \
		   events \
		   init_utils \
		   parser_map \
		   parser_map_file
LFT_DIR := libft
MLX_DIR := mlx
LFT_DIR_LINUX = libft_linux
MLX_DIR_LINUX := mlx_linux
OBJ_DIR := $(BUILD)/obj
DIRS	:= $(OBJ_DIR) $(addprefix $(OBJ_DIR)/, $(SUB_DIR))

# FILE

NAME  	:= Cub3d
LIBFT 	:= libft.a
MLX   	:= libmlx.dylib
MLX_LINUX := libmlx_Linux.a
SRC	  	:= main.c
SUB_SRC := img.c \
		   mapping.c \
		   move.c \
		   ray_casting_utils.c \
		   ray_casting.c \
		   set_camera.c \
		   turn.c
SRC 	+= $(addprefix engine/, $(SUB_SRC))
SUB_SRC := event_key.c \
		   event_loop.c \
		   event_win.c
SRC		+= $(addprefix events/, $(SUB_SRC))
SUB_SRC := color.c \
		   free.c \
		   init.c \
		   msg_error.c \
		   quit.c
SRC		+= $(addprefix init_utils/, $(SUB_SRC))
SUB_SRC := check_map.c \
		   check_x.c \
		   check_y.c \
		   get_map.c \
		   get_player_place.c
SRC		+= $(addprefix parser_map/, $(SUB_SRC))
SUB_SRC := check_file_line_id.c \
		   check_file_line_map.c \
		   check_file_name.c \
		   check_file.c \
		   check_path.c \
		   floor_ceiling.c \
		   get_color.c \
		   get_path.c \
		   get_resolution.c \
		   init_desc.c
SRC		+= $(addprefix parser_map_file/, $(SUB_SRC))
OBJ	  	:= $(SRC:%.c=$(OBJ_DIR)/%.o)

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

## Macos #########################
ifeq ($(shell uname), Darwin)
$(NAME): $(OBJ)
	$(MAKE) -C $(LFT_DIR)
	$(MAKE) -C $(MLX_DIR)
	cp ./$(LFT_DIR)/$(LIBFT) .
	cp ./$(MLX_DIR)/$(MLX) .
	$(CC) $(CFLAG) $(IFLAG) $(LFLAG) $(LIBFT) $(MLX) $^ -o $@
endif
##################################

## Linux #########################
ifeq ($(shell uname), Linux)
$(NAME): $(OBJ)
	$(MAKE) -C $(LFT_DIR_LINUX)
	$(MAKE) -C $(MLX_DIR_LINUX)
	cp ./$(LFT_DIR_LINUX)/$(LIBFT) .
	cp ./$(MLX_DIR_LINUX)/$(MLX_LINUX) .
	$(CC) $(CFLAG) $(IFLAGS_LINUX) $^ -o $@ $(LFLAG_LINUX) $(LIBFT) $(MLX_LINUX)
endif
##################################

all: $(NAME)

## Macos #########################
ifeq ($(shell uname), Darwin)	
clean:
	$(MAKE) -C $(LFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(BUILD)
endif

ifeq ($(shell uname), Darwin)
fclean: clean
	$(MAKE) -C $(LFT_DIR) fclean
	rm -rf $(NAME) $(LIBFT) $(MLX)
endif	
##################################


## Linux #########################
ifeq ($(shell uname), Linux)	
clean:
	$(MAKE) -C $(LFT_DIR_LINUX) clean
	$(MAKE) -C $(MLX_DIR_LINUX) clean
	rm -rf $(BUILD)
endif

ifeq ($(shell uname), Linux)
fclean: clean
	$(MAKE) -C $(LFT_DIR_LINUX) fclean
	rm -rf $(NAME) $(LIBFT) $(MLX_LINUX)
endif
##################################

re: fclean all

.PHONY: all clean fclean re
	
$(BUILD):
	mkdir $@ $(DIRS)

## Macos #########################
ifeq ($(shell uname), Darwin)	
$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c | $(BUILD)
	$(CC) $(CFLAG) $(IFLAG) -c $< -o $@
endif
##################################

## Linux #########################
ifeq ($(shell uname), Linux)	
$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c | $(BUILD)
	$(CC) $(CFLAG) $(IFLAGS_LINUX) -c $< -o $@
endif
##################################

