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
	char op;
  do {
    cls;
    printf("\n|||||||||||||||||||||||||||||||||\n");
    printf("              Acervo");
    printf("\n|||||||||||||||||||||||||||||||||\n");
    printf(" [1] Listar Material\n [2] Pesquisar Material\n [3] Cadastrar Material\n");
    printf(" [4] Atualizar Material\n [5] Remover material\n [0] Voltar\n\n");
    printf("Digite: ");
    clBuf; scanf(" %c",&op); clBuf;
    cls;
    if (op == '0')
      return;
    if (op == '1'){
      listBook();
    }
    if (op == '2')
      searchBookShow();
    if (op == '3')
      newBook();
    if (op == '4')
      updateBook();
    if (op == '5')
      removeBook();
  } while(op != '0');
  cls;
}

void users(void){
  char op;
  do { 
    cls;
    printf("\n|||||||||||||||||||||||||||||||||\n");
    printf("              Usuario\n");
    printf("|||||||||||||||||||||||||||||||||\n");
    printf("\n [1] Listar Usuários\n [2] Pesquisar Usuário\n [3] Cadastrar Usuário\n [4] Atualizar Usuário\n [5] Remover Usuário\n [6] Listar Diretas de Usuários\n [0] Voltar\n\n");
		printf("Digite: ");
    clBuf; scanf(" %c",&op); clBuf;
    if (op == '0')
      return;
    if (op == '1')
      listUser();
    if (op == '2')
      searchUserShow();
    if (op == '3')
      newUser();
    if (op == '4')
      updateUser();
    if (op == '5')
      removeUser();
    if (op == '6'){
      Lista* lUser;
      lUser = listaDiretaUsers();
      showInfoUserList(lUser);
      getchar();
      getchar();
    }
  } while (op != '0');
  cls;
}

void library(void){
  char op;
  do {
    cls;
    printf("\n////////////////////////////////////\n");
    printf("             Biblioteca\n");
    printf("///////////////////////////////////\n");
    printf(" [1] Empréstimo\n [2] Devolução\n [3] Lista de Empréstimos\n [0] Voltar\n\n");
		printf("Digite: ");
    scanf("%c",&op);
    if (op == '0')
      break;
    if (op == '1')
      loan();
    if (op == '2')
      devolution();
    if (op == '3')
      listLoan();
  } while (op != '0');
  cls;
}

void about(void) {
	cls;
  printf("===================================================================================\n");
  printf("                                    Sobre\n");
  printf("===================================================================================\n");
  printf("\n              SIG-Library: Um Sistema de Controle de Biblioteca.\n");
  printf("\n                 Créditos ao Orientador: Prof. Flavius Gorgônio.\n");
  printf("\n         Projeto de 2º Período do curso de Sistemas de informação da UFRN.  \n");
  printf("\n Criadores:\n");
	printf("\n  Emanuel Oliveira - emanueldasilva011@gmail.com - https://github.com/EmanuelOliveh");
	printf("\n  Zaú Galvão       -       zauhf@gmail.com       - https://github.com/ZauJulio\n\n\n");
  printf("                                2019 - Caicó/RN\n\n");
  printf("====================================================================================\n");
	clBuf; getchar(); getchar(); clBuf;
	cls;
}

int main(void) {
  char op;
  do {
    cls;
    printf("\n\n////////////////////////////////////\n");
    printf("           SIG - Library\n");
    printf("///////////////////////////////////\n");
    printf("\n [1] Usuario\n [2] Acervo\n [3] Empréstimos\n [4] Sobre \n [0] Sair\n\n");
		printf("Digite: ");
    clBuf; scanf(" %c",&op); clBuf;
    if (op == '0')
      break;
    if (op == '1')
      users();
    if (op == '2')
      acervo();
    if (op == '3')
      library();
    if (op == '4')
      about();
  } while (op != '0');
  return 0;
}
