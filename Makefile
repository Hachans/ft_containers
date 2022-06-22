NAME = container

CC = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

SRC = ft.cpp
SRC2 = std.cpp

all: ft std

ft: $(SRC)
	$(CC) $(FLAGS) $(SRC) -o ft

std: $(SRC2)
	$(CC) $(FLAGS) $(SRC2) -o std

clean:
	rm -rf ft std

re: clean all

.PHONY: all clean re