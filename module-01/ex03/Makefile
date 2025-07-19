NAME	= violence

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 

SRCS = \
		main.cpp \
		HumanA.cpp \
		HumanB.cpp \
		Weapon.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o:%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "BUILD FINISH"

clean:
	@rm -rf $(OBJS)
	@echo "OBJECT REMOVED"

fclean: clean
	@rm -rf $(NAME)
	@echo "ALL CLEAR"
	@echo "==========PROJECT RESET=========="
	@echo ""

re: fclean all

.PHONY: all re fclean clean 
