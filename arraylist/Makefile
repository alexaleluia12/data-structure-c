CFLAGS=-Wall -g
CC=gcc


main: main.o list.o
	${CC} ${CFLAGS} list.o testlist.o -o main

main.o: list.o testlist.c
	${CC} ${CFLAGS} -c testlist.c

list.o: list.c  list.h
	${CC} ${CFLAGS} -c list.c

clear:
	rm list.o testlist.o main
