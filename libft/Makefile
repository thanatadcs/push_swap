# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tanukool <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/01 14:58:23 by tanukool          #+#    #+#              #
#    Updated: 2022/06/08 18:33:24 by tanukool         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -I.

NAME = libft.a

SRCS = ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_striteri.c ft_strmapi.c ft_itoa.c ft_split.c ft_strtrim.c ft_strjoin.c ft_substr.c ft_strdup.c ft_calloc.c ft_atoi.c ft_strnstr.c ft_strlcat.c ft_strlcpy.c ft_memcmp.c ft_memchr.c ft_strncmp.c ft_strrchr.c ft_strchr.c ft_memmove.c ft_memcpy.c ft_bzero.c ft_memset.c ft_tolower.c ft_toupper.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_isalpha.c ft_isdigit.c ft_strlen.c
OBJS = $(patsubst %.c, %.o, $(SRCS))

BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
BONUS_OBJS = $(patsubst %.c, %.o, $(BONUS_SRCS))
 
all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(BONUS_OBJS)
	ar -rcs $(NAME) $^

.PHONY: bonus all clean fclean re
