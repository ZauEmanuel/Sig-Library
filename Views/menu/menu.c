#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#ifndef BOOK_H
	#include "../books/book.h"
#endif
  
#ifndef USER_H
	#include "../users/user.h"
#endif
  
#ifndef LOAN_H
	#include "../loans/loan.h"
#endif

#define cls system("clear||cls");
#define clBuf setbuf(stdin,NULL);

void acervo(void){
	char op = '1';
  do {
    cls;
    do{
      printf("\n|||||||||||||||||||||||||||||||||\n");
      printf("              Acervo");
      printf("\n|||||||||||||||||||||||||||||||||\n");
      printf(" [1] Listar Acervo\n [2] Pesquisar material\n [3] Cadastrar material\n");
      printf(" [4] Atualizar material\n [5] Remover material\n [0] Voltar\n\n");
      printf("Digite: ");
      clBuf; scanf(" %c",&op); clBuf;
      cls;
    } while(!(op >= '0' && op <= '5'));
    switch (op){

      case '0':
        return;
      
      case '1':
        listBook();
        break;
      case '2':
        //searchBook(book,'b');
        //showInfoBook(book);
        break;
      
      case '3':
        newBook();
        break;
      
      case '4':
        //updateBook();
        break;
      
      case '5':
        //removeBook();
        break;
    }
  } while(op != '0');
  cls;
}


void users(void){
  User *user = calloc(1,sizeof(User));
  char op = '1';
  cls;
  do { 
    printf("\n|||||||||||||||||||||||||||||||||\n");
    printf("              Usuario\n");
    printf("|||||||||||||||||||||||||||||||||\n");
    printf(" [1] Pesquisar\n [2] Cadastrar\n [3] Atualizar\n [4] Remover\n [5] Listar Usuários\n [0] Voltar\n\n");
		printf("Digite: ");
    clBuf; scanf(" %c",&op); clBuf;
    switch (op) {
      case '0':
        return;

      case '1':
        searchUser(user);
        //showInfoUser(user);
        break;
      
      case '2':
        cls;
        newUser();
        cls;
        break;

      case '3':
        updateUser();
        break;
      
      case '4':
        cls;
        removeUser();
        cls;
        break;
        
      case '5':
        cls;
        listUser();
        break;
    }
  } while (op != '0');
  cls;
  free(user);	
}


void library(void){
  char op = '1';
  printf("\n////////////////////////////////////\n");
  printf("             Biblioteca\n");
  printf("///////////////////////////////////\n");
  printf(" [1] Empréstimo\n [2] Devolução\n [3] Relatórios\n [0] Voltar\n\n");
  do { 
		printf("Digite: ");
    scanf("%c",&op);
    switch (op){

      case '0':
        break;

      case '1':
        //Função Relatório
        break;
      case '2':
        //Função Relatório
        break;
      case '3':
        //Função Relatório
        break;
    }
  } while (op != '0');
  cls;
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
	clBuf; getchar(); clBuf;
	cls;
}


int main(void) {
  char op = '1';
  setlocale( LC_ALL, "Portuguese" );
  do {
    cls;
    printf("////////////////////////////////////\n");
    printf("           SIG - Library\n");
    printf("///////////////////////////////////\n");
    printf(" [1] Usuario\n [2] Acervo\n [3] Biblioteca\n [4] Sobre \n [0] Sair\n\n");
		printf("Digite: ");
    scanf(" %c",&op);
    if (op >= '0' && op <= '5') {
      cls;
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
				
				case '0' :
				break;
			}
    } 
    cls;
  } while (op != '0');
  return 0;
}
