CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
CPPFLAGS = -MMD
SRC = src/libchess
CHESS = src/chess
EXCEPT = ls -I "bin" -I "obj" -I "src" -I "Makefile"

bin/main: obj/chess.o obj/$(SRC)/libmove.a
	$(CC) $(CFLAGS) -o $@  $^

obj/chess.o: $(CHESS)/main.c
	$(CC) $(CFLAGS)  -o $@  -c $^ -I$(SRC)

obj/$(SRC)/libmove.a: obj/$(CHESS)/move.o
	ar rcs $@ $<
obj/$(CHESS)/move.o: $(SRC)/move.c
	$(CC) -c $(CFLAGS) -o $@ -c $^ 
-include main.d  move.d

.PHONY: clean

clean:
	rm -rf $$($(EXCEPT));
	rm bin/*
	rm obj/*.o
	rm obj/src/chess/*
	rm obj/src/libchess/*
