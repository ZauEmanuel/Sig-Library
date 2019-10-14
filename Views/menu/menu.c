#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "../books/book.h"
#include "../users/user.h"
#include "../loans/loan.h"

#define cls system("clear||cls");
#define clBuf setbuf(stdin,NULL);

void acervo(void){
  //Book *book = calloc(sizeof *book, 0);
	Book *book = calloc(1,sizeof(Book));
	char op = '1';
  do {
    do{
      cls;
      printf("\n|||||||||||||||||||||||||||||||||\n");
      printf("              Acervo");
      printf("\n|||||||||||||||||||||||||||||||||\n");
      printf(" [1] Acervo\n [2] Pesquisar material\n [3] Cadastrar material\n");
      printf("[4] Atualizar material\n [5] Remover material\n [0] Voltar\n\n");
      printf("Digite: ");
      scanf(" %c",&op);
    } while(!(op >= '0' && op <= '5'));
    cls;
    switch (op){

      case '0':
        return;
      
      case '1':
        //searchBook(book,'l');
        //showInfoBook(book);
        break;
      
      case '2':
        //searchBook(book,'b');
        //showInfoBook(book);
        break;
      
      case '3':
        newBook();
        break;
      
      case '4':
        updateBook();
        break;
      
      case '5':
        removeBook();
        break;
    }
  } while(op != '0');
  free(book);
  cls;
}

void users(void) {
	char op = '1';
  User *user = calloc(1,sizeof(User));
	cls;
	do {
		cls;
		printf("\n|||||||||||||||||||||||||||||||||\n");
		printf("              Usuario\n");
		printf("|||||||||||||||||||||||||||||||||\n");
		printf(" [1] Pesquisar\n [2] Cadastrar\n [3] Atualizar\n [4] Remover\n [5] Listar Usuários\n [0] Voltar\n\n");
    do {
      printf("Digite: ");
      scanf(" %c",&op);
    } while(!(op >= '0' && op <= '2'));
    cls;
    switch (op) {
      case '0':
        return;

      case '1':
        searchUser(user);
        showInfoUser(user);
        break;
      
      case '2':
        newUser();
        break;

      case '3':
        updateUser();
        break;
      
      case '4':
        removeUser();
        break;
        
      case '5':
        listUser();
        break;
    }
	} while(op != '0');
  free(user);	
  cls;
}

void library(void){
  char op = '1';
  printf("\n////////////////////////////////////\n");
  printf("             Biblioteca\n");
  printf("///////////////////////////////////\n");
  printf(" [1] Relatórios\n [0] Voltar\n\n");
  do { 
		printf("Digite: ");
    scanf("%c",&op);
    switch (op){

      case '0':
        break;

      case '1':
        //Função Relatório
        printf("Função não implementada!\n");
			  getchar();
        break;
    }
  } while (op != '0');
  cls;
}

void config(void){
  char op = '1';

  while(op != 0)
  {
  printf("\n////////////////////////////////////\n");
  printf("              Opções.\n");
  printf("///////////////////////////////////\n");
  scanf("%c",&op);
  cls;
  }
}


void about(void) {
	cls;
  printf("=================================================\n");
  printf("                         Sobre\n");
  printf("=================================================\n");
  printf("\nSIG-Library: Um Sistema de Controle de Biblioteca.\n");
  printf("\nCriadores:\n");
	printf("\n  Emanuel Oliveira - emanueldasilva011@gmail.com");
	printf("\n  Zaú Galvão - zauhf@gmail.com\n\n\n");
  printf("            2019 - Caicó/RN\n\n");
  printf("==================================================\n");
	clBuf;
	getchar();
	cls;
}


int main(void) {
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
				users();
				break;
				
				case '2':
				acervo();
				break;
				
				case '3':
				library();
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
  return 0;
}
