# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aphan <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/22 13:26:36 by aphan             #+#    #+#              #
#    Updated: 2016/11/22 23:15:29 by aphan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INC = includes/

SRC_DIR = src/

SRC =	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
		ft_memcpy.c ft_memmove.c ft_memset.c ft_strcat.c ft_strchr.c \
		ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strlcat.c ft_strlen.c \
		ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnstr.c ft_strrchr.c \
		ft_strstr.c ft_tolower.c ft_toupper.c ft_memalloc.c ft_memdel.c \
		ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
		ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
		ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_putchar.c ft_putstr.c \
		ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c 	 ft_itoa.c ft_lstnew.c ft_lstdelone.c \
		ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
		ft_itoa_base.c ft_atoi_base.c ft_strndup.c ft_split_whitespaces.c \
		ft_print_memory.c ft_islower.c ft_isupper.c ft_isnumber.c ft_isblank.c \
		ft_strtrimc.c ft_strlcpy.c ft_atol.c ft_strrealloc.c ft_power.c \
		get_next_line.c ft_intswap.c ft_lstdup.c ft_lstclr.c

PRINTF_DIR =	src/ft_printf/

PRINTF_SRC = 	ft_printf.c pf_parse.c pf_ismodifier.c pf_s.c pf_d.c pf_u.c \
				pf_p.c pf_o.c pf_x.c pf_c.c pf_b.c

OBJ_DIR = build/

OBJ =	$(SRC:.c=.o) $(PRINTF_SRC:.c=.o) 

all: $(NAME)

$(NAME):
		@$(CC) $(CFLAGS) -c $(addprefix $(SRC_DIR), $(SRC)) \
			$(addprefix $(PRINTF_DIR), $(PRINTF_SRC)) -I$(INC)
		@ar rc $(NAME) $(OBJ)
		ranlib $(NAME)
		@echo 'compile'

clean:
		@/bin/rm -f $(OBJ)
		@echo 'clean objects'

fclean: clean
		@/bin/rm -f $(NAME) 
		@echo 'clean library'

re: fclean all

.PHONY: all clean fclean re
