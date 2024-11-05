# ============================================================================ #
#        Codes de couleur ANSI                                                 #
# ============================================================================ #

BLACK := \033[0;30m
RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
BLUE := \033[0;34m
MAGENTA := \033[0;35m
CYAN := \033[0;36m
WHITE := \033[0;37m

# Couleurs ANSI en gras
BOLD_BLACK := \033[1;30m
BOLD_RED := \033[1;31m
BOLD_GREEN := \033[1;32m
BOLD_YELLOW := \033[1;33m
BOLD_BLUE := \033[1;34m
BOLD_MAGENTA := \033[1;35m
BOLD_CYAN := \033[1;36m
BOLD_WHITE := \033[1;37m

# Couleurs d'arriere-plan
BG_BLACK := \033[40m
BG_RED := \033[41m
BG_GREEN := \033[42m
BG_YELLOW := \033[43m
BG_BLUE := \033[44m
BG_MAGENTA := \033[45m
BG_CYAN := \033[46m
BG_WHITE := \033[47m

RESET := \033[0m
CLEAR_LINE := \033[K

# ============================================================================ #
#        Makefile                                                              #
# ============================================================================ #

NAME := libndav.a

CC := cc
CFLAGS := -Wall -Werror -Wextra -Iinclude -g

SRC_DIR := src
OBJ_DIR := obj

SRC := $(shell find $(SRC_DIR) -type f -name "*.c")
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): msg_comp $(OBJ)
	@ar rcs $@ $(OBJ)
	@printf "$(GREEN)✔ Libndav created.\n$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $<

clean: msg_clean
	@rm -rf $(OBJ_DIR)

fclean: clean msg_fclean
	@rm -rf $(NAME)

re: fclean all

test:

# ============================================================================ #
#        Message rules                                                         #
# ============================================================================ #

msg_comp:
	@printf "$(YELLOW)🔧 Compiling libndav... [$(CFLAGS)]\n$(RESET)"

msg_clean:
	@printf "$(YELLOW)🗑️ Removing lib object files...\n$(RESET)"

msg_fclean:
	@printf "$(YELLOW)🗑️ Removing libndav...\n$(RESET)"

.PHONY: all clean fclean re test msg_comp msg_clean msg_fclean
