#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "entries/entries.h"
#include "entries/admin/menuAdmin.h"
#include "entries/clients/menuClient.h"


#define cls system("clear||cls");

int main(void){
  criaArqBin();
  char log[11] = "";
  char senha[128] = "";
  int c = 0;
  //cls;
  setlocale( LC_ALL, "Portuguese" );
  printf("#######################################\n");
  printf("##              LOGIN                ##\n");
  printf("#######################################\n");
  entrCPF(log);
  entrKey(senha);
  cls;
  menuClient();
  return 0;

}