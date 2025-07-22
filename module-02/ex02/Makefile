# Program name
NAME	= fixed

# Compiler
CC		= c++
CFLAGS	= -Werror -Wextra -Wall -std=c++98

# Files
SRCS	= main.cpp Fixed.cpp
OBJS	= $(SRCS:.cpp=.o)
INC		= -I ./

# Build rule
all: $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

# Program build rule
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@ $(INC)
	@echo "BUILD DONE"

# Clean rules

clean:
	@rm -rf $(OBJS)
	@echo "OBJECT REMOVE"

fclean: clean
	@rm -f $(NAME)
	@echo "EVERYTHING CLEAR"
	@echo "====PROJECT RESET====="
	@echo ""

# Remake
re: fclean all

.PHONY: all re clean fclean