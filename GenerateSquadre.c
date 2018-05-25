#include "include.h"
#include "Read.h"
#include "lista.h"
#include "Squadre.h"

Chierichetto* Lista;

int main(int argc, char *argv[]){
  int n;
  srand(time(NULL));
  if (argc<2){
    printf("Errore nella chiamata");
    return 0;
  }
  n = atoi(argv[1]);
  ReadList(&Lista);
  CreaNSquadre(Lista, n);
  WriteList(Lista);
}
