NAME	:=	harlFilter

CC		:=	c++
CFLAGS	:=	-Werror -Wextra -Wall -std=c++98

SRCS	:=	\
			main.cpp \
			Harl.cpp
			
OBJS	:=	$(SRCS:.cpp=.o)

all:$(NAME)

%.o:%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGD) $^ -o $@
	@echo "BUILD DONE"

clean:
	@rm -rf $(OBJS)
	@echo "OBJECTS REMOVED"

fclean: clean
	@rm -rf $(NAME)
	@echo "EVERYTHING CLEAR"
	@echo "======PROJECT RESET======="
	@echo ""

re: fclean all

.PHONY: all re fclean clean