NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_max.c ft_abs.c ft_log.c ft_swap_numbers.c ft_atol.c ft_strcmp.c
BONUS_SRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c ft_lstcpy_bonus.c \
		ft_lstrm_node_bonus.c

GNL_SRC = get_next_line.c

PRINTF_SRC = ft_printf.c ft_putargs.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
GNL_OBJ = $(GNL_SRC:.c=.o)
PRINTF_OBJ = $(PRINTF_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(BONUS_OBJ)
	@if [ ! -f .bonus ]; then \
	    touch .bonus; \
	    ar rcs $(NAME) $(BONUS_OBJ); \
	fi

gnl: $(GNL_OBJ)
	@if [ ! -f .gnl ]; then \
	    touch .gnl; \
	    ar rcs $(NAME) $(GNL_OBJ); \
	fi

printf: $(PRINTF_OBJ)
	@if [ ! -f .printf ]; then \
	    touch .printf; \
	    ar rcs $(NAME) $(PRINTF_OBJ); \
	fi

complete: all bonus gnl printf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f .gnl
	rm -f .bonus
	rm -f .printf
	rm -f $(OBJ) $(BONUS_OBJ) $(GNL_OBJ) $(PRINTF_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re gnl printf bonus complete
