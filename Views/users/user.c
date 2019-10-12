#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "../../Controllers/entries/user/entriesUser.h"
#include "../../Models/checks/valid.h"
#include "user.h"


#define cls system("clear||cls");
#define clBuf setbuf(stdin,NULL);


void showInfoUser(User *user){
	setlocale( LC_ALL, "Portuguese" );
	printf(" [1] Name :     %s \n [4] CEP :      %s \n",user->name,user->cep);
	printf(" [2] CPF :      %s \n [5] Rua :      %s \n",user->cpf,user->rua);
	printf(" [3] Numero :   %s \n [6] email :    %s \n",user->num,user->email);
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
		if(op == '0'){
			return;
		}
		op = inputUserCPF(user->cpf);
		if(op == '0'){
			return;
		}
		printf("\n\t::Endereço::");
		op = inputUserRua(user->rua);
		if(op == '0'){
			return;
		}
		op = inputUserNum(user->num);
		if(op == '0'){
			return;
		}
		op = inputUserCEP(user->cep);
		if(op == '0'){
			return;
		}
		op = inputUserEmail(user->email);
		if(op == '0'){
			return;
		}
		showInfoUser(user);
		getchar();
		break;
		printf("Continuar:\n [1] SIM \n [0] NÃO \n Digite: ");
		scanf("%c",&op);	
	} while(op != '0');
	op = writeData(user,'uR');
	if(op==0){
		cls;
		printf("Erro! Conflito de dados. Dados idênticos encontrados.");
		getchar();
		return;
	} else if(op==1) {
		printf("Usuário atualizado com sucesso!");
	}
}




int searchUser(User *user) {
	char any[256] = "";
	char op = ' ';
	op = '1';
	printf("  ::: PESQUISAR USUÁRIO :::");
	printf("::: DIGITE 0 PARA VOLTAR :::\n");
	do {
		any[256] = "";
		printf("Pesquisar: ");
		scanf("%s",&any);
		if(strlen(any) == 1 && any[0] == 0){
			return;
		} else {
			op = '0';
		}
	} while(op != '0');
	cls;
	op = search(user,any,'u');
	if(op == 1){
		return 1;
	} else {
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
					op = inputUserCep(userUp->cep);
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
		printf("Continuar:\n [1] SIM \n [0] NÃO \n Digite: ");
		scanf("%c",&op);	
	} while(op != '0');
	op = writeData(userUp,'uR');
	if(op==0){
		cls;
		printf("Erro! Conflito de dados. Dados idênticos encontrados.");
		getchar();
		return;
	} else if(op==1) {
		printf("Usuário atualizado com sucesso!");
	}
}