#include "include.h"

int main(int argc, char *argv[]){
  if (argc<2){
    printf("Errore nella chiamata");
    return 0;
  }
  char cmd[100];
  srand(time(NULL));
  sprintf(cmd, "./ChooseMimo %s %d\n", argv[1], rand());
  system(cmd);
}
