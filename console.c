#include "console.h"

WINDOW * infoW, * menuW, * logW, * statW;
int ActualMenu = 0, LenMenu[3], high[3];

WINDOW** WinArr[3]={
  &statW, &logW, &menuW
};


int main(){
  LenMenu[0]=FASILEN;
  LenMenu[1]=1;

  int c;

  initialize();
  initWindows();

  wprintw(infoW, TITOLO);
  wrefresh(infoW);

  PrintMenuW(high[ActualMenu], LenMenu[ActualMenu], MenuArr[ActualMenu] ,*WinArr[ActualMenu]);

  while(1){
    c = wgetch(menuW);
    switch(c){
      case KEY_UP:
        if(high[ActualMenu] <= 0)
          high[ActualMenu] = LenMenu[ActualMenu]-1;
        else
          --high[ActualMenu];
        break;
      case KEY_DOWN:
        if(high[ActualMenu] >= LenMenu[ActualMenu]-1)
          high[ActualMenu] = 0;
        else
          ++high[ActualMenu];
        break;
      case KEY_RIGHT:
        ActualMenu--;
        if(ActualMenu<0){
          ActualMenu = 2;
        }
        break;
      case KEY_LEFT:
        ActualMenu++;
        if(ActualMenu>2){
          ActualMenu = 0;
        }
        break;
      case 'q':
        ActualMenu = -1;
        break;
      case 10:
        MenuArr[ActualMenu][high[ActualMenu]].func(MenuArr[ActualMenu][high[ActualMenu]].String, high[ActualMenu]);
        break;
      default:
        mvwprintw(infoW, 3, 1, "Character pressed is = %3d Hopefully it can be printed as '%c'", c, c);
        wrefresh(infoW);
        break;
    }
    for(int i = 0;i<3;i++){
      PrintMenuW(high[i], LenMenu[i], MenuArr[i] ,*WinArr[i]);
    }
    PrintMenuW(high[ActualMenu], LenMenu[ActualMenu], MenuArr[ActualMenu] ,*WinArr[ActualMenu]);
    if(ActualMenu==-1)
      break;
  }

  endwin();
  clear();

}
