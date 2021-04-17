CC = gcc
CFLAGS = -Wall -Wextra -Werror
main:
	$(CC) $(CFLAGS) -o $@ main.c