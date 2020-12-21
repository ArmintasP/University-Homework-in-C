list.exe: main.o nodes.o
	gcc -ansi main.o nodes.o -o list.exe
main.o: main.c nodes.h
	gcc -ansi -c main.c
nodes.o: nodes.c nodes.h
	gcc -ansi -c nodes.c