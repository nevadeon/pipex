# ============================================================================ #
#        ANSI color codes                                                      #
# ============================================================================ #

GREEN := \033[0;32m
YELLOW := \033[0;33m

BOLD_GREEN := \033[1;32m
BOLD_YELLOW := \033[1;33m

RESET := \033[0m
CLEAR_LINE := \033[K

# ============================================================================ #
#        Makefile                                                              #
# ============================================================================ #

NAME := libndav.a

CC := cc
CFLAGS = -Wall -Werror -Wextra -Iinclude

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

test: CFLAGS += -g
test: all

# ============================================================================ #
#        Message rules                                                         #
# ============================================================================ #

msg_comp:
	@printf "$(YELLOW)Compiling libndav... [$(CFLAGS)]\n$(RESET)"

msg_clean:
	@printf "$(YELLOW)Removing lib object files...\n$(RESET)"

msg_fclean:
	@printf "$(YELLOW)Removing libndav...\n$(RESET)"

.PHONY: all clean fclean re test msg_comp msg_clean msg_fclean
