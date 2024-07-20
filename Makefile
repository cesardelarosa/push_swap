NAME = push_swap
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I include
SRC_DIR = src
OBJ_DIR = obj
SRC = $(SRC_DIR)/main.c $(SRC_DIR)/operations.c $(SRC_DIR)/order.c $(SRC_DIR)/utils.c
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	$(MAKE) -C libft
	$(MAKE) -C libft bonus

$(PRINTF):
	$(MAKE) -C ft_printf

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C libft clean
	$(MAKE) -C ft_printf clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean
	$(MAKE) -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re

