#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "../../Controllers/entries/user/entriesUser.h"
#include "../../Models/checks/valid.h"
#include "user.h"


#define cls system("clear||cls");
#define clBuf setbuf(stdin,NULL);

void listUser(void){
	User user;
	FILE *f = fopen("users.bin","rb");
	if(!f){
		printf("Erro ao tantar abrir o arquivo.\n");
		return;
	}
	while(fread(&user,sizeof(User),1,f)){
		showInfoUser(&user);
	}
	fclose(f);
}


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



void showInfoUser(User *user){
	setlocale( LC_ALL, "Portuguese" );
	printf(" [1] Name :     %s \n [4] CEP :      %s \n",user->name,user->cep);
	printf(" [2] CPF :      %s \n [5] Rua :      %s \n",user->cpf,user->rua);
	printf(" [3] Número :   %s \n [6] email :    %s \n",user->num,user->email);
}


void newUser(void) {
	User *user = calloc(sizeof *user, 0);
	char op = '1';
	do {
		printf("\n||||||||||||||||||||||||||||||||||||||||||||||\n");
		printf("                 Novo Usuario\n");
		printf("||||||||||||||||||||||||||||||||||||||||||||||\n\n");
		printf("        ::: DIGITE 0 PARA VOLTAR :::\n");
		op = inputUserName(user->name);
		if(op == '0')
			return;
		
		op = inputUserCPF(user->cpf);
		if(op == '0')
			return;
		
		printf("\n\t::Endereço::");
		op = inputUserRua(user->rua);
		if(op == '0')
			return;
		
		op = inputUserNum(user->num);
		if(op == '0')
			return;
		
		op = inputUserCEP(user->cep);
		if(op == '0')
			return;
		
		op = inputUserEmail(user->email);
		if(op == '0')
			return;
		
		showInfoUser(user);
		printf("::: ENTER :::");
		getchar();
		printf("Continuar:\n [1] SIM \n [0] NÃO \n Digite: ");
		scanf("%c",&op);
		recUser(user);	
	} while(op != '0');
	free(user);
	//op = writeDataUser(user,'n');
	//if(op==1) {
	//	printf("Usuário atualizado com sucesso!");
	//	clBuf; printf("::: ENTER :::"); getchar();
	//}
}


int searchUser(User *user) {
	char any[256] = "";
	char op = ' ';
	op = '1';
	printf("  ::: PESQUISAR USUÁRIO :::");
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
	User *userUp = calloc(sizeof *userUp, 0);
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
					op = inputUserName(userUp->name);
					if(op == '0')
						return;
					break;
				
				case '2':
					op = inputUserCPF(userUp->cpf);
							if(op == '0')
								return;
					break;
				
				case '3':
					op = inputUserNum(userUp->num);
					if(op == '0')
						return;
					break;

				case '4':
					op = inputUserCEP(userUp->cep);
					if(op == '0')
						return;
					break;

				case '5':
					op = inputUserRua(userUp->rua);
					if(op == '0')
						return;
					break;

				case '6':
					op = inputUserEmail(userUp->email);
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
	User *user = calloc(sizeof *user, 0);
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