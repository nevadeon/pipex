# ============================================================================ #
#        Codes de couleur ANSI                                                 #
# ============================================================================ #

GREEN := \033[0;32m
YELLOW := \033[0;33m

# Couleurs ANSI en gras
BOLD_GREEN := \033[1;32m
BOLD_YELLOW := \033[1;33m

RESET := \033[0m
CLEAR_LINE := \033[K

# ============================================================================ #
#        Makefile                                                              #
# ============================================================================ #

NAME := pipex

CC := cc

# Directories
SRC_DIR := src
OBJ_DIR := obj
INC_DIR := include
LIB_DIR := libndav
LIB_INC_DIR := include

# Flags
CFLAGS := -Wall -Werror -Wextra -I$(INC_DIR)
LIB_HEADER_FLAG := -I$(LIB_DIR)/$(LIB_INC_DIR)
LDFLAGS := -L$(LIB_DIR) -lndav $(LIB_HEADER_FLAG)

SRC := $(shell find $(SRC_DIR) -type f -name "*.c")
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
LIB := libndav.a

all: $(NAME)

$(NAME): $(LIB_DIR)/$(LIB) msg_comp $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)
	@printf "$(GREEN)✔ Pipex created.\n$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(LIB_HEADER_FLAG) -o $@ -c $<

$(LIB_DIR)/$(LIB):
	@make -s -C $(LIB_DIR)

clean: msg_clean
	@rm -rf $(OBJ_DIR)

fclean: clean msg_fclean
	@rm -rf $(NAME)

lclean:
	@make -s -C $(LIB_DIR) fclean

re: fclean all

# ============================================================================ #
#        Test rules                                                            #
# ============================================================================ #

val: CFLAGS += -g
val: libtest all
	valgrind --leak-check=full ./$(NAME)

gdb: CFLAGS += -g
gdb: libtest all
	gdb $(NAME)

libtest:
	@make -s -C $(LIB_DIR) test

# ============================================================================ #
#        Message rules                                                         #
# ============================================================================ #

msg_comp:
	@printf "$(YELLOW)Compiling pipex... [$(CFLAGS)]\n$(RESET)"

msg_clean:
	@printf "$(YELLOW)Removing object files...\n$(RESET)"

msg_fclean:
	@printf "$(YELLOW)Removing pipex...\n$(RESET)"

.PHONY: all clean fclean lclean re val gdb libtest msg_comp msg_clean msg_fclean
