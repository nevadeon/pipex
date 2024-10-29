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

RESET := \033[0m		# Retour a la couleur par defaut
CLEAR_LINE := \033[K	# Effacer une ligne

# ============================================================================ #
#        Makefile                                                              #
# ============================================================================ #

NAME = pipex

CC = cc
CFLAGS = -Wall -Werror -Wextra -Iinclude
LDFLAGS = -L$(LIB_DIR) -lndav $(LIB_INC)
LIB_INC = -I$(LIB_DIR)/include

SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = ./libndav

SRC = $(shell find $(SRC_DIR) -type f -name "*.c")
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
LIB = libndav.a

all: $(NAME)

$(NAME): msg_comp $(OBJ) $(LIB_DIR)/$(LIB)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)
	@echo -e "$(GREEN)✔ Pipex created.$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $< $(LIB_INC)

$(LIB_DIR)/$(LIB):
	@make -s -C $(LIB_DIR)

clean: msg_clean
	@rm -rf $(OBJ_DIR)

fclean: clean msg_fclean
	@rm -rf $(NAME)

lclean:
	@make -s -C $(LIB_DIR) fclean

re: fclean all

val: CFLAGS += -g
val: all
	valgrind --leak-cheack=full ./$(NAME)

gdb: CFLAGS += -g
gdb: all
	gdb $(NAME)

# ============================================================================ #
#        Message rules                                                         #
# ============================================================================ #

msg_comp:
	@echo -e "$(YELLOW)🔧 Compiling pipex... [$(CFLAGS)]$(RESET)"

msg_clean:
	@echo -e "$(YELLOW)🗑️ Removing object files...$(RESET)"

msg_fclean:
	@echo -e "$(YELLOW)🗑️ Removing pipex...$(RESET)"

.PHONY: all clean fclean lclean re val gdb msg_comp msg_clean msg_fclean
