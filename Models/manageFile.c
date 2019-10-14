#include <stdio.h>
#include <stdlib.h>
#include "../Views/users/user.h"
#include "../Views/books/book.h"
#include "../Views/loans/loan.h"


// Lista todos os usuários //
void listUser(void){
	User user;
	FILE *f = fopen("users.bin","rb");
	if(!f){
		printf("Erro ao tantar abrir o arquivo.\n");
		return;
	}
	while(fread(user,sizeof(User),1,f)){
		showInfoUser(user);
		printf("\n\n");
	}
	fclose(f);
}


// Grava usuário em arquivo binário //
void recUser(User *user){
	FILE *f = fopen("user.bin","ab");
	if(f==NULL){
		printf("ERRO ao criar arquivo.\n");
		return;
	}else{
		fwrite(user, sizeof(User),1,f);
		fclose(f);
	}
}


// Lista todos os livros //
void listBook(void){
	User user;
	FILE *f = fopen("users.bin","rb");
	if(!f){
		printf("Erro ao tantar abrir o arquivo.\n");
		return;
	}
	while(fread(user,sizeof(User),1,f)){
		showInfoBook(user);
		printf("\n\n");
	}
	fclose(f);
}


// Grava livro em arquivo binário //
void recBook(User *user){
	FILE *f = fopen("user.bin","ab");
	if(f==NULL){
		printf("ERRO ao criar arquivo.\n");
		return;
	}else{
		fwrite(user, sizeof(User),1,f);
		fclose(f);
	}
}


// Lista todos os empréstimo//
void listLoan(void){
	User user;
	FILE *f = fopen("users.bin","rb");
	if(!f){
		printf("Erro ao tantar abrir o arquivo.\n");
		return;
	}
	while(fread(user,sizeof(User),1,f)){
		showInfoUser(user);
		showInfoBook(user);
		printf("\n\n");
	}
	fclose(f);
}


// Grava em arquivo binário //
void recLoan(User *user){
	FILE *f = fopen("user.bin","ab");
	if(f==NULL){
		printf("ERRO ao criar arquivo.\n");
		return;
	}else{
		fwrite(user, sizeof(User),1,f);
		fclose(f);
	}
}

