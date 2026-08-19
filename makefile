SRC = $(wildcard *.c)

all:
	gcc $(SRC) -o library
