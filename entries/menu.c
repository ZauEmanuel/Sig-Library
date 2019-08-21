#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "valid.h"
#include "../users/user.h"
#define cls system("clear||cls");
#define clBuf setbuf(stdin,NULL);

void user(void);
void livro(void);
void bibli(void);
void config(void);
void configUser(void);
void about(void);
  
void acervo(void){
	cls;
	char op = '1';
	printf("\n|||||||||||||||||||||||||||||||||\n");
  printf("              Acervo");
  printf("\n|||||||||||||||||||||||||||||||||\n");
  printf(" [1] Acervo\n [2] Pesquisar material\n [3] Cadastrar material\n [4] Atualizar material\n [5] Remover material\n [0] Voltar\n\n");
	do {
    printf("Digite: ");
    scanf(" %c",&op);
	} while(!((op >= '0') && (op <= '5')));
	// Fun??es Futuras //
}

void user(void) {
	char op = '1';
	cls;
	do {
		cls;
		printf("\n|||||||||||||||||||||||||||||||||\n");
		printf("              Usuario\n");
		printf("|||||||||||||||||||||||||||||||||\n");
		printf(" [1] Pesquisar\n [2] Cadastrar\n [3] Atualizar\n [4] Remover\n [0] Voltar\n\n");
		printf("Digite: ");
		scanf(" %c",&op);
		if(op >= '0' && op <= '5') {
			cls;
			switch (op) {
				case '1':
				pesqUser();
				break;
				
				case '2':
				newUser();
				break;

				case '3':
				//updateUser();
				break;
				
				case '4':
				//delUser();
				break;

				case '0':
				break;
			}
		}
	cls;
	} while(op != '0');
}

void livro(void){
  int op = 1;

  while(op != 0)
  {
    printf("\n///////////////////////////////////\n");
    printf("               Acervo\n");
    printf("///////////////////////////////////\n");
    printf(" [1] Acervo\n [2] Solicitar Aquisi??o\n [3] Biblioteca\n [4] Config.\n [0] Voltar\n\n");
    scanf("%d",&op);
    system("clear||cls");
    cls
  }
}
void bibli(void){
  int op = 1;
  printf("\n////////////////////////////////////\n");
  printf("             Biblioteca\n");
  printf("///////////////////////////////////\n");
  printf(" [1] Relat?rio\n [2] Gerenciamento de Funcion?rios\n [3] Entrada e Sa?da de Livros\n [4] Usu?rio\n [0] Voltar\n\n");
  do { 
		printf("Digite: ");
    scanf("%d",&op);
    switch (op){
      case 1:
      //Fun??o Relat?rio
      printf("Fun??o n?o implementada!\n");
			getchar();
      break;

      case 2:
      //Fun??o Gerenciamento de Funcion?rios
      printf("Fun??o n?o implementada!\n");
			getchar();
      break;

      case 3:
      //Fun??o Entrada e Sa?da de Livros
      printf("Fun??o n?o implementada!\n");
			getchar();
      break;

      case 4:
      //Fun??o Usu?rio
      printf("Fun??o n?o implementada!\n");
			getchar();
      break;

      case 0:
      break;
    }
  } while (op != 0);
  cls;
}

void config(void){
  int op = 1;

  while(op != 0)
  {
  printf("\n////////////////////////////////////\n");
  printf("              Op??es.\n");
  printf("///////////////////////////////////\n");
  scanf("%d",&op);
  cls;
  }
}

void configUser(void){
  int op = 1;

  while(op != 0)
  {
  printf("\n---------------------------------\n");
  printf("              Op??es de Usuario\n");  
  printf("---------------------------------\n");
  printf(" [1] Cadrastrar\n [2] Atualizar\n [3] Excluir\n [0] Volta\n\n");
  scanf("%d",&op);
  cls;
  }
}


void about (void) {
	cls;
  printf("=================================================\n");
  printf("                         Sobre\n");
  printf("=================================================\n");
  printf("\nSIG-Library: Um Sistema de Controle de Biblioteca.\n");
  printf("\nCriadores:\n");
	printf("\n  Emanuel Oliveira - emanueldasilva011@gmail.com");
	printf("\n  Za? Galv?o - zauhf@gmail.com\n\n\n");
  printf("            2019 - Caic?/RN\n\n");
  printf("==================================================\n");
	clBuf;
	getchar();
	cls;
}


void menu (void) {
  char op = '1';
  do {
    setlocale( LC_ALL, "Portuguese" );
    printf("////////////////////////////////////\n");
    printf("           SIG - Library\n");
    printf("///////////////////////////////////\n");
    printf(" [1] Usuario\n [2] Acervo\n [3] Biblioteca\n [4] Sobre \n [5] Opções\n [0] Sair\n\n");
		printf("Digite: ");
    scanf(" %c",&op);
    if (op >= '0' && op <= '5') {
			switch (op) {
				case '1':
				user();
				break;
				
				case '2':
				livro();
				break;
				
				case '3':
				bibli();
				break;
				
				case '4':
				about();
				break;

				case '5':
				config();
				break;
				
				case '0' :
				break;
			}
    } 
    cls;
  } while (op != '0');
}
