#include "include.h"
#include "Read.h"
#include "lista.h"

domanda_t* questionario, * selected;

int main(int argc, char *argv[]){
  int len=0, i;
  srand(time(NULL));
  if (argc<2){
    printf("Errore nella chiamata");
    return 0;
  }
  ReadDomande(&questionario, argv[1]);
  len = LenQuestionario(questionario);
  if (len == 0){
    return 0;
  }
  i = rand()%len;
  selected = PopNDomanda(&questionario, i);
  WriteDomande(selected, FILEDOMANDASINGOLA);
  WriteDomande(questionario, argv[1]);
  return 1;
}
