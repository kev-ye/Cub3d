# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/16 18:53:03 by kaye              #+#    #+#              #
#    Updated: 2021/01/18 09:00:24 by kaye             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###########################################################
#                                                         #
# Macos : #################################################
#                                                         #
###########################################################

ifeq ($(shell uname), Darwin)

# COMPILATION #############################################

CC = gcc
CFLAG = -Wall -Wextra -Werror
IFLAG = -I./inc -I./libft/libft/inc -I./mlx/mlx
LFLAG = -L./mlx/mlx -lmlx -lm -framework OpenGL -framework AppKit

# DIRECTORY ###############################################

BUILD 	:= .build
INC_DIR := inc
SRC_DIR := src
SUB_DIR := engine \
		   events \
		   init_utils \
		   parser_map \
		   parser_map_file
LFT_DIR := libft/libft
MLX_DIR := mlx/mlx
OBJ_DIR := $(BUILD)/obj
DIRS	:= $(OBJ_DIR) $(addprefix $(OBJ_DIR)/, $(SUB_DIR))

# FILE ####################################################

NAME  	:= Cub3d
LIBFT 	:= libft.a
MLX   	:= libmlx.dylib
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

# COLORS ##################################################

DEFAULT_COLOR	= \033[0m
BLACK_COLOR		= \033[1;30m
RED_COLOR		= \033[1;31m
GREEN_COLOR		= \033[1;32m
YELLOW_COLOR	= \033[1;33m
BLUE_COLOR		= \033[1;34m
MAGENTA_COLOR 	= \033[1;35m
CYAN_COLOR 		= \033[1;36m
WHITE_COLOR 	= \033[1;107m

# Makefile ################################################

$(NAME): $(OBJ)
	$(MAKE) -C $(LFT_DIR)
	$(MAKE) -C $(MLX_DIR)
	cp ./$(LFT_DIR)/$(LIBFT) .
	cp ./$(MLX_DIR)/$(MLX) .
	$(CC) $(CFLAG) $(IFLAG) $(LFLAG) $(LIBFT) $(MLX) $^ -o $@

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
	$(CC) $(CFLAG) $(IFLAG) -c $< -o $@

endif

###########################################################
#                                                         #
# Linux : #################################################
#                                                         #
###########################################################

ifeq ($(shell uname), Linux)

# COMPILATION #############################################

CC = clang
CFLAG = -Wall -Wextra -Werror
IFLAGS_LINUX = -I./inc -I./libft/libft_linux/inc -I./mlx/mlx_linux
LFLAG_LINUX = -L./mlx/mlx_linux -lmlx_Linux -lXext -lX11 -lm

# DIRECTORY ###############################################

BUILD 	:= .build
INC_DIR := inc
SRC_DIR := src
SUB_DIR := engine \
		   events \
		   init_utils \
		   parser_map \
		   parser_map_file
LFT_DIR_LINUX = libft/libft_linux
MLX_DIR_LINUX := mlx/mlx_linux
OBJ_DIR := $(BUILD)/obj
DIRS	:= $(OBJ_DIR) $(addprefix $(OBJ_DIR)/, $(SUB_DIR))

# FILE ####################################################

NAME  	:= Cub3d
LIBFT 	:= libft.a
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

# COLORS ##################################################

DEFAULT_COLOR	= \033[0m
BLACK_COLOR		= \033[1;30m
RED_COLOR		= \033[1;31m
GREEN_COLOR		= \033[1;32m
YELLOW_COLOR	= \033[1;33m
BLUE_COLOR		= \033[1;34m
MAGENTA_COLOR 	= \033[1;35m
CYAN_COLOR 		= \033[1;36m
WHITE_COLOR 	= \033[1;107m

# Makefile ################################################

$(NAME): $(OBJ)
	$(MAKE) -C $(LFT_DIR_LINUX)
	$(MAKE) -C $(MLX_DIR_LINUX)
	cp ./$(LFT_DIR_LINUX)/$(LIBFT) .
	cp ./$(MLX_DIR_LINUX)/$(MLX_LINUX) .
	$(CC) $(CFLAG) $(IFLAGS_LINUX) $^ -o $@ $(LFLAG_LINUX) $(LIBFT) $(MLX_LINUX)

all: $(NAME)

clean:
	$(MAKE) -C $(LFT_DIR_LINUX) clean
	$(MAKE) -C $(MLX_DIR_LINUX) clean
	rm -rf $(BUILD)

fclean: clean
	$(MAKE) -C $(LFT_DIR_LINUX) fclean
	rm -rf $(NAME) $(LIBFT) $(MLX_LINUX)

re: fclean all

.PHONY: all clean fclean re
	
$(BUILD):
	mkdir $@ $(DIRS)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c | $(BUILD)
	$(CC) $(CFLAG) $(IFLAGS_LINUX) -c $< -o $@

endif

###########################################################