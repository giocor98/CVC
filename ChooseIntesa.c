#include "include.h"
#include "Read.h"
#include "lista.h"

intesa_t* list, * selected;

int main(int argc, char *argv[]){
  int len=0, i;
  if (argc<3){
    printf("Errore nella chiamata");
    return 0;
  }
  ReadIntesa(&list, argv[1]);
  len = LenIntesa(list);
  if (len == 0){
    return 0;
  }
  i = atoi(argv[2])%len;
  selected = PopNIntesa(&list, i);
  WriteIntese(selected, FILEINTESASINGOLA);
  WriteIntese(list, argv[1]);
  return 1;
}
