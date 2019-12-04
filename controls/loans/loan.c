#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

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

Loan* searchLoan(char* cpf, char* isn){
	FILE* f = fopen("loans.bin", "rb");
	Loan* loan;
	int found;
	cls;
	if(!f){
		return NULL;
	}
	loan = (Loan*) malloc(sizeof(Loan));
	found = 0;
	while((!found) && (fread(loan, sizeof(Loan), 1, f))) {
		if ((strcmp(loan->cpf, cpf) == 0) && (strcmp(loan->ISN, isn) == 0)){
			found = 1;
		}
	}
	fclose(f);
	if (found)
		return loan;
}

void listLoan(void){
	Book *book = (Book*) malloc(sizeof(Book));
	User *user = (User*) malloc(sizeof(User));
	Loan *loan = (Loan*) malloc(sizeof(Loan));
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
	Book *book = (Book*) malloc(sizeof(Book));
	User *user = (User*) malloc(sizeof(User));
	Loan *loan = (Loan*) malloc(sizeof(Loan));
	char date[10];
	int op = 1;
	char cpf[12] = "";
	char isn[13] = "";

	struct tm *data_;
	time_t segundos;
	time(&segundos);   
	data_ = localtime(&segundos);
	strftime(&date, 10, "%d/%m/%g", data_);

	do {
		printf("\n||||||||||||||||||||||||||||||||||||||||||||||\n");
		printf("             Realizar Empréstimo\n");
		printf("||||||||||||||||||||||||||||||||||||||||||||||\n\n");

		printf("Digite cpf: ");
		user = searchUser(cpf);

		if(!(user->loans > 3)){
			printf("\nNúmero máximo de empréstimos antigido!");
			clBuf; getchar();
			return;
		}

		do{
			printf("\n Digite o ISBN: ");
			scanf(" %s",isn);
			op = searchBook(isn);
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
		strcpy(loan->data,date);
		loan->unity = book->unity;
		recLoan(loan);
	} while(op != 0);
	free(book);
	free(user);
	free(loan);
}

void devolution(void) {
	Book *book = (Book*) malloc(sizeof(Book));
	User *user = (User*) malloc(sizeof(User));
	Loan *loan = (Loan*) malloc(sizeof(Loan));
	char op = '1';
	char controlP = '0';
	char bookD[13] = "";
	char cpf[11] = "";

	char date[10];
	struct tm *data_;
	time_t segundos;
	time(&segundos);   
	data_ = localtime(&segundos);
	strftime(&date, 10, "%d/%m/%g", data_);

	do{
		// Busca de livro
		do{
			printf("Digite o código de identificação do livro: ");
			scanf(" %s",bookD);
			book = searchBook(bookD);
			if (book == NULL){
				printf("O Livro não foi encontrado: \n[1] Tentar novamente \n[0] Sair\n Digite: ");
				scanf(" %c",&controlP);
				if (controlP == '0'){
					free(book);
					free(user);
					free(loan);
					return;
				}
				if (controlP == '1')
					continue;
			}
		} while (controlP !='0');

		// Busca de usuário
		do{
			printf("Digite o CPF: ");
			scanf(" %s",user);
			user = searchBook(user);
			if (user == NULL){
				printf("O usuário não foi encontrado: \n[1] Tentar novamente \n[0] Sair\n Digite: ");
				scanf(" %c",&controlP);
				if (controlP == '0'){
					free(book);
					free(user);
					free(loan);
					return;
				}
				if (controlP == '1')
					continue;
			}
		} while (controlP !='0');

		// Verificação de emprestimo
		do{
			loan = searchLoan(user->cpf,book->ISN);
			if (loan == NULL){
				printf("O emprestimo não pertence ao usuário, ou, não foi encontrado: \n[1] Tentar novamente \n[0] Sair\n Digite: ");
				scanf(" %c",&op);
				if (op == '0'){
					free(book);
					free(user);
					free(loan);
					return;
				}
				if (op == '1')
					continue;
			}
		} while (controlP !='0');
	}while(op != 0);

	if (op == '0'){
		free(book);
		free(user);
		free(loan);
		return;
	}

	do {
		showInfoBook(book);
		showInfoUser(user);
		printf("Data de empréstimo: %s",loan->data);
		printf("Data Atual: %s",date);
		clBuf; getchar();
		printf("\n||||||||||||||||||||||||||||||||||||||||||||||\n");
		printf("                   Devolução \n");
		printf("||||||||||||||||||||||||||||||||||||||||||||||\n\n");
		printf("\n-- Continuar:\n [1] SIM \n [0] NÃO \n Digite: ");
		scanf("%c",&op);
		if(op == '0'){
			free(book);
			free(user);
			free(loan);
			return;
		}
		FILE* fUser = fopen("users.bin", "r+b");
		user->loans = user->loans-1;
		fseek(fUser, (-1)*sizeof(User), SEEK_CUR);
		fwrite(user, sizeof(User), 1, fUser);
		fclose(fUser);

		FILE* fBook = fopen("books.bin", "r+b");
		book->status = 'D';
		fseek(fBook, (-1)*sizeof(Book), SEEK_CUR);
		fwrite(book, sizeof(Book), 1, fBook);
		fclose(fBook);

		FILE* fLoan = fopen("loans.bin", "r+b");
		loan->status = '0';
		fseek(fLoan, (-1)*sizeof(Loan), SEEK_CUR);
		fwrite(loan, sizeof(Loan), 1, fLoan);
		fclose(fLoan);
		
		printf("\nDevolução realizada com sucesso com sucesso!\n");
		clBuf;
		printf("	::: ENTER :::");
		getchar();
	} while(op != 0);
	free(book);
	free(user);
	free(loan);
}