NAME        = push_swap
NAME_BONUS  = checker

INC_DIR     = include
LIBFT_DIR   = libft
SRC_DIR     = src
OBJ_DIR     = obj

SRC_COMMON_FILES = parser.c push.c swap.c rotate.c reverse_rotate.c utils.c
SRC_MANDATORY_FILES   = push_swap.c a_to_b.c b_to_a.c align_a.c
SRC_BONUS_FILES  = checker_bonus.c

SRC       = $(addprefix $(SRC_DIR)/, $(SRC_MANDATORY_FILES) $(SRC_COMMON_FILES))
SRC_BONUS = $(addprefix $(SRC_DIR)/, $(SRC_BONUS_FILES) $(SRC_COMMON_FILES))

OBJ       = $(addprefix $(OBJ_DIR)/, $(SRC_MANDATORY_FILES:.c=.o) $(SRC_COMMON_FILES:.c=.o))
OBJ_BONUS = $(addprefix $(OBJ_DIR)/, $(SRC_BONUS_FILES:.c=.o) $(SRC_COMMON_FILES:.c=.o))

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -I $(INC_DIR) -I $(LIBFT_DIR)
LIBFTA  = -L $(LIBFT_DIR) -lft

RED     = \033[0;31m
GREEN   = \033[0;32m
YELLOW  = \033[0;33m
CYAN    = \033[0;36m
MAGENTA = \033[0;35m
RESET   = \033[0m

all: $(NAME)
	@echo "$(GREEN)Proyecto $(NAME) compilado correctamente.$(RESET)"

$(NAME): $(OBJ)
	@echo "$(MAGENTA)Compilando libft...$(RESET)"
	$(MAKE) complete -C $(LIBFT_DIR)
	@echo "$(CYAN)Linkeando $(NAME)...$(RESET)"
	$(CC) $(OBJ) $(CFLAGS) $(LIBFTA) -o $(NAME)
	@echo "$(GREEN)$(NAME) generado.$(RESET)"

bonus: $(NAME_BONUS)
	@echo "$(GREEN)Proyecto $(NAME_BONUS) compilado correctamente.$(RESET)"

$(NAME_BONUS): $(OBJ_BONUS)
	@echo "$(MAGENTA)Compilando libft...$(RESET)"
	$(MAKE) complete -C $(LIBFT_DIR)
	@echo "$(CYAN)Linkeando $(NAME_BONUS)...$(RESET)"
	$(CC) $(OBJ_BONUS) $(CFLAGS) $(LIBFTA) -o $(NAME_BONUS)
	@echo "$(GREEN)$(NAME_BONUS) generado.$(RESET)"

$(OBJ_DIR):
	@echo "$(YELLOW)Creando directorio de objetos $(OBJ_DIR)...$(RESET)"
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compilando $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Limpiando archivos objeto...$(RESET)"
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(RED)Archivos objeto eliminados.$(RESET)"

fclean: clean
	@echo  "$(RED)Eliminando ejecutables...$(RESET)"
	rm -f $(NAME) $(NAME_BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(RED)Ejecutables eliminados.$(RESET)"

re: fclean all

both: all bonus

.PHONY: all bonus clean fclean re both
