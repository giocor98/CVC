#include "include.h"
#include "Read.h"
#include "lista.h"


#define LENHTML 2173

FILE * fh, * fd;

intesa_t * List = NULL;

int main(){
  char* riga=NULL;
  int Right=0;
  size_t len;
  ReadIntesa(&List, FILEINTESASINGOLA);
  if(LenIntesa(List)!=1){
    printf ("Errore\n");
    return 0;
  }
  fh = fopen(ESEMPIOHTMLINTESA, "r");
  fd = fopen(FINALHTMLINTESA, "w");
  if(fd == NULL || fh == NULL){
    printf("Error\n");
    fclose(fh);
    fclose(fd);
    return 0;
  }
  int i=0;
  while(getline(&riga, &len, fh)>=0){
    i++;
    if(i==164){
      sprintf(riga, "%s\n", TITOLO);
    }else if(i==167){
      sprintf(riga, "%s\n", List->parola);
    }else if(i==170){
      sprintf(riga, "");
      for(int c=0; c<List->n_veto;c++){
        sprintf(riga, "%s </br> %s", riga, List->veto[c]);
      }
      sprintf(riga, "%s\n", riga);
    }
    fprintf(fd, "%s", riga);
  }
  fclose(fh);
  fclose(fd);
  return 1;
}
