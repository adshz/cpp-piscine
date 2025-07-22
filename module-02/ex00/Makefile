NAME	= fixed

CC		= c++
CFLAGS	= -Werror -Wextra -Wall -std=c++98

SRCS	= main.cpp Fixed.cpp
OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@


$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "BUILD DONE"

clean:
	@rm -rf $(OBJS)
	@echo "OBJECT REMOVED"

fclean: clean
	@rm -f $(NAME)
	@echo "EVERYTHING CLEAR"
	@echo "=====PROJECT RESET======"
	@echo ""

# Remake
re: fclean all

.PHONY: all re clean fclean