NAME = push_swap
NAME_BONUS = checker

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
CYAN=\033[0;36m
MAGENTA=\033[0;35m
RESET=\033[0m

INC_DIR = include 
LIBFT_DIR = libft
SRC_DIR = src

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR) -I $(LIBFT_DIR)
SANITIZER_FLAGS = -g3 -fsanitize=address -fsanitize=undefined

SRC_FILES = push_swap.c parser.c a_to_b.c b_to_a.c moves/push.c moves/swap.c moves/rotate.c moves/reverse_rotate.c utils.c
SRC_BONUS_FILES = bonus/checker.c parser.c moves/push.c moves/swap.c moves/rotate.c moves/reverse_rotate.c utils.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
SRC_BONUS = $(addprefix $(SRC_DIR)/, $(SRC_BONUS_FILES))

LIBFTA = -L $(LIBFT_DIR) -lft

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
OBJ_BONUS = $(addprefix $(OBJ_DIR)/, $(SRC_BONUS_FILES:.c=.o))

RM = rm -rf

all: $(NAME)
	@echo -e "$(GREEN)Proyecto $(NAME) compilado correctamente.$(RESET)"

$(NAME): lft $(OBJ)
	@echo -e "$(GREEN)Linkeando $(NAME)...$(RESET)"
	$(CC) $(OBJ) $(CFLAGS) $(LIBFTA) $(if $(findstring $(SANITIZER_FLAGS),$(CFLAGS)),$(SANITIZER_FLAGS),) -o $(NAME)
	@echo -e "$(GREEN)$(NAME) generado.$(RESET)"

bonus: $(NAME_BONUS)
	@echo -e "$(GREEN)Proyecto $(NAME_BONUS) compilado correctamente.$(RESET)"

$(NAME_BONUS): lft $(OBJ_BONUS)
	@echo -e "$(GREEN)Linkeando $(NAME_BONUS)...$(RESET)"
	$(CC) $(OBJ_BONUS) $(CFLAGS) $(LIBFTA) $(if $(findstring $(SANITIZER_FLAGS),$(CFLAGS)),$(SANITIZER_FLAGS),) -o $(NAME_BONUS)
	@echo -e "$(GREEN)$(NAME_BONUS) generado.$(RESET)"

lft:
	@echo -e "$(CYAN)Compilando libft...$(RESET)"
	$(MAKE) complete -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)/moves
	mkdir -p $(OBJ_DIR)/bonus
	@echo -e "$(CYAN)Directorio $(OBJ_DIR) creado.$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo -e "$(YELLOW)Compilando $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo -e "$(RED)Limpiando archivos objeto...$(RESET)"
	$(RM) $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	@echo -e "$(RED)Archivos objeto eliminados.$(RESET)"

fclean: clean
	@echo -e "$(RED)Eliminando ejecutables...$(RESET)"
	$(RM) $(NAME) $(NAME_BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean
	@echo -e "$(RED)Ejecutables eliminados.$(RESET)"

re: fclean all

#check: CFLAGS += $(SANITIZER_FLAGS)
#check: re
#	@echo -e "$(MAGENTA)Ejecutando norminette...$(RESET)"
#	norminette $(INC_DIR) $(SRC_DIR)

.PHONY: all bonus clean fclean re lft check
