#include "console.h"
#include "ToBeImplemented.h"
#include "lista.h"

Chierichetto * Lista;
domanda_t* domande = NULL;
intesa_t* list = NULL;
mimo_t* lista_mimo = NULL;

char CurrentFile[100]="";

el_t* MenuArr[3] = {
  FasiDiGioco, Menu, InfoMenu
};

el_t FasiDiGioco[FASILEN] = {
  {
    "Inizializzazione", RED, 0, init
  },
  {
    "Salva/ricarica Chierichetti", RED, 0, Inizia
  },
  {
    "Aggiungi Chierichetto", ORANGE, 0, AddChierichetto
  },
  {
    "Crea Squadre", ORANGE, 0, CreaSquadre
  },
  {
    "Dai Punti alla Squadra", ORANGE, 0, DaiPuntiA
  },
  {
    "Quiz", ORANGE, 0, Quiz
  },
  {
    "Mimo", ORANGE, 0, Mimo
  },
  {
    "Intesa Vincente", ORANGE, 0, Intesa
  }
};

el_t Menu[LENMENU] = {
  {
    "Exit", BLUE, 0, Exit
  }
};

el_t InfoMenu[LENMENU] = {
  {
    "Exit", BLUE, 0, Exit
  }
};


void Exit (char* str, int info){}


void init (char* Str, int info){
  system("make clean &> /dev/null\nmake &> /dev/null");
  ReadList(&Lista);
  PopolaMenuChierichetti(Lista);
  FasiDiGioco[info].color = GREEN;
  FasiDiGioco[info+1].color = GREEN;
}

void AddChierichetto (char* str, int info){
  WINDOW * AddW;
  char nome[100];
  int ch, eta, punti=0, stato = 0;
  int i=0;
  nome[0]=0;
  init_pair (80, COLOR_BLUE, COLOR_YELLOW);
  init_pair (41, COLOR_YELLOW, COLOR_BLACK);
  AddW = newwin(8, 70, (LINES/2)-3, (COLS/2)-35);
  wmove(AddW, 0,0);
  wbkgd(AddW, COLOR_PAIR(80));
  box(AddW, 0, 0);
  mvwprintw(AddW, 0, 35-7, "Add chierichetto");
  mvwprintw(AddW, 1, 1, "Nome:");
  //wattron(LogFileW, COLOR_PAIR(81));
  wrefresh(AddW);
  ch = wgetch(menuW);
  while((char)ch!='\n'){
    int z=0;
    if(ch!=KEY_BACKSPACE&&ch!=KEY_DC&&ch!=KEY_CANCEL&&ch!=127)
      nome[i++]=(char)ch;
    else
      nome[--i]=0;
    if (i<0)
      i=0;
    nome[i+1]=0;
    mvwprintw(AddW, 1, 7, nome);
    for (z=strlen(nome)+7; z<69;z++)
      wprintw(AddW, " ");
    wmove(AddW, 1, 7+strlen(nome));
    wrefresh(AddW);
    ch = wgetch(AddW);
  }
  mvwprintw(AddW, 2, 1, "eta':");
  wscanw(AddW, "%d\n", &eta);
  mvwprintw(AddW, 2, 1, "eta':%d", eta);
  mvwprintw(AddW, 3, 1, "punti:0");
  wscanw(AddW, "%d\n", &punti);
  mvwprintw(AddW, 3, 1, "punti:%d", punti);
  mvwprintw(AddW, 4, 1, "stato:0");
  wscanw(AddW, "%d\n", &stato);
  mvwprintw(AddW, 4, 1, "stato:%d", stato);

  mvwprintw(AddW, 6, 3, "Ok, s per salvarlo, d per \"scartarlo\"");
  ch = wgetch(AddW);
  if((char)ch != 'd'&&(char)ch != 'D')
    AddToList(&Lista, eta, punti, stato, nome);
  wrefresh(AddW);
  delwin(AddW);
  PopolaMenuChierichetti(Lista);
  FasiDiGioco[info-1].color = RED;
  return;
}

void Inizia (char* str, int info){
  WriteList(Lista);
  FreeLista(&Lista);
  ReadList(&Lista);
  PopolaMenuChierichetti(Lista);
  FasiDiGioco[info].color = GREEN;
}

void PopolaMenuChierichetti(Chierichetto* Pointer){
  int i = 0;
  while(Pointer!=NULL){
    strcpy(InfoMenu[i].String, Pointer->nome);
    InfoMenu[i].color = RED + Pointer->stato;
    InfoMenu[i].info = 0;
    InfoMenu[i].func = SelectChierichetto;
    i++;
    Pointer = (Chierichetto*)Pointer->next;
  }
  LenMenu[2]=i;
  high[2]=0;
}

void vuota (char* str, int info){
  return;
}

void CreaSquadre (char* str, int info){
  WINDOW * AddW;
  char cmd[100];
  int ch, n;
  int i=0;
  init_pair (80, COLOR_BLUE, COLOR_YELLOW);
  init_pair (41, COLOR_YELLOW, COLOR_BLACK);
  AddW = newwin(8, 70, (LINES/2)-3, (COLS/2)-35);
  wmove(AddW, 0,0);
  wbkgd(AddW, COLOR_PAIR(80));
  box(AddW, 0, 0);
  mvwprintw(AddW, 0, 35-6, "Crea Squadre");
  mvwprintw(AddW, 1, 1, "Quante squadre vuoi creare? (-1=non crearne)");
  wscanw(AddW, "%d\n", &n);
  mvwprintw(AddW, 2, 1, "numero squadre:%d", n);
  if(n!=-1){
    mvwprintw(AddW, 6, 3, "Creo le squadre");
    wrefresh(AddW);
    ch = wgetch(AddW);
    sprintf(cmd, "./GenerateSquadre %d\n", n);
    system(cmd);
  }
  wrefresh(AddW);
  delwin(AddW);
  FreeLista(&Lista);
  ReadList(&Lista);
  PopolaMenuChierichetti(Lista);
  return;
}
void DaiPuntiA (char* str, int info){
  WINDOW * AddW;
  char cmd[100];
  int ch, n, punti;
  int i=0;
  init_pair (80, COLOR_BLUE, COLOR_YELLOW);
  init_pair (41, COLOR_YELLOW, COLOR_BLACK);
  AddW = newwin(8, 70, (LINES/2)-3, (COLS/2)-35);
  wmove(AddW, 0,0);
  wbkgd(AddW, COLOR_PAIR(80));
  box(AddW, 0, 0);
  mvwprintw(AddW, 0, 35-4, "Dai Punti");
  mvwprintw(AddW, 1, 1, "A chi devo dare i punti?");
  wrefresh(AddW);
  wscanw(AddW, "%d\n", &n);
  mvwprintw(AddW, 1, 1, "A chi devo dare i punti? %d", n);
  mvwprintw(AddW, 2, 1, "Quanti punti devo dare?");
  wrefresh(AddW);
  wscanw(AddW, "%d\n", &punti);
  mvwprintw(AddW, 2, 1, "Quanti punti devo dare? %d", punti);
  mvwprintw(AddW, 5, 1, "Do %d punti alla squadra %d [press n per annullare]", punti, n);
  wrefresh(AddW);
  ch = wgetch(AddW);
  if((char)ch!='n'&&(char)ch!='N'){
    sprintf(cmd, "./DaiPunti %d %d\n", n, punti);
    system(cmd);
  }
  wrefresh(AddW);
  delwin(AddW);
  FreeLista(&Lista);
  ReadList(&Lista);
  PopolaMenuChierichetti(Lista);
  return;
}

void Quiz (char* str, int info){
  FILE * fl;
  char ch[100];
  int i=0;
  fl = fopen("listaDomande.auto", "r");
  if(fl == NULL){
    FasiDiGioco[info].color = RED;
  }
  FasiDiGioco[info].color = ORANGE;
  while(fscanf(fl, "%s\n", ch)!=EOF){
    strcpy(Menu[i].String, ch);
    Menu[i].color = ORANGE;
    Menu[i].info = 0;
    Menu[i].func = FileQuiz;
    i++;
  }
  LenMenu[1]=i;
  high[1]=0;
}

void PopolaMenuDomande(domanda_t* Pointer){
  int i = 0;
  while(Pointer!=NULL){
    strcpy(InfoMenu[i].String, Pointer->domanda);
    InfoMenu[i].color = RED;
    InfoMenu[i].info = 0;
    InfoMenu[i].func = SelectDomanda;
    i++;
    Pointer = (domanda_t*)Pointer->next;
  }
  LenMenu[2]=i;
  high[2]=0;
}

void FileQuiz (char* str, int info){
  WINDOW * AddW;
  char cmd[100];
  int ch;
  int i=0;
  init_pair (80, COLOR_BLUE, COLOR_YELLOW);
  init_pair (41, COLOR_YELLOW, COLOR_BLACK);
  AddW = newwin(5, 50, (LINES/2)-3, (COLS/2)-25);
  wmove(AddW, 0,0);
  wbkgd(AddW, COLOR_PAIR(80));
  box(AddW, 0, 0);
  mvwprintw(AddW, 0, 25-4, "Domanda casuale?");
  mvwprintw(AddW, 1, 1, "Estraggo la domanda casualmente?[y/n]");
  wrefresh(AddW);
  ch = wgetch(AddW);
  if((char)ch=='y'&&(char)ch!='Y'){
    sprintf(cmd, "./ChooseRandomDomanda %s\n./MakeHtmlDomanda\n", str);
    system(cmd);
  }
  wrefresh(AddW);
  delwin(AddW);
  FreeDomande(&domande);
  ReadDomande(&domande, str);
  PopolaMenuDomande(domande);
  strcpy(CurrentFile, str);
}

void SelectDomanda (char* str, int info){
  WINDOW * AddW;
  char cmd[100];
  int ch;
  int i=0;
  init_pair (80, COLOR_BLUE, COLOR_YELLOW);
  init_pair (41, COLOR_YELLOW, COLOR_BLACK);
  AddW = newwin(5, 50, (LINES/2)-3, (COLS/2)-25);
  wmove(AddW, 0,0);
  wbkgd(AddW, COLOR_PAIR(80));
  box(AddW, 0, 0);
  mvwprintw(AddW, 0, 25-4, "Faccio la Domanda?");
  mvwprintw(AddW, 1, 1, "Faccio questa domanda?[y/n]");
  wrefresh(AddW);
  ch = wgetch(AddW);
  if((char)ch=='y'&&(char)ch!='Y'){
    sprintf(cmd, "./ChooseDomanda %s %d\n./MakeHtmlDomanda\n", CurrentFile, info);
    system(cmd);
  }
  wrefresh(AddW);
  delwin(AddW);
  FreeDomande(&domande);
  ReadDomande(&domande, CurrentFile);
  PopolaMenuDomande(domande);
}

void SelectChierichetto (char* str, int info){
  WINDOW * AddW;
  Chierichetto* this;
  int ch;
  int i=0;
  init_pair (80, COLOR_BLUE, COLOR_YELLOW);
  init_pair (41, COLOR_YELLOW, COLOR_BLACK);
  AddW = newwin(7, 50, (LINES/2)-3, (COLS/2)-25);
  wmove(AddW, 0,0);
  wbkgd(AddW, COLOR_PAIR(80));
  box(AddW, 0, 0);
  this = FindN(Lista, info);
  mvwprintw(AddW, 0, 25-strlen(str)/2, "%s", str);
  mvwprintw(AddW, 1, 1, "Nome : %s", this->nome);
  mvwprintw(AddW, 2, 1, "eta : %d", this->eta);
  mvwprintw(AddW, 3, 1, "stato [s] : %d", this->stato);
  mvwprintw(AddW, 4, 1, "punti [p] : %d", this->punti);
  wrefresh(AddW);
  ch = wgetch(AddW);
  if((char)ch=='s'&&(char)ch!='S'){
    mvwprintw(AddW, 3, 1, "stato [s] : %d |inserisci il nuovo stato...", this->stato);
    wscanw(AddW, "%d\n", &this->stato);
    FasiDiGioco[1].color = RED;
  }else if ((char)ch=='p'&&(char)ch!='P'){
    mvwprintw(AddW, 4, 1, "punti [p] : %d |inserisci il nuovo punteggio...", this->punti);
    wscanw(AddW, "%d\n", &this->punti);
    FasiDiGioco[1].color = RED;
  }
  wrefresh(AddW);
  delwin(AddW);
}


void Intesa (char* str, int info){
  FILE * fl;
  char ch[100];
  int i=0;
  fl = fopen("listaIntese.auto", "r");
  if(fl == NULL){
    FasiDiGioco[info].color = RED;
  }
  FasiDiGioco[info].color = ORANGE;
  while(fscanf(fl, "%s\n", ch)!=EOF){
    strcpy(Menu[i].String, ch);
    Menu[i].color = ORANGE;
    Menu[i].info = 0;
    Menu[i].func = FileIntesa;
    i++;
  }
  LenMenu[1]=i;
  high[1]=0;
}

void PopolaMenuIntese(intesa_t* Pointer){
  int i = 0;
  while(Pointer!=NULL){
    strcpy(InfoMenu[i].String, Pointer->parola);
    InfoMenu[i].color = RED;
    InfoMenu[i].info = 0;
    InfoMenu[i].func = SelectIntesa;
    i++;
    Pointer = (intesa_t*)Pointer->next;
  }
  LenMenu[2]=i;
  high[2]=0;
}

void FileIntesa (char* str, int info){
  WINDOW * AddW;
  char cmd[100];
  int ch;
  int i=0;
  init_pair (80, COLOR_BLUE, COLOR_YELLOW);
  init_pair (41, COLOR_YELLOW, COLOR_BLACK);
  AddW = newwin(5, 50, (LINES/2)-3, (COLS/2)-25);
  wmove(AddW, 0,0);
  wbkgd(AddW, COLOR_PAIR(80));
  box(AddW, 0, 0);
  mvwprintw(AddW, 0, 25-4, "Intesa casuale?");
  mvwprintw(AddW, 1, 1, "Estraggo l'intesa casualmente?[y/n]");
  wrefresh(AddW);
  ch = wgetch(AddW);
  if((char)ch=='y'&&(char)ch!='Y'){
    sprintf(cmd, "./ChooseRandomIntesa %s\n./MakeHtmlIntesa\n", str);
    system(cmd);
  }
  wrefresh(AddW);
  delwin(AddW);
  FreeIntese(&list);
  ReadIntesa(&list, str);
  PopolaMenuIntese(list);
  strcpy(CurrentFile, str);
}

void SelectIntesa (char* str, int info){
  WINDOW * AddW;
  char cmd[100];
  int ch;
  int i=0;
  init_pair (80, COLOR_BLUE, COLOR_YELLOW);
  init_pair (41, COLOR_YELLOW, COLOR_BLACK);
  AddW = newwin(5, 50, (LINES/2)-3, (COLS/2)-25);
  wmove(AddW, 0,0);
  wbkgd(AddW, COLOR_PAIR(80));
  box(AddW, 0, 0);
  mvwprintw(AddW, 0, 25-10, "Scelgo quest'intesa?");
  mvwprintw(AddW, 1, 1, "scelgo quest'intesa?[y/n]");
  wrefresh(AddW);
  ch = wgetch(AddW);
  if((char)ch=='y'&&(char)ch!='Y'){
    sprintf(cmd, "./ChooseIntesa %s %d\n./MakeHtmlIntesa\n", CurrentFile, info);
    system(cmd);
  }
  wrefresh(AddW);
  delwin(AddW);
  //PopolaMenuIntese(list);
}


void Mimo (char* str, int info){
  FILE * fl;
  char ch[100];
  int i=0;
  fl = fopen("listaMimi.auto", "r");
  if(fl == NULL){
    FasiDiGioco[info].color = RED;
    return;
  }
  FasiDiGioco[info].color = ORANGE;
  while(fscanf(fl, "%s\n", ch)!=EOF){
    strcpy(Menu[i].String, ch);
    Menu[i].color = ORANGE;
    Menu[i].info = 0;
    Menu[i].func = FileMimo;
    i++;
  }
  LenMenu[1]=i;
  high[1]=0;
}

void PopolaMenuMimo(mimo_t* Pointer){
  int i = 0;
  while(Pointer!=NULL){
    strcpy(InfoMenu[i].String, Pointer->Mimo);
    InfoMenu[i].color = RED;
    InfoMenu[i].info = 0;
    InfoMenu[i].func = SelectMimo;
    i++;
    Pointer = (mimo_t*)Pointer->next;
  }
  LenMenu[2]=i;
  high[2]=0;
}

void FileMimo (char* str, int info){
  WINDOW * AddW;
  char cmd[100];
  int ch;
  int i=0;
  init_pair (80, COLOR_BLUE, COLOR_YELLOW);
  init_pair (41, COLOR_YELLOW, COLOR_BLACK);
  AddW = newwin(5, 50, (LINES/2)-3, (COLS/2)-25);
  wmove(AddW, 0,0);
  wbkgd(AddW, COLOR_PAIR(80));
  box(AddW, 0, 0);
  mvwprintw(AddW, 0, 25-4, "Mimo casuale?");
  mvwprintw(AddW, 1, 1, "Estraggo il mimo casualmente?[y/n]");
  wrefresh(AddW);
  ch = wgetch(AddW);
  if((char)ch=='y'&&(char)ch!='Y'){
    sprintf(cmd, "./ChooseRandomMimo %s\n./MakeHtmlMimo\n", str);
    system(cmd);
  }
  wrefresh(AddW);
  delwin(AddW);
  FreeMimi(&lista_mimo);
  ReadMimo(&lista_mimo, str);
  PopolaMenuMimo(lista_mimo);
  strcpy(CurrentFile, str);
}

void SelectMimo (char* str, int info){
  WINDOW * AddW;
  char cmd[100];
  int ch;
  int i=0;
  init_pair (80, COLOR_BLUE, COLOR_YELLOW);
  init_pair (41, COLOR_YELLOW, COLOR_BLACK);
  AddW = newwin(5, 50, (LINES/2)-3, (COLS/2)-25);
  wmove(AddW, 0,0);
  wbkgd(AddW, COLOR_PAIR(80));
  box(AddW, 0, 0);
  mvwprintw(AddW, 0, 25-10, "Scelgo questo mimo?");
  mvwprintw(AddW, 1, 1, "scelgo questo mimo?[y/n]");
  wrefresh(AddW);
  ch = wgetch(AddW);
  if((char)ch=='y'&&(char)ch!='Y'){
    sprintf(cmd, "./ChooseMimo %s %d\n./MakeHtmlMimo\n", CurrentFile, info);
    system(cmd);
  }
  wrefresh(AddW);
  delwin(AddW);FreeMimi(&lista_mimo);
  ReadMimo(&lista_mimo, CurrentFile);
  PopolaMenuMimo(lista_mimo);
}
