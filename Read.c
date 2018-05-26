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

int ParseIntesa(char* param, char** parola, char*** veto){
  int i = -1, x =strlen(param)+1;
  char* tmp = param;
  char* arr[10];
  for(int c = 0;c<x; c++){
    if(param[c]==' '||param[c]==0){
      param[c]=0;
      if(i<0){
        *parola=malloc(strlen(tmp));
        if(*parola==NULL){
          return 0;
        }
        strcpy(*parola, tmp);
        tmp = &param[c+1];
      }else{
        arr[i]=tmp;
        tmp = &param[c+1];
      }
      i++;
    }
  }
  *veto = malloc(sizeof(char*)*(i));
  if(*veto==NULL){
    return 0;
  }
  for(int c=0;c<i;c++){
    (*veto)[c]=malloc(sizeof(char)*(strlen(arr[c])+1));
    if((*veto)[c]==NULL){
      return 0;
    }
    strcpy((*veto)[c], arr[c]);
  }
  return i;
}

int ReadIntesa(intesa_t** list, char* file){
  fl = fopen(file, "r");
  if (fl == NULL){
    printf("Errore, non posso aprire il file...\n");
    return 0;
  }
  char ch;
  char* parola, **veto, *tmp;
  int punteggio = 0, n_veto=0;
  do{
    ch = fgetc(fl);
    if (ch == '#'){
      tmp = ReadFileUntil(fl, '\n', 500);
      n_veto = ParseIntesa(tmp, &parola, &veto);
      AddIntesa(list, parola, veto, punteggio, n_veto);
    }else if (ch == '%'){
      fscanf(fl, "%d\n", &punteggio);
    }
  }while(ch !=EOF);
  fclose(fl);
  return 1;
}

int WriteIntese(intesa_t* list, char* file){
  char ch[300];
  fl = fopen(file, "w");
  if (fl == NULL){
    //printf("Errore, non posso aprire il file...\n");
    return 0;
  }
  while(list!=NULL){
    //strcpy(ch, "%%%d\n#%s");
    sprintf(ch, "%%%d\n#%s", list->punti, list->parola);
    for(int i = 0;i<list->n_veto;i++){
      strcat(ch, " ");
      strcat(ch, list->veto[i]);
    }
    strcat(ch, "\n");
    fprintf(fl, ch);
    list = (intesa_t*)list->next;
  }
  fclose(fl);
  return 1;
}

int ReadMimo(mimo_t** list, char* file){
  char *Mimo, ch;
  fl = fopen(file, "r");
  if (fl == NULL){
    printf("Errore, non posso aprire il file...\n");
    return 0;
  }
  int punteggio = 0;
  do{
    ch = fgetc(fl);
    if (ch == '#'){
      Mimo = ReadFileUntil(fl, '\n', 500);
      AddMimo(list, Mimo, punteggio);
      free(Mimo);
    }else if (ch == '%'){
      fscanf(fl, "%d\n", &punteggio);
    }
  }while(ch !=EOF);
  fclose(fl);
  return 1;
}

int WriteMimo(mimo_t* list, char* file){
  fl = fopen(file, "w");
  if (fl == NULL){
    printf("Errore, non posso aprire il file...\n");
    return 0;
  }
  while(list!=NULL){
    fprintf(fl, "%%%d\n#%s\n", list->punti, list->Mimo);
    list = (mimo_t*)list->next;
  }
  fclose(fl);
  return 1;
}
