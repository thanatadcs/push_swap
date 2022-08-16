# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tanukool <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/13 04:05:43 by tanukool          #+#    #+#              #
#    Updated: 2022/08/17 02:31:47 by tanukool         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = "\033[0;32m"
RED = "\033[0;31m"
RESET = "\033[0m"

CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(INCS_DIR) -I$(LIBFT_DIR)

INCS_DIR = .
HEADER = stack.h push_swap.h

SRC = main.c stack1.c stack2.c push_swap.c push_swap_utils1.c push_swap_utils2.c push_swap_utils3.c
OBJ = $(SRC:%.c=%.o)

SRC_TEST = test.c stack1.c stack2.c push_swap.c push_swap_utils1.c push_swap_utils2.c push_swap_utils3.c
OBJ_TEST = $(SRC_TEST:%.c=%.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

NAME = push_swap

LEAKS = leaks --atExit -- 

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -L$(LIBFT_DIR) -lft $^ -o $@

t: norm test

test: $(OBJ_TEST) $(LIBFT)
	$(CC) $(CFLAGS) -L$(LIBFT_DIR) -lft $^ -o $@ && ./$@ && $(LEAKS) ./$@ 2> /dev/null | grep 'leak' && rm -f $^ $@

$(LIBFT):
	make -C $(LIBFT_DIR)

norm:
	norminette $(SRC) $(HEADER) $(LIBFT_DIR)/*.c $(LIBFT_DIR)/*.h 1> /dev/null && echo NORM: $(GREEN)PASS$(RESET) || echo NORM: $(RED)FAIL$(RESET) && norminette $(SRC) $(HEADER) $(LIBFT_DIR)/*.c $(LIBFT_DIR)/*.h | awk '/Error/'

clean:
	make fclean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test norm t
