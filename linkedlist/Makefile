CFLAGS=-Wall -g
CC=gcc


main: main.o linkedlist.o
	${CC} ${CFLAGS} linkedlist.o testlinkedlist.o -o main

main.o: linkedlist.o testlinkedlist.c
	${CC} ${CFLAGS} -c testlinkedlist.c

linkedlist.o: linkedlist.c  linkedlist.h
	${CC} ${CFLAGS} -c linkedlist.c

clear:
	rm linkedlist.o testlinkedlist.o main
