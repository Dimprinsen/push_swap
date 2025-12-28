# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thtinner <thtinner@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/11 02:03:00 by thtinner          #+#    #+#              #
#    Updated: 2025/10/11 02:03:00 by thtinner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft
LIBFT_A = $(LIBFT)/libft.a

SRCS = main.c \
       memory_management.c \
       rotation_cost.c \
       rotation.c \
       sorting.c \
       stack_management.c \
       stack_manipulation.c \
       synchronization.c \
       utility.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT_A):
	make -C $(LIBFT)

$(NAME): $(LIBFT_A) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT) -lft

%.o: %.c
	$(CC) $(CFLAGS) -I. -I$(LIBFT) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
