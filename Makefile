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

$(NAME): $(OBJ) $(LIB_DIR)/$(LIB)
	@echo -e "\033[33m🔧 Compiling pipex...\033[0m"
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)
	@echo -e "\033[32m✔ Pipex created.\033[37m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $< $(LIB_INC)

$(LIB_DIR)/$(LIB):
	@echo -e "\033[33m🔧 Compiling library...\033[0m"
	@make -s -C $(LIB_DIR)

clean:
	@echo -e "\033[31m🗑️ Removing object files...\033[0m"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo -e "\033[31m🗑️ Removing pipex...\033[0m"
	@rm -rf $(NAME)

lclean:
	@make -s -C $(LIB_DIR) fclean

re: fclean all

test:

.PHONY: all clean fclean lclean re test
