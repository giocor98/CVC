#include "include.h"
#include "lista.h"
#include "Read.h"

intesa_t* list;

int main(){
  ReadIntesa(&list, "hey");
  //printf("%s\n", list->parola);

  WriteIntese(PopNIntesa(&list, 0), "hey1");
  WriteIntese(list, "hey");

}
