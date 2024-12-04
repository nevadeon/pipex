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
#        Config variables                                                              #
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

# Sources and objects
SRC := $(shell find $(SRC_DIR) -type f -name "*.c")
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
LIB := libndav.a

# ============================================================================ #
#        Compilation rules                                                     #
# ============================================================================ #

all: $(NAME)

$(NAME): $(LIB_DIR)/$(LIB) msg_comp $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)
	@printf "$(GREEN)✔ Pipex created.\n$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(LIB_HEADER_FLAG) -o $@ -c $<

re: fclean all

# ============================================================================ #
#        Cleaning rules                                                        #
# ============================================================================ #

clean: msg_clean
	@rm -rf $(OBJ_DIR)

fclean: clean msg_fclean
	@rm -rf $(NAME)

# ============================================================================ #
#        Lib managing rules                                                    #
# ============================================================================ #

$(LIB_DIR)/$(LIB):
	@make -s -C $(LIB_DIR)

lclean:
	@make -s -C $(LIB_DIR) fclean

# ============================================================================ #
#        Test rules                                                            #
# ============================================================================ #

val: CFLAGS += -g
val: libtest re
	valgrind --leak-check=full ./$(NAME) infile cat cat outfile

gdb: CFLAGS += -g
gdb: libtest re
	gdb --args ./$(NAME) infile catasdsad "grep lucas" outfile

libtest:
	@make -s -C $(LIB_DIR) test

# ============================================================================ #
#        Terminal message rules                                                #
# ============================================================================ #

msg_comp:
	@printf "$(YELLOW)Compiling pipex... [$(CFLAGS)]\n$(RESET)"

msg_clean:
	@printf "$(YELLOW)Removing object files...\n$(RESET)"

msg_fclean:
	@printf "$(YELLOW)Removing pipex...\n$(RESET)"

.PHONY: all clean fclean lclean re val gdb libtest msg_comp msg_clean msg_fclean
