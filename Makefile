CC = gcc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -MMD
SRC = src/libchess
CHESS = src/chess


bin/main: obj/chess.o obj/$(SRC)/libmove.a
	$(CC) $(CFLAGS) -o $@  $^

obj/chess.o: $(CHESS)/main.c
	$(CC) $(CFLAGS)  -o $@  -c $^ -Isrc/libchess

obj/$(SRC)/libmove.a: obj/$(CHESS)/move.o
	ar rcs $@ $<
obj/$(CHESS)/move.o: $(SRC)/move.c
	$(CC) -c $(CFLAGS) -o $@ -c $^ 
-include main.d  move.d