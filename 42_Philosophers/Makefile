NAME = philo
INCLUDES = include
SRCS_DIR = src
OBJS_DIR = objs
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -pthread
RM = rm -rf

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

# Sources
SOURCES = init.c parser.c philo.c simulation.c utils/errors.c utils/get_set.c \
		  utils/sync.c utils/write.c monitor.c utils/clean.c

SRCS = $(addprefix $(SRCS_DIR)/,$(SOURCES))
OBJS = $(addprefix $(OBJS_DIR)/,$(SOURCES:.c=.o))

all: tmp $(NAME)
	@echo "$(GREEN)Object files are successfully created!$(DEF_COLOR)"
	@echo "$(GREEN)Project successfully compiled$(DEF_COLOR)"

tmp:
	@mkdir -p objs
	@mkdir -p objs/utils

 $(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $@ $^ -lm -pthread

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDES)/$(NAME).h
	@$(CC) $(CFLAGS) -c -o $@ $<
	@printf "\033[K"  # Clears the line before printing the next one
	@echo -n "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(DEF_COLOR)\r"

clean:
	@echo "$(RED)Deleting library files$(DEF_COLOR)"
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)All the files are now cleaned with fclean$(DEF_COLOR)"

re: fclean
	@$(MAKE) all

.PHONY: tmp, re, fclean, clean
