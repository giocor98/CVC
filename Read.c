#include "Read.h"

FILE * fl;

void ReadList(Chierichetto** Lista){
  fl = fopen(READFILE, "r");
  if (fl == NULL){
    printf("Errore, non posso aprire il file...\n");
    return;
  }
  int eta, stato, punti, len=0;
  char nome[100];
  fscanf(fl, "%d\n", &len);
  for (int i = 0;i<len;i++){
    fscanf(fl, "%d %d %d %s\n", &eta, &stato, &punti, nome);
    AddToList(Lista, eta, punti, stato, nome);
  }
  fclose(fl);
}

int WriteList(Chierichetto* Pointer){
  fl = fopen(READFILE, "w");
  if (fl == NULL){
    printf("Errore, non posso aprire il file...\n");
    return 0;
  }
  int len;
  len = Len(Pointer);
  fprintf(fl, "%d\n", len);
  for(int i = 0;i<len;i++){
    fprintf(fl, "%d %d %d %s\n", Pointer->eta, Pointer->stato, Pointer->punti, Pointer->nome);
    Pointer =(Chierichetto*) Pointer->next;
  }
  fclose(fl);
  return 1;
}

int ReadDomande(domanda_t** questionario, char* FileDomande){
  fl = fopen(FileDomande, "r");
  if (fl == NULL){
    printf("Errore, non posso aprire il file...\n");
    return 0;
  }
  char ch;
  char* domanda, * risposta[4];
  int punteggio = 0;
  do{
    ch = fgetc(fl);
    if (ch == '#'){
      //Read domanda
      domanda = ReadFileUntil(fl, '#', 300);
      risposta[0]= ReadFileUntil(fl, '#', 300);
      risposta[1]= ReadFileUntil(fl, '#', 300);
      risposta[2]=  ReadFileUntil(fl, '#', 300);
      risposta[3]= ReadFileUntil(fl, '\n', 300);
      AddToQuestionario(questionario, domanda, risposta, punteggio);
    }else if (ch == '%'){
      fscanf(fl, "%d\n", &punteggio);
    }
  }while(ch !=EOF);
  fclose(fl);
  return 1;
}

int WriteDomande(domanda_t* questionario, char* FileDomande){
  fl = fopen(FileDomande, "w");
  if (fl == NULL){
    printf("Errore, non posso aprire il file...\n");
    return 0;
  }
  while(questionario!=NULL){
    fprintf(fl, "%%%d\n#%s #%s #%s #%s #%s\n", questionario->punteggio, questionario->domanda, questionario->risposta[0], questionario->risposta[1],questionario->risposta[2], questionario->risposta[3]);
    questionario=(domanda_t*)questionario->next;
  }
  fclose(fl);
  return 1;
}

#define MAXLEN 500

char* ReadFileUntil(FILE * fl, char term, int max){
  char tmp [MAXLEN], ch, * ret;
  int i=0;
  ch = fgetc(fl);
  tmp[0]=0;
  for(i=0;i<max && ch!=term; i++){
    if(ch == EOF){
      break;
    }
    tmp[i]=ch;
    tmp[i+1]=0;
    ch = fgetc(fl);
  }
  ret = malloc(strlen(tmp));
  if(ret!=NULL)
    strcpy(ret, tmp);
  return ret;
}
