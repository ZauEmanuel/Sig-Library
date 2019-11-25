#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#ifndef ENTRIESUSER_H
	#include "../../Controllers/entries/user/entriesUser.h"
#endif

#ifndef VALID_H
	#include "../../Models/valid.h"
#endif

#define cls system("clear||cls");
#define clBuf setbuf(stdin,NULL);

// Lista todos os usuários 
void listUser(void){
	User *user = (User*) malloc(sizeof(user));
	FILE *f = fopen("users.bin","rb");
	if(!f){
		printf("Erro ao tantar abrir o arquivo.\n");
		printf("	::: ENTER :::\n"); 
		clBuf;
		getchar();
		getchar();
		return;
	}
	while((fread(user,sizeof(User),1,f)) && (user->status == '1')){
		showInfoUser(user);
		printf("\n\n");
	}
	clBuf;
	printf("	::: ENTER :::"); 
	getchar();
	getchar();
	fclose(f);
	free(user);
	cls;
	/*
	  user = (User*) malloc(sizeof(User));
	  while(fread(user, sizeof(User), 1, f)) {
	    if (user->status == '1') {
	      showInfoUser(user);
	    }
	  }
	  fclose(f);
	  free(user);
	*/
}


// Grava usuário em arquivo binário 
void recUser(User *user){
	FILE *f = fopen("users.bin","ab");
	if(f == NULL){
		printf("ERRO ao criar arquivo.\n");
		clBuf; 
		printf("::: ENTER :::"); 
		getchar();
		return;
	}else{
		fwrite(user, sizeof(User),1,f);
		fclose(f);
	}
}

void showInfoUser(User *user){
	printf("\n===============================\n\n");
	printf(" [1] Nome :    %s \n [2] CPF :     %s \n",user->name,user->cpf);
	printf(" [3] Rua :     %s \n [4] Número :  %s \n",user->rua,user->num);
	printf(" [5] CEP :     %s \n [6] e-mail :  %s \n",user->cep,user->email);
	printf("\n\n===============================\n");
}


void newUser(void) {
	User *user = calloc(1,sizeof(User));
	char op = '1';
	printf("\n||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("                 Novo Usuario\n");
	printf("||||||||||||||||||||||||||||||||||||||||||||||\n\n");
	printf("        ::: DIGITE 0 PARA VOLTAR :::\n");
	op = inputUserName(user);
	if(op == '0'){
		free(user);
		return;
	}
	
	op = inputUserCPF(user);
	if(op == '0'){
		free(user);
		return;
	}
	
	op = inputUserRua(user);
	if(op == '0'){
		free(user);
		return;
	}
	
	op = inputUserNum(user);
	if(op == '0'){
		free(user);
		return;
	}
	
	op = inputUserCEP(user);
	if(op == '0'){
		free(user);
		return;
	}
	
	op = inputUserEmail(user);
	if(op == '0'){
		free(user);
		return;
	}
	cls;
	showInfoUser(user);
	printf("	::: ENTER :::");
	getchar();
	printf(" --Continuar:\n    [1] SIM\n    [0] NÃO\n Digite: ");
	clBuf;
	scanf("%c",&op);
	if(op=='1'){
		user->status = '1';
		recUser(user);
		//free(user);
	}
	clBuf;
	free(user);
}


void searchUser(void){
	FILE* f = fopen("users.bin", "rb");
	User* user;
	int found;
	char cpf[12];
	cls;
	if(!f){
		printf("Erro ao tantar abrir o arquivo.\n");
		printf("	::: ENTER :::\n"); 
		clBuf;
		getchar();
		getchar();
		return;
	}
	printf("\n\n");
	printf("Informe o cpf: ");
	scanf(" %11[^\n]", cpf);
	user = (User*) malloc(sizeof(User));
	found = 0;
	while((!found) && (fread(user, sizeof(User), 1, f))) {
	if ((strcmp(user->cpf, cpf) == 0) && (user->status == '1')){
		found = 1;
	}
	}
	fclose(f);
	if (found){
		showInfoUser(user);
	} else {
		printf("O user %s não foi encontrado...\n", cpf);
	}
	printf("	::: ENTER :::");
	clBuf;
	getchar();
	getchar();
	clBuf;
	cls;
	free(user);
}


void updateUser(void) {
  FILE* f = fopen("users.bin", "r+b");
  User* user;
  int found;
  char op;
  char cpf[12];
  cls;
  if(!f){
		printf("Erro ao tantar abrir o arquivo.\n");
		printf("	::: ENTER :::\n"); 
		clBuf;
		getchar();
		getchar();
		return;
	}
  	printf("\n\n");
	printf("\n||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("                 Atualizar Usuario\n");
	printf("||||||||||||||||||||||||||||||||||||||||||||||\n\n");

  printf("Informe o cpf do usuário a ser alterado: ");
  scanf(" %11[^\n]", cpf);
  user = (User*) malloc(sizeof(User));
  found = 0;
  while((!found) && (fread(user, sizeof(User), 1, f))) {
   if ((strcmp(user->cpf, cpf) == 0) && (user->status == '1')) {
     found = 1;
   }
  }

   if (found) {
	showInfoUser(user);
	clBuf;
	printf("	::: ENTER :::");
	getchar();
	printf("\n --Continuar:\n    [1] SIM\n    [0] NÃO\n Digite: ");
	clBuf;
	scanf("%c", &op);
	clBuf;
	cls;
	if(op=='1'){
		cls;
    	printf("\n||||||||||||||||||||||||||||||||||||||||||||||\n");
		printf("                 Atualizar Usuario\n");
		printf("||||||||||||||||||||||||||||||||||||||||||||||\n\n");
		printf("        ::: DIGITE 0 PARA VOLTAR :::\n");
		showInfoUser(user);
		op = inputUserName(user);
		if(op == '0'){
			free(user);
			return;
		}
		
		op = inputUserCPF(user);
		if(op == '0'){
			free(user);
			return;
		}
		
		op = inputUserRua(user);
		if(op == '0'){
			free(user);
			return;
		}
		
		op = inputUserNum(user);
		if(op == '0'){
			free(user);
			return;
		}
		
		op = inputUserCEP(user);
		if(op == '0'){
			free(user);
			return;
		}
		
		op = inputUserEmail(user);
		if(op == '0'){
			free(user);
			return;
		}
		cls;
		showInfoUser(user);
		printf("\n --Deseja REALMENTE continuar?\n    [1] SIM\n    [0] NÃO\n Digite: ");
		clBuf;
		scanf("%c",&op);
		clBuf;
		cls;
		if(op == '1'){
			user->status = '1';
			fseek(f, (-1)*sizeof(User), SEEK_CUR);
			fwrite(user, sizeof(User), 1, f);
			printf("\nDados alterados com sucesso!\n");
			clBuf;
			printf("	::: ENTER :::");
			getchar();
			getchar();
		}
    } else {
		printf("\nOperação cancelada\n");
		clBuf;
		printf("	::: ENTER :::");
		getchar();
		getchar();
    }
  } else {
		printf("O usuário não foi encontrado...\n");
		clBuf;
		printf("	::: ENTER :::");
		getchar();
		getchar();
  }
  free(user);
  fclose(f);
}



int searchUser(User *user) {
	char any[256] = "";
	char op = ' ';
	op = '1';
	printf("  ::: PESQUISAR USUÁRIO :::\n");
	printf("::: DIGITE 0 PARA VOLTAR :::\n");
	do {
		memset(any, 0, sizeof any);
		printf("Digite o CPF: \n");
		scanf("%s",any);
		if(strlen(any) == 1 && any[0] == 0){
			cls;
			return 2;
		} else {
			op = '0';
		}
	} while(op != '0');
	cls;
	if(op == '1'){

		return 1;
	} else {
		printf("\nUsuário não encontrado.");
		clBuf; getchar();
		return 0;
	}
}



void removeUser(void) {
	FILE* f = fopen("users.bin", "r+b");
	User* user;
	int found;
	char op;
	char cpf[12];
	cls;
	if(!f){
		printf("Erro ao tantar abrir o arquivo.\n");
		printf("	::: ENTER :::\n"); 
		clBuf;
		getchar();
		getchar();
		return;
	}
  	printf("\n\n");
	printf("\n||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("                 Remover Usuario\n");
	printf("||||||||||||||||||||||||||||||||||||||||||||||\n\n");

  printf("Informe o cpf do usuário a ser removido: ");
  scanf(" %11[^\n]", cpf);
  user = (User*) malloc(sizeof(User));
  found = 0;
  while((!found) && (fread(user, sizeof(User), 1, f))) {
   if ((strcmp(user->cpf, cpf) == 0) && (user->status == '1')) {
     found = 1;
   }
  }
	if (found) {
		showInfoUser(user);
		clBuf;
		printf("	::: ENTER :::");
		getchar();
		printf("\n --Deseja RALMENTE continuar? \n    [1] SIM\n    [0] NÃO\n Digite: ");
		clBuf;
		scanf("%c", &op);
		clBuf;
		cls;
		if(op=='1'){
			user->status = '0';
			fseek(f, (-1)*sizeof(User), SEEK_CUR);
			fwrite(user, sizeof(User), 1, f);
			printf("\nUsuário removido com sucesso!\n");
			clBuf;
			printf("	::: ENTER :::");
			getchar();
			getchar();
		} else {
			printf("\nOperação cancelada\n");
			clBuf;
			printf("	::: ENTER :::");
			getchar();
			getchar();
		}
  } else {
    printf("\nO usuário não foi encontrado...\n");
		clBuf;
		printf("	::: ENTER :::");
		getchar();
		getchar();
  }
  free(user);
  fclose(f);
}