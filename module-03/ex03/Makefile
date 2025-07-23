NAME	= trap

CC		= c++
CFLAGS	= -Werror -Wextra -Wall -g -std=c++98
SRC		= $(wildcard *.cpp)
OBJS	= $(SRC:%.cpp=%.o)

all: $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@ $(INC)
	@echo "BUILD DONE"

clean:
	@rm -rf $(OBJS)
	@echo "OBJECT REMOVED"

fclean: clean
	@rm -f $(NAME)
	@echo "EVERYTHING CLEAR"
	@echo "====PROJECT RESET===="
	@echo ""

re: fclean all

.PHONY: all re clean fclean