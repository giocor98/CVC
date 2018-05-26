#include "include.h"
#include "Read.h"
#include "lista.h"

domanda_t* questionario, * selected;

int main(int argc, char *argv[]){
  int len=0, i;
  if (argc<3){
    printf("Errore nella chiamata");
    return 0;
  }
  ReadDomande(&questionario, argv[1]);
  len = LenQuestionario(questionario);
  if (len == 0){
    return 0;
  }
  i = atoi(argv[2])%len;
  selected = PopNDomanda(&questionario, i);
  WriteDomande(selected, FILEDOMANDASINGOLA);
  WriteDomande(questionario, argv[1]);
  return 1;
}
