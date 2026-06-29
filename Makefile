NAME = aymane
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = src/main.c

all:
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all