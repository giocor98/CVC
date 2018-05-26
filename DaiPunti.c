#include "include.h"
#include "Read.h"
#include "lista.c"

Chierichetto * Lista;

int main(int argc, char *argv[]){
  int n, punti;
  srand(time(NULL));
  if (argc<3){
    printf("Errore nella chiamata");
    return 0;
  }
  n = atoi(argv[1]);
  punti = atoi(argv[2]);
  ReadList(&Lista);
  SetPuntiSeStatus(Lista, n, punti);
  WriteList(Lista);
}
