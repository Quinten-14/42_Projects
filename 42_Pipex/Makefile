# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 16:08:16 by qraymaek          #+#    #+#              #
#    Updated: 2023/12/04 19:33:42 by qraymaek         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Basics #
NAME = pipex
INCLUDES = include
SRCS_DIR = src
OBJS_DIR = objs
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -rf
LIBFT = libft

# Colors #
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Sources #
SOURCES = pipex.c get_next_line.c get_next_line_utils.c utils.c error.c operations.c

# Prefixes #
SRCS = $(addprefix $(SRCS_DIR)/,$(SOURCES))
OBJS = $(addprefix $(OBJS_DIR)/,$(SOURCES:.c=.o))

# All rule #
all: lib tmp $(NAME)
	@echo "$(GREEN)Object files are successfully created!$(DEF_COLOR)"
	@echo "$(GREEN)Project successfully compiled$(DEF_COLOR)"

# Lib rule #
lib:
	@echo "$(GREEN)Creating lib files$(DEF_COLOR)"
	@make -sC $(LIBFT)

# Tmp rule #
tmp:
	@mkdir -p objs

# Compiling #
 $(NAME): $(OBJS)
	$(CC) $(CFLAGS) -L $(LIBFT) -o $@ $^ -lft -lm

# Compiling #
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDES)/$(NAME).h
	@$(CC) $(CFLAGS) -c -o $@ $<
	@printf "\033[K"  # Clears the line before printing the next one
	@echo -n "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(DEF_COLOR)\r"

# Clean rule #
clean:
	@echo "$(RED)Deleting library files$(DEF_COLOR)"
	@make fclean -sC $(LIBFT)
	@rm -rf $(OBJS_DIR)

# Fclean rule #
fclean: clean
	@echo "$(RED)Deleting library files and .a$(DEF_COLOR)"
	@rm -f $(NAME)
	@echo "$(RED)All the files are now cleaned with fclean$(DEF_COLOR)"

# Re rule #
re: fclean
	@$(MAKE) all

# Phony rule #
.PHONY: tmp, re, fclean, clean
