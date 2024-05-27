# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 10:59:31 by qraymaek          #+#    #+#              #
#    Updated: 2023/12/30 01:47:57 by qraymaek         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
INCLUDES = include
SRCS_DIR = src
OBJS_DIR = objs
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
LIBFT = libft
MLX = minilibx-linux

#Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SOURCES = read_map.c map_size.c \
		   calculations.c \
		  draw.c mlx.c main.c errors.c utils.c \
		  draw_utils.c

SRCS = $(addprefix $(SRCS_DIR)/,$(SOURCES))
OBJS = $(addprefix $(OBJS_DIR)/,$(SOURCES:.c=.o))

all: lib tmp $(NAME)

lib:
	@echo "$(GREEN)Creating lib files$(BLUE)"
	@make -C $(LIBFT)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -L $(LIBFT) -L $(MLX) -o $@ $^ -lft -lm -lmlx -lXext -lX11
	@echo "$(GREEN)Project successfully compiled"

tmp:
	@mkdir -p objs

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDES)/$(NAME).h
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(WHITE)"

clean:
	@echo "$(RED)Deleting library files$(BLUE)"
	@make clean -C $(LIBFT)
	@rm -rf $(OBJS_DIR)

fclean:
	@echo "$(RED)Deleting library files and .a$(BLUE)"
	@rm -rf $(OBJS_DIR)
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
	@echo "$(RED)All the files are now cleaned with fclean"

re: fclean
	@$(MAKE) all -j

.PHONY: tmp, re, fclean, clean
