#ifndef CONSOLE_H
  #define CONSOLE_H

  #include "include.h"
  #include <ncurses.h>

  #define infoHeight 7
  #define statHeight 12

  #define FASILEN 8
  #define LENMENU 50

  #define RED 10
  #define ORANGE 11
  #define GREEN 12
  #define BLUE 13
  #define MAGENTA 14
  #define CYAN 15
  #define WHITE 16

  typedef struct {
    char String [100];
    int color;
    int info;
    void (*func) (char* str, int info);
  } el_t;

  extern el_t FasiDiGioco[FASILEN], Menu[LENMENU], InfoMenu[LENMENU];
  extern int LenMenu[3];

  void initialize();
  void initWindows();
  void PrintMenuW(int high, int len, el_t PMenu[], WINDOW * win);
  void PopolaMenuChierichetti(Chierichetto* Pointer);

  void init (char* str, int info);
  void AddChierichetto (char* str, int info);
  void SelectChierichetto (char* str, int info);
  void FileIntesa (char* str, int info);
  void FileMimo (char* str, int info);
  void SelectIntesa (char* str, int info);
  void SelectMimo (char* str, int info);

  void vuota (char* str, int info);

  extern WINDOW * infoW, * menuW, * logW, * statW;
  extern el_t* MenuArr[3];
  extern int high[3];

#endif
