NAME = brain

CC = c++
CFLAGS = -Wall -Wextra -Werror 

SRC = main.cpp
OBJ = main.o

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "BUILD FINISH"

$(OBJ): $(SRC)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@echo "OBJECT REMOVED"

fclean: clean
	@rm -rf $(NAME)
	@echo "ALL CLEAR"
	@echo "==========PROJECT RESET=========="
	@echo ""

re: fclean all

.PHONY: all re fclean clean 