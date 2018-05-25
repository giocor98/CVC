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
