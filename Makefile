NAME = push_swap
NAME_BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address -fsanitize=undefined

SRC_DIR = src
SRC_BONUS_DIR = src_bonus

SRC_FILES = push_swap.c ft_lst.c  prints.c stack_creator.c moves.c utils.c order.c
SRC_BONUS_FILES = checker.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
SRC_BONUS = $(addprefix $(SRC_BONUS_DIR)/, $(SRC_BONUS_FILES))

LIBFTA = -L./libft -lft

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
OBJ_BONUS = $(addprefix $(OBJ_DIR)/, $(SRC_BONUS_FILES:.c=.o))

RM = rm -rf

# Colores
RED = \033[91;1m
GREEN = \033[92;1m
CLEAR = \033[0m

.PHONY: all clean fclean re bonus e make_libft

all: $(NAME)

bonus:$(NAME_BONUS)

make_libft:
	@make -C ./libft
	@echo "$(GREEN)Libft Compiled.$(CLEAR)"
	
$(NAME): $(OBJ)
	@make -C ./libft
	@echo "$(GREEN)Libft Compiled.$(CLEAR)"
	$(CC) $(OBJ) $(CFLAGS) $(LIBFTA) -o $(NAME)
	@echo "$(GREEN)Push Swap Compiled.$(CLEAR)"

$(NAME_BONUS): $(OBJ_BONUS)
	@make -C ./libft
	$(CC) $(OBJ_BONUS) $(CFLAGS) $(LIBFTA) -o $(NAME_BONUS)
	@echo "$(GREEN)Checker Compiled.$(CLEAR)"

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) -c $< -o $@ $(CFLAGS) -I. -I./libft

$(OBJ_DIR)/%.o: $(SRC_BONUS_DIR)/%.c | $(OBJ_DIR)
	$(CC) -c $< -o $@ $(CFLAGS) -I. -I./libft

e: all
	@echo "Running $(NAME) with test case..."
	./$(NAME) "         2" '1'     3 6 5 8 7 -1 4 9 0 3

ec: fclean e

clean:
	$(RM) $(OBJ_DIR)
	@make -C libft clean
	@echo "$(RED)Objects cleaned.$(CLEAR)"

fclean: clean
	$(RM) $(NAME)
	@make -C libft fclean
	@echo "$(RED)$(NAME) and libft cleaned.$(CLEAR)"

re: fclean all
