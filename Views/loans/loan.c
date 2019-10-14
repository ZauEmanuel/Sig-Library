#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "../books/book.h"
#include "../users/user.h"
#include "../loans/loan.h"
#include "../../Models/manageFile.h"

#ifndef "user.h"
#include "user.h"
#endif
#ifndef "loan.h"
#include "loan.h"
#endif
#ifndef "../../Models/manageFile.h"
#include "../../Models/manageFiles.h"
#endif

#define cls system("clear||cls");
#define clBuf setbuf(stdin,NULL);


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
		strcpy(loan->unity,book->unity);
		recLoan();
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
