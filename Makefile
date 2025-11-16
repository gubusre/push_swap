# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gubusque <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/16 18:50:00 by gubusque        #+#    #+#                #
#    Updated: 2025/11/16 18:50:47 by gubusque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

# Directorios
SRC_DIR		= src
LIBFT_DIR	= libft
OBJ_DIR		= obj
INC_DIR		= include

# Archivos en src/
SRC_SRCS	= main.c \
			  ft_check.c \
			  ft_sort.c \
			  ft_operations.c

# Archivo en libft/
LIBFT_SRCS	= ft_atoi.c

# Rutas completas
SRC			= $(addprefix $(SRC_DIR)/, $(SRC_SRCS))
LIBFT		= $(addprefix $(LIBFT_DIR)/, $(LIBFT_SRCS))
ALL_SRC		= $(SRC) $(LIBFT)
OBJ			= $(addprefix $(OBJ_DIR)/, $(notdir $(ALL_SRC:.c=.o)))

# Compilador
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INC			= -I$(INC_DIR)

# Reglas
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Compila desde src/ o libft/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR)/%.o: $(LIBFT_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
