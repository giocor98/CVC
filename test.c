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
  AddToList(&Lista, 20, 1000, 0, "Giocor");
  AddToList(&Lista, 20, 1000, 0, "Giovanni");
  AddToList(&Lista, 20, 1000, 0, "Alby");
  AddToList(&Lista, 20, 1000, 0, "Richi");
  AddToList(&Lista, 20, 1000, 0, "Ludo");
  AddToList(&Lista, 20, 1000, 0, "Giacomo");
  PrintList(Lista);
  printf("Cerco \"Giocor\" : %d\n",Find (Lista, -1, -1, -1, "Giocor"));
  printf("Cerco \"Giacomo\" : %d\n",Find (Lista, -1, -1, -1, "Giacomo"));
  printf("Cerco \"Ludo\" : %d\n",Find (Lista, -1, -1, -1, "Ludo"));
  printf("Cerco \"Giorgio\" : %d\n",Find (Lista, -1, -1, -1, "Giorgio"));
  //SetStatus(Lista, 1, 1);
  //SetPunteggio(Lista, 2, 1);
  //SetPuntiSeStatus(Lista, 1, 100);
  ReadDomande(&questionario, "prova.domande");
  PrintList(Lista);
  CreaNSquadre(Lista, 4);
  PrintList(Lista);
  WriteList(Lista);
  PrintQuest( questionario);
  printf("----------------------------\n\n\n");
  WriteDomande(PopNDomanda(&questionario, 2), "Domanda");
  printf("----------------------------\n\n\n");
  PrintQuest( questionario);
}
