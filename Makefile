NAME = container

CC = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

SRC = ft.cpp
SRC2 = std.cpp

std: $(SRC2)
	$(CC) $(FLAGS) $(SRC2) -o $(NAME)

ft: $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

re: clean all

.PHONY: all clean re