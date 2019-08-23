#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "../entries/entries.h"
#include "../entries/valid.h"
#include "user.h"

#define cls system("clear||cls");
#define clBuf setbuf(stdin,NULL);


void newUser(void) {
	user = &pEntrie;
	setlocale( LC_ALL, "Portuguese" );
	printf(" Name :     %s \n Usuario :  %s\n",user->name,user->user);
	printf(" CPF :      %s \n Rua :      %s\n",user->cpf,user->rua);
	printf(" Numero :   %s \n CEP :      %s\n",user->num,user->cep);
	printf(" email :    %s \n senha :    %s\n",user->email,user->key);
	char op = '1';
	do {
		printf("\n||||||||||||||||||||||||||||||||||||||||||||||\n");
		printf("                 Novo Usuario\n");
		printf("||||||||||||||||||||||||||||||||||||||||||||||\n\n");
		printf("        ::: DIGITE 0 PARA VOLTAR :::\n");
		op = entrName(user->name);
		if(op == '0'){
			return;
		}
		op = entrUser(user->user);
		if(op == '0'){
			return;
		}
		op = entrCPF(user->cpf);
		if(op == '0'){
			return;
		}
		op = entrRua(user->rua);
		if(op == '0'){
			return;
		}
		op = entrNum(user->num);
		if(op == '0'){
			return;
		}
		op = entrCEP(user->cep);
		if(op == '0'){
			return;
		}
		op = entrEmail(user->email);
		if(op == '0'){
			return;
		}
		op = entrKey(user->key);
		if(op == '0'){
			return;
		}
		printf("\n ::: Informações Do Usuário :::\n");
		printf(" Name :     %s \n Usuario :  %s\n",user->name,user->user);
		printf(" CPF :      %s \n Rua :      %s\n",user->cpf,user->rua);
		printf(" Numero :   %s \n CEP :      %s\n",user->num,user->cep);
		printf(" email :    %s \n senha :    %s\n",user->email,user->key);
		getchar();
		break;
	} while(op != '0');
}


void pesqUser(void) {
  char op = '1';
	user = &pEntrie;
	setlocale( LC_ALL, "Portuguese" );
	printf("::: DIGITE 0 PARA VOLTAR :::\n");
  do {
		if(entrCPF(user->cpf) == '1') {
			printf("\n::CPF valido::\n");
			clBuf;
			getchar();
			op = '0';
		}	else {
			return;
		}
  } while(op != '0');
			// Futuras funções de Pesquisa em arquivo->
}


void updateUser(void) {
	char op = '1';
	cls;
	user = &pEntrie;
	do {
		char control = 'a';
		//file_entrie
		setlocale( LC_ALL, "Portuguese" );
		printf("\n   ::: Informações Atuais Do Usuário :::\n");
		printf(" [1] Name :     %s \n [5] Usuario :  %s\n",user->name,user->user);
		printf(" [2] CPF :      %s \n [6] Rua :      %s\n",user->cpf,user->rua);
		printf(" [3] Numero :   %s \n [7] CEP :      %s\n",user->num,user->cep);
		printf(" [4] email :    %s \n [8] senha :    %s\n",user->email,user->key);
		printf("\n::: DIGITE 0 PARA VOLTAR AO MENU ANTERIOR :::\n");
		while (!(control >= '0' && control <= '9')) {
			printf("Digite: ");
			scanf(" %c",&control);
		}
		printf("\n||||||||||||||||||||||||||||||||||||||||||||||");
		printf("\n|||          Atualizar informações         |||");
		printf("\n||||||||||||||||||||||||||||||||||||||||||||||\n");
		switch (control) {
			case '0':
				return;

			case '1':
				op = entrName(user->name);
				if(op == '0')
					return;
				break;
			
			case '2':
				op = entrUser(user->user);
						if(op == '0')
							return;
				break;
			
			case '3':
				op = entrCPF(user->cpf);
				if(op == '0')
					return;
				break;

			case '4':
				op = entrRua(user->rua);
				if(op == '0')
					return;
				break;

			case '5':
				op = entrNum(user->num);
				if(op == '0')
					return;
				break;

			case '6':
				op = entrCEP(user->cep);
				if(op == '0')
					return;
				break;

			case '7':
				op = entrEmail(user->email);
				if(op == '0')
					return;
				op = entrTestEmail(user->email);
				if(op == '0')
					return;
				break;

			case '8':
				op = entrKey(user->key);
				if(op == '0')
					return;
				op = entrTestKey(user->key);
				if(op == '0')
					return;
				break;
		}
	} while(op != '0');
}
