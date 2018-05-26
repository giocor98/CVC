#include "console.h"

void initialize(){
  initscr();
  clear();
  noecho();
  cbreak();
}

void initWindows(){
  if(has_colors() == FALSE)
	{	endwin();
		printf("Your terminal does not support color\n");
		return;
	}
  start_color();
  infoW = newwin(infoHeight, COLS, 0, 0);
  box(infoW, 0, 0);
  mvwprintw(infoW, 0, (COLS/2)-2, "INFO");
  wmove(infoW, 1,1);
  wrefresh(infoW);

  menuW = newwin(LINES - (infoHeight ), COLS/2, infoHeight, 0);
  box(menuW, 0,0);
  mvwprintw(menuW, 0, (COLS/4)-2, "MENU");
  wmove(menuW, 1,1);
  wrefresh(menuW);
	keypad(menuW, TRUE);

  statW  = newwin(statHeight , COLS/2, LINES - (statHeight), COLS/2);
  box(statW, 0,0);
  mvwprintw(statW, 0, (COLS/4)-3, "Status");
  wmove(statW, 1,1);
  wrefresh(statW);

  logW  = newwin((LINES - (infoHeight + statHeight)) , COLS/2, infoHeight, COLS/2);
  box(logW, 0,0);
  mvwprintw(logW, 0, (COLS/4)-2, "LOG");
  wmove(logW, 1,1);
  wrefresh(logW);
}

void PrintMenuW(int high, int len, el_t PMenu[], WINDOW * win){
  init_pair (RED, COLOR_RED, COLOR_BLACK);
  init_pair (ORANGE, COLOR_YELLOW, COLOR_BLACK);
  init_pair (GREEN, COLOR_GREEN, COLOR_BLACK);
  init_pair (BLUE, COLOR_BLUE, COLOR_BLACK);
  init_pair (WHITE, COLOR_WHITE, COLOR_BLACK);
  init_pair (MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
  init_pair (CYAN, COLOR_CYAN, COLOR_BLACK);
  werase(win);
  box(win, 0,0);
  wmove(win, 1,1);
  for(int i=0;i<len; i++){
    wattron(win, COLOR_PAIR(PMenu[i].color));
    if (i==high)
      wattron(win, A_REVERSE);
    mvwprintw(win, i+1, 1, PMenu[i].String);
    if (i==high)
      wattroff(win, A_REVERSE);
    wattroff(win, COLOR_PAIR(PMenu[i].color));
  }
  wrefresh(win);
}
