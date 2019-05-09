# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jepoujol <jepoujol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/07 15:20:38 by jepoujol          #+#    #+#              #
#    Updated: 2019/05/09 15:07:53 by jepoujol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

PATH_SRC = ./src/
PATH_OBJ = ./obj/

SRC_NAME = main.c \
			fillit.c \
			ft_checkfile.c \
			ft_nbdiese_valide.c \
			ft_getnblink.c \
			ft_nbtetri.c \
			ft_print_tetri.c \
			ft_print_map.c \
			ft_print_coor.c \
			ft_free_map.c \
			ft_parsing.c \
			ft_gen_map.c \
			ft_topleftcorner.c \
			ft_ispace.c \
			ft_addtetri.c \
			ft_init_coor.c \
			ft_resolve.c \

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(PATH_SRC),$(SRC_NAME))
OBJ = $(addprefix $(PATH_OBJ),$(OBJ_NAME))

HEADER = -I ./libft.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I includes
LDFLAGS = -Llibft
LDLIBS = -lft

$(PATH_OBJ)%.o: $(PATH_SRC)%.c
	@mkdir $(PATH_OBJ) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJ)
	@cd libft ; make; cd ..;
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

clean:
	@cd libft ; make clean; cd ..;
	@rm -fv $(OBJ)
	@rmdir $(PATH_OBJ) 2> /dev/null || true
	@echo "fillit objects clean"

fclean: clean
	@cd libft; make fclean; cd ..;
	@rm -fv $(NAME)
	@echo "fillit fclean"

re: fclean all

.PHONY: all clean fclean re
