#include "Squadre.h"

int CreaNSquadre(Chierichetto* Pointer, int n){
  printf("OK\n");
  Chierichetto* NuovaLista=NULL;
  ClonaLista(Pointer, &NuovaLista);
  int len, sq = 1, i, ret=1;
  printf("OK\n");
  if(Pointer == NULL){
    printf("Lista vuota\n");
    return 0;
  }
  do{
    char* nome;
    len = Len(NuovaLista);
    i = rand()%len;
    nome = GetName(NuovaLista, i);
    Remove(i, &NuovaLista);
    SetStatus(Pointer, Find(Pointer, -1, -1, -1, nome), sq);
    sq ++;
    if(sq >n){
      sq=1;
      ret++;
    }
    Pointer = (Chierichetto*)Pointer->next;
  }while(Pointer!=NULL);
  return ret;
}
