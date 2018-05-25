program:test.c include.h Read.o lista.o Squadre.o MakeHtmlDomanda ChooseRandomDomanda GenerateSquadre
		gcc -o program test.c Read.o lista.o Squadre.o
		./initialiser.sh
		ls *.domande > listaDomande.auto

MakeHtmlDomanda: MakeDomandaHtml.c Read.o lista.o include.h
		gcc -o MakeHtmlDomanda MakeDomandaHtml.c Read.o lista.o

ChooseRandomDomanda: ChooseRandomDomanda.c Read.o lista.o include.h
		gcc -o ChooseRandomDomanda ChooseRandomDomanda.c Read.o lista.o

GenerateSquadre: GenerateSquadre.c Read.o lista.o Squadre.o include.h
		gcc -o GenerateSquadre GenerateSquadre.c Read.o lista.o Squadre.o

Read.o: Read.c Read.h include.h
		gcc -c -o Read.o Read.c

lista.o: lista.c lista.h include.h
		gcc -c -o lista.o lista.c

Squadre.o: Squadre.c Squadre.h include.h
		gcc -c -o Squadre.o Squadre.c

clean:
		rm -f *.o
		rm -f program
		rm -f *.out
		rm -f MakeHtmlDomanda
		rm -f *.auto
		rm -f Quiz.html
