NAME = GBU

CC = c++
CFLAGS = -Werror -Wextra -Wall -std=c++98

SRCS	= Account.cpp tests.cpp
OBJ		=$(SRCS:.cpp=.o)

all: LOAD $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $@ -I .
	@echo "====BUILDING COMPLETE===="
	@echo "Use ./GBU"

LOAD:
	@echo "BUILDING......."

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@ -I .

clean:
	@rm -rf *.o
	@echo "Objects removed"

fclean: clean
	@rm -rf $(NAME)
	@echo "====PROJECT RESET===="
	@echo "---------------------"

re: fclean all


.PHONY: all re clean fclean

