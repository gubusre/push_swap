NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude

SRC_DIR = src
LIBFT_DIR = libft
OBJ_DIR = obj
INCLUDE_DIR = include

SRCS = $(SRC_DIR)/main.c \
		$(SRC_DIR)/ft_check.c \
		$(SRC_DIR)/ft_sort.c \
		$(SRC_DIR)/ft_print_ps.c \
		$(SRC_DIR)/ft_print_rps.c
LIBFT_SRCS = $(LIBFT_DIR)/ft_atoi.c 

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/src_%.o)
LIBFT_OBJS = $(LIBFT_SRCS:$(LIBFT_DIR)/%.c=$(OBJ_DIR)/libft_%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_OBJS)
	$(CC) $(OBJS) $(LIBFT_OBJS) -o $(NAME)

$(OBJ_DIR)/src_%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/libft_%.o: $(LIBFT_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -rf $(OBJ_DIR)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
