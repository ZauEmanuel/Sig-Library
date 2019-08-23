#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "entries/entries.h"
#include "users/user.h"
#include "entries/admin/menuAdmin.h"
#include "entries/clients/menuClient.h"

#define cls system("clear||cls");

int main(void){
  cls;
  user = &pEntrie;
  setlocale( LC_ALL, "Portuguese" );
  printf("#######################################\n");
  printf("##              LOGIN                ##\n");
  printf("#######################################\n");
  entrCPF(user->cpf);
  entrKey(user->key);
  cls;
  menuClient();
  return 0;

}