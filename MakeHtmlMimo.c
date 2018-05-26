#include "include.h"
#include "Read.h"
#include "lista.h"

#define LENHTML 170

FILE * fh, * fd;

mimo_t * List = NULL;

int main(){
  char* riga=NULL;
  int Right=0;
  size_t len;
  ReadMimo(&List, FILEMIMOSINGOLO);
  if(LenMimo(List)!=1){
    printf ("Errore\n");
    return 0;
  }
  fh = fopen(ESEMPIOHTMLMIMO, "r");
  fd = fopen(FINALHTMLMIMO, "w");
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
      sprintf(riga, "%s<br/>%s\n", TITOLO, "mimo");
    }else if(i==167){
      sprintf(riga, "%s\n", List->Mimo);
    }
    fprintf(fd, "%s", riga);
  }
  fclose(fh);
  fclose(fd);
  return 1;
}
