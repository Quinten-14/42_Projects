NAME = RPN
SRC = main.cpp class_definitions/RPN.cpp
OBJ = $(SRC:.cpp=.o)
CC = g++
RM = rm -rf
FLAGS = -Wall -Werror -Wextra -std=c++98 -g

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.phony: all clean fclean re
