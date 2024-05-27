NAME = phonebook
SRC = phonebook_main.cpp class_definition/Contact.cpp class_definition/PhoneBook.cpp
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
