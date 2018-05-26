program:test.c include.h Read.o lista.o Squadre.o MakeHtmlDomanda ChooseRandomDomanda GenerateSquadre Console DaiPunti ChooseDomanda ChooseIntesa ChooseRandomIntesa MakeHtmlIntesa ChooseMimo ChooseRandomMimo MakeHtmlMimo
		gcc -o program test.c Read.o lista.o Squadre.o
		./initialiser.sh

Console:console.c console.h include.h window.o global.o Read.o lista.o
		gcc -o Console console.c window.o global.o Read.o lista.o -lncurses

global.o: global.c include.h console.h
		gcc -c -o global.o global.c

window.o: window.c include.h console.h
		gcc -c -o window.o window.c

MakeHtmlDomanda: MakeDomandaHtml.c Read.o lista.o include.h
		gcc -o MakeHtmlDomanda MakeDomandaHtml.c Read.o lista.o

MakeHtmlIntesa: MakeHtmlIntesa.c Read.o lista.o include.h
		gcc -o MakeHtmlIntesa MakeHtmlIntesa.c Read.o lista.o

MakeHtmlMimo: MakeHtmlMimo.c Read.o lista.o include.h
		gcc -o MakeHtmlMimo MakeHtmlMimo.c Read.o lista.o

ChooseRandomDomanda: ChooseRandomDomanda.c Read.o lista.o include.h
		gcc -o ChooseRandomDomanda ChooseRandomDomanda.c Read.o lista.o

ChooseDomanda: ChooseDomanda.c Read.o lista.o include.h
		gcc -o ChooseDomanda ChooseDomanda.c lista.o Read.o

ChooseIntesa: ChooseIntesa.c Read.o lista.o include.h
		gcc -o ChooseIntesa ChooseIntesa.c Read.o lista.o

ChooseRandomIntesa: ChooseRandomIntesa.c include.h ChooseIntesa
		gcc -o ChooseRandomIntesa ChooseRandomIntesa.c

ChooseMimo: ChooseMimo.c Read.o lista.o include.h
		gcc -o ChooseMimo ChooseMimo.c Read.o lista.o

ChooseRandomMimo: ChooseMimo ChooseRandomMimo.c include.h
		gcc -o ChooseRandomMimo ChooseRandomMimo.c

GenerateSquadre: GenerateSquadre.c Read.o lista.o Squadre.o include.h
		gcc -o GenerateSquadre GenerateSquadre.c Read.o lista.o Squadre.o

DaiPunti: DaiPunti.c include.h Read.o
		gcc -o DaiPunti DaiPunti.c Read.o

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
		rm -f ChooseRandomDomanda
		rm -f GenerateSquadre
		rm -f Console
		rm -f *.auto
		rm -f *.domande
		rm -f Quiz.html
		rm -f IntesaVincente.html
		rm -f *.intesa
		rm -f DomandaDaCalcolare
		rm -f IntesaDaCalcolare
