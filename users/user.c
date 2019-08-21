#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../entries/entries.h"
#include "../entries/valid.h"

#define cls system("clear||cls");
#define clBuf setbuf(stdin,NULL);

void newUser(void) {
	char op = '1';
	do {
		char name[50] = "";
		char user[10] = "";
		char cpf[10] = "";
		char rua[24] = "";
		char num[4] = "";
		char cep[9] = "";
		char email[128] = "";
		char key[32] = "";
		char control[1] = "1";
		printf("\n||||||||||||||||||||||||||||||||||||||||||||||\n");
		printf("                 Novo Usuario\n");
		printf("||||||||||||||||||||||||||||||||||||||||||||||\n\n");
		printf("        ::: DIGITE 0 PARA VOLTAR :::\n");
		op = entrName(name);
		if(op == '0'){
			return;
		}
		op = entrUser(user);
		if(op == '0'){
			return;
		}
		op = entrCPF(cpf);
		if(op == '0'){
			return;
		}
		op = entrRua(rua);
		if(op == '0'){
			return;
		}
		op = entrNum(num);
		if(op == '0'){
			return;
		}
		op = entrCEP(cep);
		if(op == '0'){
			return;
		}
		op = entrEmail(email);
		if(op == '0'){
			return;
		}
		op = entrTestEmail(email);
		if(op == '0'){
			return;
		}
		op = entrKey(key);
		if(op == '0'){
			return;
		}
		op = entrTestKey(key);
		if(op == '0'){
			return;
		}
		printf("\n ::: Entrada de informações :::\n");
		printf(" Name :     %s \n Usuario :  %s\n",name,user);
		printf(" CPF :      %s \n Rua :      %s\n",cpf,rua);
		printf(" Numero :   %s \n CEP :      %s\n",num,cep);
		printf(" email :    %s \n senha :    %s\n",email,key);
		getchar();
		break;
	} while(op != '0');
}


void pesqUser(void) {
  char op = '1';
	char cpf[11] = "";
	printf("::: DIGITE 0 PARA VOLTAR :::\n");
  do {
		if(entrCPF(cpf)) {
			op = '0';
		}	
  } while(op != '0');
	if(op == '0'){
		return;
	} else {
		printf("\n::CPF valido::\n");
		getchar();
			// Futuras funções de Pesquisa em arquivo.
	}
}

void updateUser(void) {
	char op = '1';
	do {
		op = '1';
		char name[50] = "";
		char user[10] = "";
		char cpf[10] = "";
		char rua[24] = "";
		char num[4] = "";
		char cep[9] = "";
		char email[128] = "";
		char key[32] = "";
		char control = '1';
		printf("\n|||||||||||||||||||||||||||||||||||||\n");
		printf("    Atualizar informações do usuário");
		printf("\n|||||||||||||||||||||||||||||||||||||\n\n");
		printf("  ::: DIGITE 0 PARA VOLTAR :::");
	} while(op != '0');
}