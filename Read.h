#ifndef READ_H
  #define READ_H

  #include "include.h"
  #include "lista.h"



  #define FILEDOMANDASINGOLA "DomandaDaCalcolare"
  #define ESEMPIOHTML "Domanda.html"
  #define FINALHTML "Quiz.html"
  
  #define READFILE "chierichetti.cof"

  void ReadList(Chierichetto** Lista);
  int WriteList(Chierichetto* Pointer);
  int ReadDomande(domanda_t** questionario, char* FileDomande);
  char* ReadFileUntil(FILE * fl, char term, int max);
  int WriteDomande(domanda_t* questionario, char* FileDomande);

#endif
