CC = c++

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Harl

SRC = main.cpp Harl.cpp

INCLUDE = Harl.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.cpp $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
