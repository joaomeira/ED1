all: programa

programa: main.o atv5.o
	gcc -o programa main.o atv5.o
	
main.o: main.c atv5.o
	gcc -c main.c -Wall
	
atv5.o:
	gcc -c atv5.c -Wall
