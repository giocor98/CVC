program:test.c include.h Read.o lista.o Squadre.o
		gcc -o program test.c Read.o lista.o Squadre.o

Read.o: Read.c Read.h include.h
		gcc -c -o Read.o Read.c

lista.o: lista.c lista.h include.h
		gcc -c -o lista.o lista.c

Squadre.o: Squadre.c Squadre.h include.h
		gcc -c -o Squadre.o Squadre.c
