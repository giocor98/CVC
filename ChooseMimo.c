#include "include.h"
#include "Read.h"
#include "lista.h"

mimo_t* list, * selected;

int main(int argc, char *argv[]){
  int len=0, i;
  if (argc<3){
    printf("Errore nella chiamata");
    return 0;
  }
  ReadMimo(&list, argv[1]);
  len = LenMimo(list);
  if (len == 0){
    return 0;
  }
  i = atoi(argv[2])%len;
  selected = PopNMimo(&list, i);
  WriteMimo(selected, FILEMIMOSINGOLO);
  WriteMimo(list, argv[1]);
  return 1;
}
