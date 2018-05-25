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
    char* domanda;
    char* risposta[4];
    int punteggio;
    struct domanda_t* next;
  }domanda_t;

  extern Chierichetto * Lista;
#endif
