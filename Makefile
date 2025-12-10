# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gubusque <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/04 12:02:59 by gubusque          #+#    #+#              #
#    Updated: 2025/12/10 22:54:25 by gubusque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = \
      	bubble_sort.c	   ft_atoi.c	ft_swap.c  ra.c		rrr.c	main.c	\
	check_args.c	   ft_efree.c	pa.c	   rb.c		size3.c		\
	check_num.c	   ft_free.c 	pb.c	   rr.c		size5.c		\
	check_order.c	   ft_index.c	sa.c	   rra.c	push_swap.c	\
	check_same_nums.c  ft_strlen.c	sb.c	   rrb.c	s_push_swap.c	\


OBJ = $(SRC:.c=.o)

INCLUDE = pushswap.h
CC = cc
CCFLAGS = -Wall -Wextra -Werror -Include
RM = rm -f

all: $(NAME) clean

$(NAME): $(OBJ) $(INCLUDE)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

rebonus: fclean all

.PHONY: all clean fclean re
