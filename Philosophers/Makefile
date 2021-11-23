# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 09:56:47 by npinheir          #+#    #+#              #
#    Updated: 2021/11/22 08:28:54 by npinheir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program.
NAME	:= philo

# Name of the directories.
INC_DIR := include
SRC_DIR := src
OBJ_DIR := obj

# Path of the directories.
INC		:= $(INC_DIR)
SRC		:= $(wildcard $(SRC_DIR)/*.c)
OBJ		:= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Define all the compiling flags.
CC		:= gcc
CFLAGS	+= -Wall -Werror -Wextra
LFLAGS	+= -I.

# Colors
RED = \033[0;31m
GREEN = \033[0;32m
NONE = \033[0m

# Compile and create everything.
all:	obj
		@$(MAKE) -j $(NAME)

# Creates the object files' directory.
obj:
		@mkdir -p $(OBJ_DIR)
		@echo "\t$(GREEN)✔ Object folder created in philo !$(NONE)"

# This won't run if the object files don't exist or are not modified.
$(NAME): $(OBJ)
		@$(CC) -pthread $(OBJ) -o $(NAME)
		@echo "\t$(GREEN)✔ Philo created !$(NONE)"

# This won't run if the source files don't exist or are not modified.
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@$(CC) $(CFLAGS) -c $< -o $@ $(LFLAGS)/$(INC)

# Rule to remove all the object files and directory.
clean:
		@rm -rf $(OBJ) $(OBJ_DIR)
		@echo "\t$(GREEN)✔ Objects removed in philo !$(NONE)"

# Rule to remove everything that has been created by the makefile.
fclean: clean
		@rm -rf $(NAME) $(LIB_DIR)
		@echo "\t$(GREEN)✔ Philo fully cleaned up !$(NONE)"

# Rule to re-make everything.
re:		fclean all

# Unit test the library.
c:		all
		@rm -rf $(OB) $(OBJ_DIR)
		@echo "\t$(GREEN)✔ Objects removed !$(NONE)"

.PHONY:	all clean fclean re c