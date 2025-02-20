NAME        = push_swap
NAME_BONUS  = checker

INC_DIR     = include
LIBFT_DIR   = libft
SRC_DIR     = src
BONUS_DIR   = bonus
OBJ_DIR     = obj

SRC_FILES   = push_swap.c a_to_b.c b_to_a.c align_a.c moves.c moves_implementation.c parser.c utils.c
BONUS_FILES = checker_bonus.c moves_implementation_bonus.c parser_bonus.c silent_moves_bonus.c utils_bonus.c

SRC       = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
BONUS     = $(addprefix $(BONUS_DIR)/, $(BONUS_FILES))

OBJ       = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
OBJ_BONUS = $(addprefix $(OBJ_DIR)/, $(BONUS_FILES:.c=.o))

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
	@echo "$(GREEN)Project $(NAME) compiled successfully.$(RESET)"

$(NAME): $(OBJ)
	@echo "$(MAGENTA)Compiling libft...$(RESET)"
	$(MAKE) complete -C $(LIBFT_DIR)
	@echo "$(CYAN)Linking $(NAME)...$(RESET)"
	$(CC) $(OBJ) $(CFLAGS) $(LIBFTA) -o $(NAME)
	@echo "$(GREEN)$(NAME) generated.$(RESET)"

bonus: $(NAME_BONUS)
	@echo "$(GREEN)Project $(NAME_BONUS) compiled successfully.$(RESET)"

$(NAME_BONUS): $(OBJ_BONUS)
	@echo "$(MAGENTA)Compiling libft...$(RESET)"
	$(MAKE) complete -C $(LIBFT_DIR)
	@echo "$(CYAN)Linking $(NAME_BONUS)...$(RESET)"
	$(CC) $(OBJ_BONUS) $(CFLAGS) $(LIBFTA) -o $(NAME_BONUS)
	@echo "$(GREEN)$(NAME_BONUS) generated.$(RESET)"

$(OBJ_DIR):
	@echo "$(YELLOW)Creating objects directory $(OBJ_DIR)...$(RESET)"
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(RED)Object files removed.$(RESET)"

fclean: clean
	@echo "$(RED)Removing executables...$(RESET)"
	rm -f $(NAME) $(NAME_BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(RED)Executables removed.$(RESET)"

re: fclean all

both: all bonus

.PHONY: all bonus clean fclean re both
