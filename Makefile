NAME        = push_swap
NAME_BONUS  = checker

INC_DIR     = include
LIBFT_DIR   = libft
SRC_DIR     = src
OBJ_DIR     = obj

SRC_FILES       = push_swap.c parser.c a_to_b.c b_to_a.c align_a.c push.c swap.c rotate.c reverse_rotate.c utils.c
SRC_BONUS_FILES = checker_bonus.c parser.c push.c swap.c rotate.c reverse_rotate.c utils.c

SRC       = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
SRC_BONUS = $(addprefix $(SRC_DIR)/, $(SRC_BONUS_FILES))

OBJ       = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
OBJ_BONUS = $(addprefix $(OBJ_DIR)/, $(SRC_BONUS_FILES:.c=.o))

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -I $(INC_DIR) -I $(LIBFT_DIR)
SANITIZER_FLAGS = -g3 -fsanitize=address -fsanitize=undefined
LIBFTA  = -L $(LIBFT_DIR) -lft

RED     = \033[0;31m
GREEN   = \033[0;32m
YELLOW  = \033[0;33m
CYAN    = \033[0;36m
MAGENTA = \033[0;35m
RESET   = \033[0m

all: $(NAME)
	@echo -e "$(GREEN)Proyecto $(NAME) compilado correctamente.$(RESET)"

$(NAME): $(OBJ)
	@echo -e "$(MAGENTA)Compilando libft...$(RESET)"
	$(MAKE) complete -C $(LIBFT_DIR)
	@echo -e "$(CYAN)Linkeando $(NAME)...$(RESET)"
	$(CC) $(OBJ) $(CFLAGS) $(LIBFTA) -o $(NAME)
	@echo -e "$(GREEN)$(NAME) generado.$(RESET)"

bonus: $(NAME_BONUS)
	@echo -e "$(GREEN)Proyecto $(NAME_BONUS) compilado correctamente.$(RESET)"

$(NAME_BONUS): $(OBJ_BONUS)
	@echo -e "$(MAGENTA)Compilando libft...$(RESET)"
	$(MAKE) complete -C $(LIBFT_DIR)
	@echo -e "$(CYAN)Linkeando $(NAME_BONUS)...$(RESET)"
	$(CC) $(OBJ_BONUS) $(CFLAGS) $(LIBFTA) -o $(NAME_BONUS)
	@echo -e "$(GREEN)$(NAME_BONUS) generado.$(RESET)"

$(OBJ_DIR):
	@echo -e "$(YELLOW)Creando directorio de objetos $(OBJ_DIR)...$(RESET)"
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo -e "$(YELLOW)Compilando $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo -e "$(RED)Limpiando archivos objeto...$(RESET)"
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	@echo -e "$(RED)Archivos objeto eliminados.$(RESET)"

fclean: clean
	@echo -e "$(RED)Eliminando ejecutables...$(RESET)"
	rm -f $(NAME) $(NAME_BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean
	@echo -e "$(RED)Ejecutables eliminados.$(RESET)"

re: fclean all

check: CFLAGS += $(SANITIZER_FLAGS)
check: fclean all
	@echo -e "$(CYAN)Ejecutando norminette...$(RESET)"
	norminette $(INC_DIR) $(SRC_DIR) $(LIBFT_DIR)

.PHONY: clean fclean re check
