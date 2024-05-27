NAME = minishell
INCLUDES = include
SRCS_DIR = src
OBJS_DIR = objs
OBJS_DIR_DEBUG = objs_debug
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -Iinclude
RM = rm -rf
LIBFT = libft
READLINE_FLAGS = -L/opt/homebrew/opt/readline/lib -lreadline -lhistory

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

SOURCES = main.c input/input.c input/lexer/lexer.c input/lexer/split_config.c \
		  input/lexer/split_input.c input/lexer/split_utils.c input/lexer/syntax.c\
		  input/lexer/lexer_list.c env/env.c builtins/env.c env/env_get_set.c \
		  utils/errors.c builtins/pwd.c builtins/unset.c builtins/cd.c \
		  env/env_set_utils.c builtins/exit.c builtins/echo.c builtins/export.c\
		  input/parser/ast.c input/parser/ast_utils.c utils/arrays.c \
		  expander/expander.c utils/pid.c executor/executor.c executor/builtin.c\
		  signals/signal.c executor/executor_utils.c executor/binary.c utils/redir_utils.c\
		  executor/redirections.c env/shell_lvl.c expander/expander_utils.c utils/env_array.c\
		  signals/signal2.c executor/pipes.c

SRCS = $(addprefix $(SRCS_DIR)/,$(SOURCES))
OBJS = $(addprefix $(OBJS_DIR)/,$(SOURCES:.c=.o))
OBJS_DEBUG = $(addprefix $(OBJS_DIR_DEBUG)/,$(SOURCES:.c=.o))

all: lib tmp $(NAME)
	@$(RM) $(OBJS_DIR_DEBUG)

debug: lib tmp_debug $(NAME)_debug
	@$(RM) $(OBJS_DIR)

lib:
	@echo "$(GREEN)Creating lib files$(BLUE)"
	@make -C $(LIBFT)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)/libft.a $(READLINE_FLAGS)
	@printf "$(BLUE)Compiling $(WHITE)%-30s$(BLUE)[100%%]$(RED)\r" "Done"
	@echo "$(GREEN)Project successfully compiled$(DEF_COLOR)"

$(NAME)_debug: $(OBJS_DEBUG)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS_DEBUG) $(LIBFT)/libft.a $(READLINE_FLAGS)
	@printf "$(BLUE)Compiling $(WHITE)%-30s$(BLUE)[100%%]$(RED)\r" "Done"
	@echo "$(GREEN)Debug executable successfully compiled$(DEF_COLOR)"

tmp:
	@mkdir -p $(OBJS_DIR) $(addprefix $(OBJS_DIR)/,$(dir $(SOURCES)))
	@echo "$(GREEN)Creating temporary directory: $(OBJS_DIR)$(DEF_COLOR)"

tmp_debug:
	@mkdir -p $(OBJS_DIR_DEBUG) $(addprefix $(OBJS_DIR_DEBUG)/,$(dir $(SOURCES)))
	@echo "$(GREEN)Creating temporary directory: $(OBJS_DIR_DEBUG)$(DEF_COLOR)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDES)/$(NAME).h
	@$(CC) $(CFLAGS) -c -o $@ $<
	@printf "$(BLUE)Compiling $(WHITE)%-30s$(BLUE)[%3d%%]$(RED)\r" $(notdir $@) $$(expr $$(expr $$(find $(OBJS_DIR) -name '*.o' 2>/dev/null | wc -l) \* 100) / $$(find $(SRCS_DIR) -name '*.c' | wc -l))
	@sleep 0.1

$(OBJS_DIR_DEBUG)/%.o: $(SRCS_DIR)/%.c $(INCLUDES)/$(NAME).h
	@$(CC) $(CFLAGS) -D DEBUG_MODE=true -c -o $@ $<
	@printf "$(BLUE)Compiling $(WHITE)%-30s$(BLUE)[%3d%%]$(RED)\r" $(notdir $@) $$(expr $$(expr $$(find $(OBJS_DIR_DEBUG) -name '*.o' 2>/dev/null | wc -l) \* 100) / $$(find $(SRCS_DIR) -name '*.c' | wc -l))
	@sleep 0.1

clean:
	@echo "$(RED)Deleting object files$(BLUE)"
	@make clean -C $(LIBFT)
	@$(RM) $(OBJS_DIR) $(OBJS_DIR_DEBUG)

fclean:
	@$(RM) $(OBJS_DIR) $(OBJS_DIR_DEBUG)
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
	@echo "$(RED)All files cleaned with fclean"

re: fclean
	@$(MAKE) all

.PHONY: tmp, re, fclean, clean, debug
