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
		clBuf; getchar();
		getchar();
		return;
	}
	while(fread(user,sizeof(User),1,f)){
		showInfoUser(user);
		printf("\n\n");
		free(user);
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
	if(f==NULL){
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
	printf(" [1] Nome :    %s \n [2] CEP :     %s \n",user->name,user->cep);
	printf(" [3] CPF :     %s \n [4] Rua :     %s \n",user->cpf,user->rua);
	printf(" [5] Número :  %s \n [6] e-mail :   %s \n",user->num,user->email);
}


void newUser(void) {
	User *user = calloc(1,sizeof(User));
	char op = '1';
	printf("\n||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("                 Novo Usuario\n");
	printf("||||||||||||||||||||||||||||||||||||||||||||||\n\n");
	printf("        ::: DIGITE 0 PARA VOLTAR :::\n");
	op = inputUserName(user);
	if(op == '0')
		return;
	
	op = inputUserCPF(user);
	if(op == '0')
		return;
	
	op = inputUserRua(user);
	if(op == '0')
		return;
	
	op = inputUserNum(user);
	if(op == '0')
		return;
	
	op = inputUserCEP(user);
	if(op == '0')
		return;
	
	op = inputUserEmail(user);
	if(op == '0')
		return;
	cls;
	showInfoUser(user);
	printf("	::: ENTER :::");
	getchar();
	printf(" --Continuar:\n    [1] SIM\n    [0] NÃO\n Digite: ");
	clBuf; scanf("%c",&op); clBuf;
	if(op=='1')
		recUser(user);
	free(user);
	return;
}


int searchUser(User *user) {
	char any[256] = "";
	char op = ' ';
	op = '1';
	printf("  ::: PESQUISAR USUÁRIO :::\n");
	printf("::: DIGITE 0 PARA VOLTAR :::\n");
	do {
		memset(any, 0, sizeof any);
		printf("Pesquisar: ");
		scanf("%s",any);
		if(strlen(any) == 1 && any[0] == 0){
			cls;
			return 2;
		} else {
			op = '0';
		}
	} while(op != '0');
	cls;
	//op = search(user,any,'u');
	if(op == 1){
		return 1;
	} else {
		printf("\nUsuário não encontrado.");
		clBuf; getchar();
		return 0;
	}
}


void updateUser(void) {
	char op = '1';
	char controlP= '0';
	//User *userUp = calloc(sizeof *userUp, 0);
	User *userUp = calloc(1,sizeof(User));
	do {
		do{
			controlP = searchUser(userUp);
		 	if(controlP == 0){
				printf("Usuário não encontrado.\n");
				printf("Pesquisar novamente [1]\n");
				printf("Voltar              [0]\n");
				printf("Digite: ");
				clBuf; scanf("%c",&controlP); clBuf;
			 } if(op == '0'){
				 return;
			 }
		} while (controlP == '0');
		setlocale( LC_ALL, "Portuguese" );
		printf("\n||||||||||||||||||||||||||||||||||||||||||||||");
		printf("\n|||          Atualizar informações         |||");
		printf("\n||||||||||||||||||||||||||||||||||||||||||||||\n");
		printf("        ::: DIGITE 0 PARA VOLTAR :::\n");
		printf("\n   ::: Informações Atuais Do Usuário :::\n");
		showInfoUser(userUp);
		printf("Digite: ");
		scanf(" %c",&op);
		if(op>='0' && op<='6'){
			switch (op) {

				case '0':
					return;

				case '1':
					op = inputUserName(userUp);
					if(op == '0')
						return;
					break;
				
				case '2':
					op = inputUserCPF(userUp);
							if(op == '0')
								return;
					break;
				
				case '3':
					op = inputUserNum(userUp);
					if(op == '0')
						return;
					break;

				case '4':
					op = inputUserCEP(userUp);
					if(op == '0')
						return;
					break;

				case '5':
					op = inputUserRua(userUp);
					if(op == '0')
						return;
					break;

				case '6':
					op = inputUserEmail(userUp);
					if(op == '0')
						return;
					break;
			}
		}
		showInfoUser(userUp);
		printf("::: ENTER :::");
		printf("Continuar:\n [1] SIM \n [0] NÃO \n Digite: ");
		scanf("%c",&op);	
	} while(op != '0');
	free(userUp);
	//op = writeDataUser(userUp,'uR');
	//if(op==1){
	//	printf("Usuário atualizado com sucesso!");
	//	clBuf; printf("::: ENTER :::"); getchar();
	//}
}


void removeUser(void){
	User *user = calloc(1,sizeof(User));
	int op = 0;
	printf("\n||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("                Remover Usuário\n");
	printf("||||||||||||||||||||||||||||||||||||||||||||||\n\n");

	do{
		op = searchUser(user);
		if(op == 2)
			return;
	}while(op == 0);

	showInfoUser(user);
	clBuf; printf("::: ENTER :::"); getchar();
	printf("Continuar:\n [1] SIM \n [0] NÃO \n Digite: ");
	scanf("%d",&op);
	free(user);
	//if(op == 1){
	//	op = writeDataUser(user,'R');
	//	if(op == 1){
	//		printf("Usuário removido com sucesso!");
	//		clBuf; printf("::: ENTER :::"); getchar();
	//	}
	//}
}
