programma: main.o frazioni.o
	gcc main.o frazioni.o -o ./programma

main.o: main.c frazioni.h
	gcc -c main.c

frazioni.o: frazioni.c frazioni.h
	gcc -c frazioni.c
