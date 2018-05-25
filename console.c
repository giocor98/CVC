#include "console.h"

WINDOW * infoW, * menuW, * logW, * statW;

int main(){

  int c;

  initialize();
  initWindows();

  wprintw(infoW, TITOLO);
  wrefresh(infoW);
  c = wgetch(menuW);

/*
  c = wgetch(menuW);
  print_menuW(highlight);
  while(1){
    c = wgetch(menuW);
    switch(c){
      case KEY_UP:
        if(highlight == 1)
          highlight = n_choices;
        else
          --highlight;
        break;
      case KEY_DOWN:
        if(highlight == n_choices)
          highlight = 1;
        else
          ++highlight;
        break;
  UpdateButtons();
      case 10:
        choice = highlight;
        break;
      case 'q':
        Exit();
        break;
      case 'c':
        if(CommentShortcut){
          AddComment();
        }
        break;
      case 'p':
        if(PointShortcut){
          AddPoint();
        }
        break;
      case 's':
        if(StartShortcut){
          StartOrPause();
        }
        break;
      case 'i':
        if(SettingShortcut){
          AdSetting();
        }
        break;
      case 'r':
        if(ResumeShortcut){
          Resume();
        }
        break;
      default:
        mvwprintw(infoW, 3, 1, "Character pressed is = %3d Hopefully it can be printed as '%c'", c, c);
        wrefresh(infoW);
        break;
    }
    print_menuW(highlight);
    if(choice != 0){	/* User did a choice come out of the infinite loop */
      /*Choosen(choice);
      choice = 0;
    }
    if(_menu == -1)
      break;
  }

  endwin();
  clear();

}*/

}
