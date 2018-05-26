#ifndef INCLUDE_H
  #define INCLUDE_H

  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <time.h>

  #define TITOLO "Chi vuol essere CHIERICHETTO (II)?"

  typedef struct{
    int eta;
    int punti;
    int stato;  //squadra o altro
    int lenNome;
    char * nome;
    struct Chierichetto * next;
  }Chierichetto;

  typedef struct{
    char* parola;
    char** veto;
    int punti;
    int n_veto;
    struct intesa_t* next;
  }intesa_t;

  typedef struct{
    char* domanda;
    char* risposta[4];
    int punteggio;
    struct domanda_t* next;
  }domanda_t;

  typedef struct{
    char* Mimo;
    int punti;
    struct mimo_t* next;
  }mimo_t;

  extern Chierichetto * Lista;
  extern mimo_t* lista_mimo;
#endif
