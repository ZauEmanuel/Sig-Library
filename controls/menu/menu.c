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
      clBuf;
      scanf(" %c",&op);
      clBuf;
      cls;
    } while(!(op >= '0' && op <= '5'));
    switch (op){

      case '0':
        return;
      
      case '1':
        listBook();
        break;
      case '2':
        searchBookShow();
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
  cls;
}


void users(void){
  char op = '1';
  cls;
  do { 
    printf("\n|||||||||||||||||||||||||||||||||\n");
    printf("              Usuario\n");
    printf("|||||||||||||||||||||||||||||||||\n");
    printf("\n [1] Pesquisar\n [2] Cadastrar\n [3] Atualizar\n [4] Remover\n [5] Listar Usuários\n [0] Voltar\n\n");
		printf("Digite: ");
    clBuf;
    scanf(" %1[^\n]",&op);
    clBuf;
    switch (op) {
      case '0':
        return;

      case '1':
        cls;
        searchUserShow();
        break;
      
      case '2':
        cls;
        newUser();
        cls;
        break;

      case '3':
        cls;
        updateUser();
        cls;
        break;
      
      case '4':
        cls;
        removeUser();
        cls;
        break;
        
      case '5':
        cls;
        listUser();
        cls
        break;
    }
  } while (op != '0');
  cls;
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
  printf("===================================================================================\n");
  printf("                                    Sobre\n");
  printf("===================================================================================\n");
  printf("\n              SIG-Library: Um Sistema de Controle de Biblioteca.\n");
  printf("\nCriadores:\n");
	printf("\n  Emanuel Oliveira - emanueldasilva011@gmail.com - https://github.com/emanuelOliver");
	printf("\n  Zaú Galvão       -       zauhf@gmail.com       - https://github.com/ZauJulio\n\n\n");
  printf("                                2019 - Caicó/RN\n\n");
  printf("====================================================================================\n");
	clBuf; getchar(); clBuf;
	cls;
}


int main(void) {
  int op;
  do {
    cls;
    op = 1;
    printf("\n\n////////////////////////////////////\n");
    printf("           SIG - Library\n");
    printf("///////////////////////////////////\n");
    printf("\n [1] Usuario\n [2] Acervo\n [3] Empréstimos\n [4] Sobre \n [0] Sair\n\n");
		printf("Digite: ");
    clBuf;
    scanf(" %d",&op);
    clBuf;
    printf(" %d",op);
    if (op >= 0 && op <= 5) {
      cls;
      if (op == 1){
				users();
      } if (op == 2){
				acervo();
      } if (op == 3){
				library();
      } if (op == 4){
				about();
      } if (op == 0){
				break;
			}
      cls;
    }
    printf("%d",op);
  } while (op != 0);
  return 0;
}
