#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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



// Lista todos os empréstimo//
void listLoan(void){
	Book *book = calloc(1,sizeof(Book));
	User *user = calloc(1,sizeof(user));
	Loan *loan = calloc(1,sizeof(Loan));
	FILE *f = fopen("loans.bin","rb");
	if(!f){
		printf("Erro ao tantar abrir o arquivo.\n");
		return;
	}
	while(fread(loan,sizeof(Loan),1,f)){
		showInfoUser(user);
		showInfoBook(book);
		printf("\n\n");
	}
	clBuf;
	printf("::: ENTER :::"); 
	getchar();
	fclose(f);
	free(book);
	free(user);
	free(loan);
}


// Grava em arquivo binário //
void recLoan(Loan *loan){
	FILE *f = fopen("loans.bin","ab");
	if(f==NULL){
		printf("ERRO ao criar arquivo.\n");
		clBuf; 
		printf("::: ENTER :::"); 
		getchar();
		return;
	}else{
		fwrite(loan, sizeof(Loan),1,f);
		fclose(f);
	}
}

void loan(void) {
	Book *book = calloc(1,sizeof(Book));
	User *user = calloc(1,sizeof(user));
	Loan *loan = calloc(1,sizeof(Loan));
	int op = 1;

	do {
		printf("\n||||||||||||||||||||||||||||||||||||||||||||||\n");
		printf("             Realizar Empréstimo\n");
		printf("||||||||||||||||||||||||||||||||||||||||||||||\n\n");

		do{
			op = searchUser(user);
			if(op == 2)
				return;
		}while(op == 0);

		if(!(user->loans < 3)){
			printf("\nNúmero máximo de empréstimos antigido!");
			clBuf; getchar();
			return;
		}

		do{
			op = searchBook(book,'D');
			if(op == 2)
				return;
		}while(op == 0);

		showInfoBook(book);
		showInfoUser(user);
		clBuf; getchar();
		printf("Continuar:\n [1] SIM \n [0] NÃO \n Digite: ");
		scanf("%d",&op);
		if(op == 0)
			return;
		strcpy(loan->cpf,user->cpf);
		strcpy(loan->ISN,book->ISN);
		strcpy(loan->unity,book->unity); //Está errado pois char strcpy(char *, constant char *) só aceita tipo ponteiro char e retorna tipo char.
		recLoan(loan);
	} while(op != 0);
	free(book);
	free(user);
	free(loan);
	//op = writeDataLoan(loan,'E');
	//if(op==1){
	//	printf("\nEmpréstimo realizado com sucesso!");
	//	clBuf; printf("::: ENTER :::"); getchar();
	//}
}


void devolution(void) {
	Book *book = calloc(1,sizeof(Book));
	User *user = calloc(1,sizeof(User));
	Loan *loan = calloc(1,sizeof(Loan));
	int op = 1;

	do {
		printf("\n||||||||||||||||||||||||||||||||||||||||||||||\n");
		printf("                   Devolução \n");
		printf("||||||||||||||||||||||||||||||||||||||||||||||\n\n");

		do{
			op = searchUser(user);
			if(op == 2)
				return;
		}while(op == 0);

		do{
			op = searchBook(book,'I');
			if(op == 2)
				return;
		}while(op == 0);

		showInfoBook(book);
		showInfoUser(user);
		clBuf; getchar();
		printf("\n-- Continuar:\n [1] SIM \n [0] NÃO \n Digite: ");
		scanf("%d",&op);
		if(op == 0)
			return;
		user->loans = user->loans-1;
	} while(op != 0);
	free(book);
	free(user);
	free(loan);
	//op = writeDataLoan(loan,'D');
	//if(op == 1)
	//	printf("Livro devolvido com sucesso!");
	//	clBuf; printf("::: ENTER :::"); getchar();
}
