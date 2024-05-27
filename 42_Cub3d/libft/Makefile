# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qraymaek <qraymaek@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 13:58:55 by lpeeters          #+#    #+#              #
#    Updated: 2024/05/04 18:01:33 by lpeeters         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#program name (library)
NAME = libft.a

#make into library file
LIBC = ar rcs

#compiler
CC = cc

#flags
CFLAGS = -g -Wall -Wextra -Werror

#remove
RM = rm -rf

#source files
SRCS = check/ft_isprint.c					\
	   check/ft_isspace.c					\
	   check/ft_isdigit.c					\
	   check/ft_isalnum.c					\
	   check/ft_isascii.c					\
	   check/ft_isalpha.c					\
	   check/strisdigit.c					\
	      									\
	   memory/ft_memcmp.c					\
	   memory/ft_memset.c					\
	   memory/ft_memmove.c					\
	   memory/ft_calloc.c					\
	   memory/ft_bzero.c					\
	   memory/ft_memcpy.c					\
	   memory/ft_memchr.c					\
	      									\
	   list/ft_lstdelone_bonus.c			\
	   list/ft_lstnew_bonus.c				\
	   list/ft_lstadd_back_bonus.c			\
	   list/ft_lstsize_bonus.c				\
	   list/ft_lstmap_bonus.c				\
	   list/ft_lstlast_bonus.c				\
	   list/ft_lstclear_bonus.c				\
	   list/ft_lstadd_front_bonus.c			\
	   list/ft_lstiter_bonus.c				\
	      									\
	   convert/ft_atoi.c					\
	   convert/ft_tolower.c					\
	   convert/ft_itoa.c					\
	   convert/ft_abs.c						\
	   convert/ft_toupper.c					\
	      									\
	   array/cpy_arr.c						\
	   array/free_array.c					\
	   array/mk_arr.c						\
	   array/resize_array.c					\
	   array/get_arr_char.c					\
	      									\
	   string/ft_putstr_fd.c				\
	   string/ft_strlen.c					\
	   string/ft_strdup.c					\
	   string/ft_strjoin.c					\
	   string/ft_strtrim.c					\
	   string/ft_split.c					\
	   string/ft_strrchr.c					\
	   string/ft_strmapi.c					\
	   string/ft_strlcat.c					\
	   string/ft_strlcpy.c					\
	   string/ft_strncmp.c					\
	   string/ft_putchar_fd.c				\
	   string/ft_putnbr_fd.c				\
	   string/ft_strchr.c					\
	   string/ft_strnstr.c					\
	   string/ft_putendl_fd.c				\
	   string/ft_strcmp.c					\
	   string/ft_substr.c					\
	   string/ft_striteri.c					\
	   string/strjoin.c						\
	   string/ext_cmp.c						\
	      									\
	   integer/free_int_arr.c				\
	      									\
	   get_next_line/get_next_line.c		\
	   get_next_line/get_next_line_utils.c	\

#object directory
OBJ_DIR = OBJS/

#convert c files into object files
OBJS = ${SRCS:%.c=${OBJ_DIR}%.o}

#header file
HEADER = libft.h

#make directories for object files
MK_DIR = mkdir -p ${@D}

#color codes
WHITE = \033[0;39m
YELLOW = \033[38;5;226m
GREEN = \033[0;92m
RED = \033[0;31m

#key codes
UP = \033[A
CLEAR = \033[K

#make object files
${OBJ_DIR}%.o: %.c ${SRCS} ${HEADER}
	@${MK_DIR}
	@echo "[LIBFT] ${YELLOW}Compiling: $<${WHITE}"
	@${CC} ${CFLAGS} -c $< -I ./ -o $@
	@printf "${UP}${CLEAR}"

#make project into library file
${NAME}: ${OBJS}
	@echo "[LIBFT] ${GREEN}done compiling object files${WHITE}"
	@${MK_DIR}
	@${LIBC} ${NAME} ${OBJS}
	@echo "[LIBFT] ${GREEN}done compiling executable${WHITE}"

#make
all: ${NAME}

#clean object files and directories
clean:
	@echo "[LIBFT] ${RED}removing object files...${WHITE}"
	@${RM} ${OBJ_DIR}

#clean everything that was made
fclean: clean
	@echo "[LIBFT] ${RED}removing executable...${WHITE}"
	@${RM} ${NAME}

#remake
re: fclean all

#targets
.PHONY: all clean fclean re
