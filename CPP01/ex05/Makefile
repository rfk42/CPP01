CC = c++
RM = rm -f

CFLAGS = -Wall -Wextra -Werror -std=c++98

PRGM_NAME = Harl

SRC = Harl.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(PRGM_NAME)

$(PRGM_NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(PRGM_NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(PRGM_NAME)

re: fclean all

.PHONY: all clean fclean re
