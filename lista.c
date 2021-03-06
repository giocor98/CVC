#include "lista.h"

int AddToList( Chierichetto** Lista, int eta, int punti, int stato, char Name[100]){
  Chierichetto * New;
  char * nome;
  if(Find(*Lista, -1, -1, -1, Name)!=-1){
    printf("non posso aggiungere il chierichetto, ne esiste gia' un altro con nome uguale...\n");
    return 0;
  }
  New = malloc(sizeof(Chierichetto));
  nome = malloc(strlen(Name));
  if (New == NULL || nome == NULL){
    free(New);
    free(nome);
    printf("\nErrore!!\nnon posso allocare il nuovo chierichetto\n");
    return 0;
  }
  strcpy(nome, Name);
  New->eta = eta;
  New->punti = punti;
  New->stato = stato;
  New->nome = nome;
  New->next = (struct Chierichetto*)(*Lista);
  *Lista = New;

  return 1;

}

int AddToQuestionario(domanda_t** questionario, char*domanda, char*risposte[4], int punteggio){
  domanda_t* new;
  new = malloc(sizeof(domanda_t));
  if(new == NULL){
    printf("Non posso aggiungere la domanda\n");
    return 0;
  }
  new->domanda = domanda;
  new->risposta[0] = risposte[0];
  new->risposta[1] = risposte[1];
  new->risposta[2] = risposte[2];
  new->risposta[3] = risposte[3];
  new->punteggio = punteggio;
  new->next = (struct domanda_t*)*questionario;
  *questionario = new;
  return 1;
}

void PrintQuest(domanda_t* questionario){
  while(questionario!=NULL){
    printf("Nuova domanda da %d punti:\n%s\n\t%s\t\t%s\n\t%s\t\t%s\n\n", questionario->punteggio, questionario->domanda, questionario->risposta[0], questionario->risposta[1], questionario->risposta[2], questionario->risposta[3]);
    questionario = (domanda_t*)questionario->next;
  }
}

void PrintList(Chierichetto* Pointer){
  while(Pointer!=NULL){
    printf("New Chierichetto:\n\tnome:\t%s;\n\teta:\t%d;\n\tpunti:\t%d;\n\tstato:\t%d;\n\n", Pointer->nome, Pointer->eta, Pointer->punti, Pointer->stato);
    Pointer = (Chierichetto * )Pointer->next;
  }
  printf("Ended\n");
}

int Remove(int pos, Chierichetto ** Lista){
  int i;
  for(i=0;i<pos&&*Lista!=NULL;i++){
    Lista = (Chierichetto **) (&(*Lista)->next);
  }
  if (*Lista == NULL){
    return 0;
  }
  Chierichetto* tmp;
  tmp = *Lista;
  *Lista = (Chierichetto*)((*Lista)->next);
  free(tmp->nome);
  free(tmp);
  return 1;
}

int Len(Chierichetto* Pointer){
  int i=0;
  while(Pointer!=NULL){
    Pointer = (Chierichetto * )(Pointer->next);
    i++;
  }
  return i;
}

int SetStatus(Chierichetto* Pointer, int pos, int status){
  for(int i =0; i<pos && Pointer!=NULL; i++){
    Pointer = (Chierichetto*) Pointer->next;
  }
  if(Pointer == NULL){
    printf("Errore, non posso cambiare lo stato richiesto\n");
    return 0;
  }
  Pointer->stato = status;
  return 1;
}

int SetPunteggio(Chierichetto* Pointer, int pos, int punti){
  for(int i =0; i<pos && Pointer!=NULL; i++){
    Pointer = (Chierichetto*) Pointer->next;
  }
  if(Pointer == NULL){
    printf("Errore, non posso cambiare i punti richiesti\n");
    return 0;
  }
  Pointer->punti = punti;
  return 1;
}

int SetPuntiSeStatus(Chierichetto* Pointer, int status, int punti){
  int n = 0;
  while(Pointer!=NULL){
    if(Pointer->stato == status){
      n++;
      Pointer->punti += punti;
    }
    Pointer = (Chierichetto*)Pointer->next;
  }
  return n;
}

int LenQuestionario(domanda_t* questionario){
  int i=0;
  while(questionario!=NULL){
    i++;
    questionario = (domanda_t*) questionario->next;
  }
  return i;
}

domanda_t* PopNDomanda(domanda_t** questionario, int n){
  if (n>=LenQuestionario(*questionario)){
    return NULL;
  }
  for(int i = 0;i<n;i++){
    questionario = (domanda_t**) &((*questionario)->next);
  }
  domanda_t* ret = *questionario;
  *questionario=(domanda_t*)ret->next;
  ret->next = NULL;
  return ret;
}

void FreeDomanda(domanda_t *questionario){
  free(questionario->domanda);
  free(questionario->risposta[0]);
  free(questionario->risposta[1]);
  free(questionario->risposta[2]);
  free(questionario->risposta[3]);
  free(questionario);
}

int Find (Chierichetto* Pointer, int eta, int punti, int stato, char* nome){
  int ret=0;
  while (Pointer!=NULL && (eta!=Pointer->eta||eta==-1)&&(punti!=Pointer->punti||punti==-1)&&(stato!=Pointer->stato||stato==-1)&&(strcmp(nome, Pointer->nome)!=0||nome==NULL)){
    ret++;
    Pointer =(Chierichetto*) Pointer->next;
  }
  if(Pointer == NULL){
    ret = -1;
  }
  return ret;
}

void ClonaLista (const Chierichetto * fonte, Chierichetto** dest){
  while(fonte!=NULL){
//    printf("i %d %d %d %s\n", fonte->eta, fonte->punti, fonte->stato, fonte->nome);
    AddToList(dest, fonte->eta, fonte->punti, fonte->stato, fonte->nome);
    fonte = (Chierichetto*)fonte->next;
  }
}

char* GetName(Chierichetto* Pointer, int pos){
  for(int i=0;i<pos&&Pointer!=NULL; i++, Pointer=(Chierichetto*)Pointer->next)
    ;
  if(Pointer == NULL){
    printf("ERRORE, non trovato\n");
    return NULL;
  }
  char * ret;
  ret = malloc(strlen(Pointer->nome));
  strcpy(ret, Pointer->nome);
  return ret;
}

  void FreeLista(Chierichetto** Lista){
    while(*Lista != NULL){
      Remove(0, Lista);
    }
  }


  void FreeDomande(domanda_t** pointer){
    while(*pointer != NULL){
      PopNDomanda(pointer, 0);
    }
  }

  Chierichetto * FindN(Chierichetto* pointer, int n){
    for(int i = 0; i<n && pointer!=NULL; i++){
      pointer = (Chierichetto*)pointer->next;
    }
    return pointer;
  }


int AddIntesa(intesa_t** list, char* parola, char* veto[], int punti, int n_veto){
  intesa_t* new;
  new=malloc(sizeof(intesa_t));
  if (new == NULL){
    return 0;
  }
  new->parola = parola;
  new->veto = veto;
  new->punti = punti;
  new->n_veto = n_veto;
  new->next = (struct intesa_t*) *list;
  *list = new;
  return 1;
}

int LenIntesa(intesa_t* list){
  int i=0;
  while(list!=NULL){
    i++;
    list = (intesa_t*)list->next;
  }
  return i;
}

intesa_t* PopNIntesa(intesa_t** list, int n){
  for(int i=0; i<n&&*list!=NULL; i++){
    list = (intesa_t**)(&(*list)->next);
  }
  if (*list==NULL){
    return *list;
  }else{
    intesa_t* tmp;
    tmp = *list;
    *list = (intesa_t*)tmp->next;
    tmp->next = NULL;
    return tmp;
  }
}

void FreeIntesa(intesa_t* elemento){
  free(elemento->parola);
  for(int i=0;i<elemento->n_veto;i++){
    free(elemento->veto[i]);
  }
  free(elemento->veto);
  free(elemento);
}

void FreeIntese(intesa_t** list){
  while(*list !=NULL){
    FreeIntesa(PopNIntesa(list, 0));
  }
}

int AddMimo(mimo_t** list, char* Mimo, int punti){
  mimo_t* new;
  new = malloc(sizeof(mimo_t));
  if(new == NULL){
    return 0;
  }
  new->Mimo = malloc(sizeof(char) * (strlen(Mimo) + 1));
  if(new->Mimo == NULL)
    return 0;
  strcpy(new->Mimo, Mimo);
  new->punti = punti;
  new->next = (struct mimo_t*) *list;
  *list = new;
  return 1;
}

int LenMimo(mimo_t* list){
  int len=0;
  while (list !=NULL){
    len++;
    list = (mimo_t*) list->next;
  }
  return len;
}

mimo_t* PopNMimo(mimo_t** list, int n){
  for(int i = 0; i<n && *list!=NULL; i++){
    list = (mimo_t**)&((*list)->next);
  }
  if(*list == NULL){
    return *list;
  }
  mimo_t* tmp;
  tmp = *list;
  *list = (mimo_t*)tmp->next;
  tmp->next = NULL;
  return tmp;
}

void FreeMimo(mimo_t *elemento){
  free(elemento->Mimo);
  free(elemento);
}

void FreeMimi(mimo_t** list){
  while (*list!=NULL){
    FreeMimo(PopNMimo(list, 0));
  }
}

int SetStatoSeStatus(Chierichetto* Pointer, int status, int NewStato){
  while(Pointer!=NULL){
    if(Pointer->stato == status){
      Pointer->stato = NewStato;
    }
    Pointer = (Chierichetto*) Pointer->next;
  }
}
