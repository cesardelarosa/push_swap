NAME = push_swap
NAME_BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror  -g3 -fsanitize=address -fsanitize=undefined -I include -I libft

SRC_DIR = src
SRC_BONUS_DIR = src_bonus

SRC_FILES = push_swap.c ft_lst.c stack_creator.c moves.c utils.c quick_to_b.c turkish_to_a.c
SRC_BONUS_FILES = checker.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
SRC_BONUS = $(addprefix $(SRC_BONUS_DIR)/, $(SRC_BONUS_FILES))

LIBFTA = -L./libft -lft

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
OBJ_BONUS = $(addprefix $(OBJ_DIR)/, $(SRC_BONUS_FILES:.c=.o))

RM = rm -rf

all: $(NAME)

bonus:$(NAME_BONUS)

lft:
	make complete -C ./libft
	
$(NAME): lft $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(LIBFTA) -o $(NAME)

$(NAME_BONUS): lft $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFTA) -o $(NAME_BONUS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_BONUS_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)
	make -C libft clean

fclean: clean
	$(RM) $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re bonus e make_libft
