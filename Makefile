# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/24 17:01:29 by ybouladh          #+#    #+#              #
#    Updated: 2019/07/15 21:45:04 by ybouladh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = ybouladh.filler
FILES = filler.c heat_map.c map.c placable.c token.c
LIB = libft/libft.a
INCLUDE = includes/filler.h
all: $(NAME)

$(NAME):
	make -C libft
	gcc -o $(NAME) -Wall -Werror -Wextra -I$(INCLUDE) $(FILES) $(LIB)

clean:
	/bin/rm -f *.o
	make clean -C libft

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C libft

re : fclean all
