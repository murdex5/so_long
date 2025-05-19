# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kadferna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/17 10:05:19 by kadferna          #+#    #+#              #
#    Updated: 2025/03/17 10:05:22 by kadferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
SRCS_DIR = ./srcs
SRCS		= ${SRCS_DIR}/utils0.c \
			${SRCS_DIR}/utils1.c \
			${SRCS_DIR}/frees.c \
			${SRCS_DIR}/maps/map_utils.c \
			${SRCS_DIR}/maps/map_utils1.c \
			${SRCS_DIR}/maps/map_utils2.c \
			${SRCS_DIR}/maps/map_frees.c \
			${SRCS_DIR}/maps/map_validation.c \
			${SRCS_DIR}/maps/map_parse.c \
			${SRCS_DIR}/maps/maps.c \
			${SRCS_DIR}/errors.c \
			${SRCS_DIR}/textures/textures.c \
			${SRCS_DIR}/textures/buffer_map.c \
			${SRCS_DIR}/textures/free_textures.c \
			${SRCS_DIR}/animations/animation_utils.c \
			${SRCS_DIR}/animations/free_animations.c \
			${SRCS_DIR}/animations/animation.c \
			${SRCS_DIR}/enemy/enemy_utils.c \
			${SRCS_DIR}/enemy/free_enemy.c \
			${SRCS_DIR}/enemy/enemy.c \
			${SRCS_DIR}/player/free_player.c \
			${SRCS_DIR}/player/player.c \
			${SRCS_DIR}/game/game_utils1.c \
			${SRCS_DIR}/game/game_free.c \
			${SRCS_DIR}/game/game.c \
			${SRCS_DIR}/hooks.c \
			${SRCS_DIR}/main.c
OBJS		= ${SRCS:.c=.o}
CFLAGS		= -Wall -Werror -Wextra 
MLX_DIR		= ./mlx
MLX_LIB		= $(MLX_DIR)/libmlx.a
LIBFT_PATH	= ./libft
LIBFT_LIB = $(LIBFT_PATH)/libft.a
NAME	= so_long

ifeq ($(shell uname), Linux)
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
	MLX_INCLUDES = -I/usr/include -Imlx
else
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
	MLX_INCLUDES = -I/opt/X11/include -Imlx
endif

all: subsystems $(NAME) #clean

%.o : %.c
	$(CC) $(CFLAGS) $(MLX_INCLUDES) -O3 -c -o $@ $<

subsystems:
	@make -C $(MLX_DIR) all
	@make -C $(LIBFT_PATH) all

# pull:
# 	git pull
# 	cd ./mlx && git pull

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	@make -C $(MLX_DIR) clean
	@make -C $(LIBFT_PATH) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re subsystems
