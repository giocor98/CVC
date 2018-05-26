#ifndef READ_H
  #define READ_H

  #include "include.h"
  #include "lista.h"



  #define FILEDOMANDASINGOLA "DomandaDaCalcolare"
  #define FILEINTESASINGOLA "IntesaDaCalcolare"
  #define FILEMIMOSINGOLO "MimoDaCalcolare"

  #define ESEMPIOHTML "Domanda.html"
  #define FINALHTML "/srv/http/Chierichetti/index.html"

  #define ESEMPIOHTMLINTESA "Intesa.html"
  #define FINALHTMLINTESA "/srv/http/Chierichetti/index.html"

  #define ESEMPIOHTMLMIMO "Mimo.html"
  #define FINALHTMLMIMO "/srv/http/Chierichetti/index.html"

  #define READFILE "chierichetti.cof"

  void ReadList(Chierichetto** Lista);
  int WriteList(Chierichetto* Pointer);

  int ReadDomande(domanda_t** questionario, char* FileDomande);
  char* ReadFileUntil(FILE * fl, char term, int max);
  int WriteDomande(domanda_t* questionario, char* FileDomande);

  int ReadIntesa(intesa_t** list, char* file);
  int WriteIntese(intesa_t* list, char* file);

  int ReadMimo(mimo_t** list, char* file);
  int WriteMimo(mimo_t* list, char* file);

#endif
