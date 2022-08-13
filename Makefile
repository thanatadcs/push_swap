# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tanukool <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/13 04:05:43 by tanukool          #+#    #+#              #
#    Updated: 2022/08/14 01:05:27 by tanukool         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

INCS_DIR = .
HEADER = stack.h push_swap.h

SRC = stack.c push_swap_ops.c
OBJ = $(SRC:%.c=%.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

NAME = push_swap

LEAKS = leaks --atExit -- 

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

t: norm test

test: $(OBJ) test.o $(LIBFT)
	@$(CC) $(CFLAGS) -I$(INCS_DIR) -I$(LIBFT_DIR) -L$(LIBFT_DIR) -lft $^ -o $@ && ./$@ && $(LEAKS) ./$@ 2> /dev/null | grep 'leak' && rm -f $^ $@

$(LIBFT):
	make -C $(LIBFT_DIR)

norm:
	norminette $(SRC) $(HEADER) $(LIBFT_DIR)/*.c $(LIBFT_DIR)/*.h
clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test norm t
