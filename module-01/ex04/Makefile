NAME		=	replace

CC			=	c++
CPPFLAGS	=	-Wall -Werror -Wextra -std=c++98
RM			=	rm -rf

SRCS		=	main.cpp

OBJS		=	$(SRCS:%.cpp=%.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)
			@echo "Linked into executable \033[38;2;39;154;186m$(NAME)\033[0m"

.cpp.o:
			@$(CC) $(CPPFLAGS) -c $< -o $(<:.cpp=.o)
			@echo "Compiling $<."

clean:
			@$(RM) $(OBJS)
			@echo "Removed object files." 

fclean:		clean
			@$(RM) $(NAME)
			@echo "Removed executable."

re:			fclean all

.PHONY:		fclean, all, re