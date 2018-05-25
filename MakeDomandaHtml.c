#include "include.h"
#include "Read.h"
#include "lista.h"


#define LENHTML 204

FILE * fh, * fd;

domanda_t * List = NULL;

int main(){
  char* riga=NULL;
  int Right=0;
  size_t len;
  ReadDomande(&List, FILEDOMANDASINGOLA);
  if(LenQuestionario(List)!=1){
    printf ("Errore\n");
    return 0;
  }
  fh = fopen(ESEMPIOHTML, "r");
  fd = fopen(FINALHTML, "w");
  if(fd == NULL || fh == NULL){
    printf("Error\n");
    fclose(fh);
    fclose(fd);
    return 0;
  }
  if(List->risposta[0][0]=='*'){
    List->risposta[0]+=1;
    Right = 1;
  }else if(List->risposta[1][0]=='*'){
    List->risposta[1]+=1;
    Right = 2;
  }else if(List->risposta[2][0]=='*'){
    List->risposta[2]+=1;
    Right = 3;
  }else if(List->risposta[3][0]=='*'){
    List->risposta[3]+=1;
    Right = 4;
  }

  int i=0;
  while(getline(&riga, &len, fh)>=0){
    i++;
    if(i==8){
      sprintf(riga, "\t\tvar right = %d;\n", Right);
    }else if(i==164){
      sprintf(riga, "%s\n", TITOLO);
    }else if(i==167){
      sprintf(riga, "%s\n", List->domanda);
    }else if(i==172){
      sprintf(riga, "%s\n", List->risposta[0]);
    }else if(i==175){
      sprintf(riga, "%s\n", List->risposta[1]);
    }else if(i==179){
      sprintf(riga, "%s\n", List->risposta[2]);
    }else if(i==182){
      sprintf(riga, "%s\n", List->risposta[3]);
    }
    fprintf(fd, "%s", riga);
  }
  fclose(fh);
  fclose(fd);
  return 1;
}
