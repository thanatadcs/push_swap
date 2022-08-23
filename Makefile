# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tanukool <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/13 04:05:43 by tanukool          #+#    #+#              #
#    Updated: 2022/08/23 14:39:22 by tanukool         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -I. -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR)

SRC = main.c stack1.c stack2.c push_swap.c push_swap_utils1.c push_swap_utils2.c push_swap_utils3.c push_swap_utils4.c push_swap_utils5.c
OBJ = $(SRC:%.c=%.o)

SRC_BONUS = main_bonus.c checker_bonus.c stack1_bonus.c stack2_bonus.c push_swap_bonus.c push_swap_utils1_bonus.c push_swap_utils2_bonus.c push_swap_utils3_bonus.c push_swap_utils4_bonus.c push_swap_utils5_bonus.c get_next_line.c get_next_line_utils.c
OBJ_BONUS = $(SRC_BONUS:%.c=%.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = ./ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

NAME = push_swap
BNAME = checker 

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf $^ -o $@

bonus: $(BNAME)

$(BNAME): $(OBJ_BONUS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf $^ -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

clean:
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(FT_PRINTF_DIR)
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)
	rm -f $(BNAME)

re: fclean all

.PHONY: all clean fclean re
