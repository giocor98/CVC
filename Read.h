#ifndef READ_H
  #define READ_H

  #include "include.h"
  #include "lista.h"



  #define FILEDOMANDASINGOLA "DomandaDaCalcolare"
  #define FILEINTESASINGOLA "IntesaDaCalcolare"

  #define ESEMPIOHTML "Domanda.html"
  #define FINALHTML "Quiz.html"

  #define ESEMPIOHTMLINTESA "Intesa.html"
  #define FINALHTMLINTESA "IntesaVincente.html"

  #define READFILE "chierichetti.cof"

  void ReadList(Chierichetto** Lista);
  int WriteList(Chierichetto* Pointer);

  int ReadDomande(domanda_t** questionario, char* FileDomande);
  char* ReadFileUntil(FILE * fl, char term, int max);
  int WriteDomande(domanda_t* questionario, char* FileDomande);

  int ReadIntesa(intesa_t** list, char* file);
  int WriteIntese(intesa_t* list, char* file);

#endif
