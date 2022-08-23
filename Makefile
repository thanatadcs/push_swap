# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tanukool <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/13 04:05:43 by tanukool          #+#    #+#              #
#    Updated: 2022/08/23 10:19:58 by tanukool         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = "\033[0;32m"
RED = "\033[0;31m"
RESET = "\033[0m"

CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(INCS_DIR) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR)

INCS_DIR = .
HEADER = stack.h push_swap.h

SRC = main.c stack1.c stack2.c push_swap.c push_swap_utils1.c push_swap_utils2.c push_swap_utils3.c push_swap_utils4.c push_swap_utils5.c
OBJ = $(SRC:%.c=%.o)

SRC_TEST = test.c stack1.c stack2.c push_swap.c push_swap_utils1.c push_swap_utils2.c push_swap_utils3.c push_swap_utils4.c push_swap_utils5.c
OBJ_TEST = $(SRC_TEST:%.c=%.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = ./ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

NAME = push_swap

LEAKS = leaks --atExit -- 

all: norm $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf $^ -o $@

t: norm test

test: $(OBJ_TEST) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf $^ -o $@ && ./$@ && $(LEAKS) ./$@ 2> /dev/null | grep 'leak' && rm -f $^ $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

norm:
	norminette $(SRC) $(HEADER) $(LIBFT_DIR)/*.c $(LIBFT_DIR)/*.h 1> /dev/null && echo NORM: $(GREEN)PASS$(RESET) || echo NORM: $(RED)FAIL$(RESET) && norminette $(SRC) $(HEADER) $(LIBFT_DIR)/*.c $(LIBFT_DIR)/*.h | awk '/Error/'

clean:
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(FT_PRINTF_DIR)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test norm t
