# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 20:18:57 by qraymaek          #+#    #+#              #
#    Updated: 2023/11/27 19:56:40 by qraymaek         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Basics
NAME = push_swap
INCLUDES = includes
SRCS_DIR = src
OBJS_DIR = objs
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
LIBFT = libft

# Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SOURCES = big_sort.c checks.c cost_utils.c free.c input.c \
	  move_utils.c push.c push_swap.c rev_rotate.c \
	  rotate.c sort_three.c stack.c swap.c libft_functions.c

SRCS = $(addprefix $(SRCS_DIR)/,$(SOURCES))
OBJS = $(addprefix $(OBJS_DIR)/,$(SOURCES:.c=.o))

all: lib tmp $(NAME)

lib:
	@echo "$(GREEN)Creating lib files$(BLUE)"
	@make -C $(LIBFT)

tmp:
	@mkdir -p objs

 $(NAME): $(OBJS)
	$(CC) $(FLAGS) -L $(LIBFT) -o $@ $^ -lft -lm
	@echo "$(GREEN)Project successfully compiled"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDES)/$(NAME).h
	@$(CC) $(FLAGS) -c -o $@ $<
	@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(WHITE)"

clean:
	@echo "$(RED)Deleting library files$(BLUE)"
	@make clean -C $(LIBFT)
	@rm -rf $(OBJS_DIR)
	@echo "$(Green)Objects are cleaned"

fclean:
	@echo "$(RED)Deleting library files and .a$(BLUE)"
	@rm -rf $(OBJS_DIR)
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
	@echo "$(RED)All the files are now cleaned with fclean"

re: fclean all

.PHONY: tmp, re, fclean, clean
