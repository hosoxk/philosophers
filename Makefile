NAME = philo
CC = cc
CFLAGS = -g3 -Wall -Werror -Wextra
MAKEFLAGS += -s

SRC_DIR = ./sources
LIBFT_DIR = ./sources/libft

SRC_FILES = $(SRC_DIR)/main.c \
		$(SRC_DIR)/parsing.c \
		$(SRC_DIR)/utils.c \
		$(SRC_DIR)/safe_functions.c \
		$(SRC_DIR)/init.c

OBJ_FILES = $(SRC_FILES:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a

YELLOW = \033[1;33m
GREEN = \033[1;32m
RESET = \033[0m

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT)
	@echo "$(YELLOW)Linking $(NAME) to $(OBJ_FILES)...$(RESET)"
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)Compilation $(NAME) successfull!$(RESET)"

%.o: %.c
	@echo "$(YELLOW)Compiling $(notdir $<)...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@echo "$(YELLOW)Building libft...$(RESET)"
	$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN)Libft compiled succesfully!$(RESET)"

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	rm -fr $(OBJ_FILES)
	$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(GREEN)Object files cleaned!$(RESET)"

fclean: clean
	@echo "$(YELLOW)Removing $(NAME) executable...$(RESET)"
	rm -fr $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)Executable $(NAME) removed!$(RESET)"

re: fclean all

.PHONY: all clean fclean re
