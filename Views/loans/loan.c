#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "../books/book.h"
#include "../users/user.h"
#include "../loans/loan.h"


#define cls system("clear||cls");
#define clBuf setbuf(stdin,NULL);


void loan(void) {
	Book *book = calloc(sizeof *book, 0);
	User *user = calloc(sizeof *user, 0);
	Loan *loan = calloc(sizeof *loan, 0);
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
	} while(op != 0);
	//op = writeDataLoan(loan,'E');
	//if(op==1){
	//	printf("\nEmpréstimo realizado com sucesso!");
	//	clBuf; printf("::: ENTER :::"); getchar();
	//}
}


void devolution(void) {
	Book *book = calloc(sizeof *book, 0);
	User *user = calloc(sizeof *user, 0);
	Loan *loan = calloc(sizeof *loan, 0);
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
	//op = writeDataLoan(loan,'D');
	//if(op == 1)
	//	printf("Livro devolvido com sucesso!");
	//	clBuf; printf("::: ENTER :::"); getchar();
}