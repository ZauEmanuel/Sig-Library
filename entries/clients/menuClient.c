#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "../admin/menuAdmin.h"
#include "../../users/user.h"

#define cls system("clear||cls");
#define clBuf setbuf(stdin,NULL);

void acervoClient(void){
  char op = '1';
  printf("\n///////////////////////////////////\n");
  printf("               Acervo\n");
  printf("///////////////////////////////////\n");
  printf(" [1] Acervo\n [2] Solicitar Aquisião\n [0] Voltar\n\n");
  do {
    printf("Digite: ");
    scanf(" %c",&op);
  } while(!(op >= '0' && op <= '2'));
  cls;
  switch (op){
    case '0':
      return;
    case '1':
      //library();
      break;
    case '2':
      //newItem();
      break;
  }
}

void configUserClient(void){
  char op = '1';
  setlocale( LC_ALL, "Portuguese" );
  printf("\n---------------------------------");
  printf("\n       Opções de Usuario");  
  printf("\n---------------------------------");
  printf("\n [1] Atualizar dados\n [2] Excluir Conta\n [0] Voltar\n\n");
  do {
    printf("Digite: ");
    scanf(" %c",&op);
  } while(!(op >= '0' && op <= '2'));
  cls;
  switch (op){
    case '0':
      return;
    case '1':
      updateUser();
      break;
    case '2':
      //deleteUser();
      break;
  }
}


void menuClient(void) {
  char op = '1';
  do {
    setlocale( LC_ALL, "Portuguese" );
    printf("////////////////////////////////////\n");
    printf("           SIG - Library\n");
    printf("///////////////////////////////////\n");
    printf(" [1] Usuario\n [2] Acervo\n [3] Sobre \n [0] Sair\n\n");
		printf("Digite: ");
    scanf(" %c",&op);
    cls;
    if (op >= '0' && op <= '5') {
			switch (op) {
				case '1':
          configUserClient();
          break;
          
				case '2':
          acervoClient();
          break;
          
				case '3':
          about();
          break;
          
				case '0' :
				  break;
			}
    } 
    cls;
  } while (op != '0');
}
