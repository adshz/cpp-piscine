NAME = brainzz

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = \
		main.cpp \
		Zombie.cpp \
		newZombie.cpp \
		randomChump.cpp 

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o:%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@ -I .

$(NAME):$(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@
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