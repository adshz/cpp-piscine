DF = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
MAGENTA = \033[0;95m
YELLOW = \033[0;93m
CYAN =\033[0;96m
WHITE = \033[0;97m
BOLD = \033[91m
ORANGE = \033[38;5;208m

NAME	=	PhoneBook

CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra -std=c++98

SRC_DIR	=	./src
OBJ_DIR	=	./obj
INC_DIR	=	./includes/

SRC	=	\
			main.cpp \
			PhoneBook.class.cpp \
			Contact.class.cpp

SRCS	=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJ		=	$(SRC:.cpp=.o)
OBJS	=	$(addprefix $(OBJ_DIR)/, $(OBJ))
INC		=	-I $(INC_DIR)

all:	$(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "${GREEN}BUILD is done.${DF}"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "${CYAN}*********Objects Removed*********${CYAN}"

fclean: clean
	@rm -rf $(NAME)
	@echo "${CYAN}*********Everything Removed*********${CYAN}"
	@echo "${BOLD}${ORANGE}======== PROJECT RESET ========${DF}"

re: fclean all

.PHONY: all re clean fclean