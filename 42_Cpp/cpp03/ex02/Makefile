NAME = fragtrap
SRC = main.cpp class_definitions/ClapTrap.cpp class_definitions/ScavTrap.cpp class_definitions/FragTrap.cpp
OBJ = $(SRC:.cpp=.o)
CC = g++
RM = rm -rf
FLAGS = -Wall -Werror -Wextra -std=c++98 -g

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.phony: all clean fclean re
