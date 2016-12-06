# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aphan <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/13 14:10:34 by aphan             #+#    #+#              #
#    Updated: 2016/11/22 23:39:10 by aphan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

INC = includes/

LIBFT_INC = libft/includes/

LIBFT = libft/libft.a

MLX = minilibx_macos/

SRC_DIR = src/

SRC =		fdf.c fdf_color.c fdf_fieldkey.c fdf_movement.c fdf_pntcxt.c

OBJ_DIR = build/

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
			cd libft && $(MAKE) all
			cd minilibx_macos && $(MAKE) all
			@mkdir -p $(OBJ_DIR)
			@$(CC) $(CFLAGS) -c $(addprefix $(SRC_DIR), $(SRC))	-I$(INC) \
				-I$(LIBFT_INC) -I$(MLX)
			@mv $(OBJ) build/
			$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME) -I$(LIBFT_INC) $(LIBFT) \
				-I$(MLX) -L$(MLX) -I$(INC) $(addprefix build/, $(OBJ))
			@echo 'compile fdf'

clean:
			cd libft && $(MAKE) clean
			cd minilibx_macos && $(MAKE) clean
			@/bin/rm -f $(addprefix build/, $(OBJ))
			@echo 'clean objects'

fclean:		clean
			cd libft && $(MAKE) fclean
			cd minilibx_macos && $(MAKE) clean
			@/bin/rm -f $(NAME)
			@echo 'clean fdf'

re:	fclean all

.PHONY: all clean fclean re
