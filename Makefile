# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tanukool <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/13 04:05:43 by tanukool          #+#    #+#              #
#    Updated: 2022/08/13 05:14:58 by tanukool         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -I.

HEADER = stack.h
SRC = stack.c
OBJ = $(SRC:%.c=%.o)

NAME = push_swap

LEAKS = leaks --atExit -- 

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

t: norm test

test: $(OBJ) test.o
	@$(CC) $(CFLAGS) $^ -o $@ && ./$@ && $(LEAKS) ./$@ 2> /dev/null | grep 'leak' && rm -f $^ $@

norm:
	norminette $(SRC) $(HEADER)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test norm
