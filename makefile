magic: magic.o
	gcc -ansi -Wall -pedantic -g magic.o -o magic
magic.o: magic.c
	gcc -c -ansi -Wall -pedantic magic.c -o magic.o
