#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "entries/entries.h"
#include "entries/menu.h"
#include "entries/files.h"


#define cls system("clear||cls");

int main(void){
  criaArqBin();
  char log[11] = "";
  char senha[128] = "";
  int c = 0;
  cls;
  printf("#######################################\n");
  printf("##              LOGIN                ##\n");
  printf("#######################################\n");
  entrCPF(log);
  entrKey(senha);
  cls;
  menu();
  return 0;

}