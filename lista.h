#ifndef LISTA_H
  #define LISTA_H

  #include "include.h"
  #include "Read.h"

  int AddToList( Chierichetto** Lista, int eta, int punti, int stato, char Name[100]);
  void PrintList( Chierichetto* Pointer);
  int Remove(int pos, Chierichetto ** Lista);
  int Len(Chierichetto* Pointer);
  int Find (Chierichetto* Pointer, int eta, int punti, int stato, char* nome);
  int SetStatus(Chierichetto* Pointer, int pos, int status);
  int SetPunteggio(Chierichetto* Pointer, int pos, int punti);
  int SetPuntiSeStatus(Chierichetto* Pointer, int status, int punti);
  void ClonaLista (const Chierichetto * fonte, Chierichetto** dest);
  char* GetName(Chierichetto* Pointer, int pos);
  int AddToQuestionario(domanda_t** questionario, char*domanda, char*risposte[4], int punteggio);
  void PrintQuest(domanda_t* questionario);
  int LenQuestionario(domanda_t* questionario);
  domanda_t* PopNDomanda(domanda_t** questionario, int n);


#endif
