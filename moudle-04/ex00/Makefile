# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: szhong <szhong@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/24 10:54:22 by szhong            #+#    #+#              #
#    Updated: 2025/07/24 10:54:24 by szhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= animal


CC		= c++
CFLAGS	= -Werror -Wextra -Wall -g -std=c++98


INC_PATH	= ./inc/
INC			= -I $(INC_PATH)

SRC_PATH	= ./src/
SRCS		= $(wildcard $(SRC_PATH)*.cpp)
OBJ_PATH	= ./obj/
OBJS			= $(SRCS:$(SRC_PATH)%.cpp=$(OBJ_PATH)%.o)

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "BUILD DONE"

clean:
	@rm -rf $(OBJ_PATH)
	@echo "OBJECT REMOVED"

fclean: clean
	@rm -f $(NAME)
	@echo "EVERYTHING CLEAR"
	@echo "==========PROJECT RESET =========="
	@echo ""

LOAD:
	@echo "BUILDING......"
re: LOAD fclean all

.PHONY: all re clean fclean
