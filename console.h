#ifndef CONSOLE_H
  #define CONSOLE_H

  #include "include.h"
  #include <ncurses.h>

  #define infoHeight 7
  #define statHeight 12

  void initialize();
  void initWindows();

  extern WINDOW * infoW, * menuW, * logW, * statW;

#endif
