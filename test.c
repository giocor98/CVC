#include "include.h"
#include "lista.h"
#include "Read.h"
#include "Squadre.h"

Chierichetto * Lista = NULL;
domanda_t * questionario=NULL;

void main(){
  int x;
  srand(time(NULL));
  printf("Here\n");
  ReadList(&Lista);
  PrintList(Lista);
  CreaNSquadre(Lista, 2);
  WriteList(Lista);
}
