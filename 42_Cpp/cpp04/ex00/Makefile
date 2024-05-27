NAME = animals
SRC = main.cpp class_definitions/Animal.cpp class_definitions/Dog.cpp class_definitions/Cat.cpp class_definitions/WrongAnimal.cpp class_definitions/WrongCat.cpp
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
