NAME = libndav.a

CC = cc
FLAGS = -Wall -Werror -Wextra -I include

SRC_DIR = src
OBJ_DIR = obj

SRC = $(shell find $(SRC_DIR) -type f -name "*.c")
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $(OBJ)
	@echo -e "\033[32m✔ Libndav created.\033[37m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test:

.PHONY: all clean fclean re test
