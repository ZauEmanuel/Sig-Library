#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "valid.h"

#define cls system("clear||cls");
#define clBuf setbuf(stdin,NULL);

char entrName(char* c) {
	char i = '0';
	do {
		printf("\n\n--Nome: ");
		clBuf;
		scanf(" %[^\n]",c);
		clBuf;
		if (strlen(c) == 1 && c[0] == '0') {
			return '0';
		}
		if (valName(c) == 0) {
			printf("\n::: Entrada inválida :::");
			strcpy(c,"");
		} else {
			i = '0';
		}
	} while(i != '0'); 
	return '1';
}


char entrUser(char* c) {
	int i = 0;
	do {
		printf("\n--Usuario: ");
		clBuf;
		scanf(" %[^\n]",c);
		clBuf;
		if (strlen(c) == 1 && c[0] == '0') {
			return '0';
		}
		if ((strlen(c) < 3 && valAlphaNum(c))) {
			printf("\n::: Entrada inválida :::\n Digite ao menos 3 caracteres.");
			strcpy(c,"");
		} else {
			i = 1;
		}
	} while(i != 1); 
	return '1';
}

char entrCPF(char* c) {
	char i = '1';
	do {
		printf("\n--CPF: ");
		scanf(" %s",c);
		clBuf;
		if (strlen(c) == 1 && c[0] == '0') {
			return '0';
		}
		if (!valCPF(c)) {
			printf("\n::: Entrada inválida :::\n");
			strcpy(c,"");
		} else {
			i = '0';
		}
	} while(i != '0'); 
	return '1';
}


char entrRua(char* c) {
	int i = 1;
	printf("\n\t::Endereço::");
	do {
	  printf("\n\n--Rua: ");
		scanf(" %[^\n]",c);
		clBuf;
		if (strlen(c) == 1 && c[0] == '0') {
			return '0';
		}
		if(!valRua(c)) {
			printf("\n::: Entrada inválida :::\n");
			strcpy(c,"");
		}	else {
			i = 0;
		}
	} while(i != 0);
	return '1';
}


char entrNum(char* c) {
	int i = 1;
	do {
		printf("\n--Número: ");
		scanf(" %s",c);
		clBuf;
		if (strlen(c) == 1 && c[0] == '0') {
			return '0';
		}
		if (valAlphaNum(c) == 0) {
			printf("\n::: Entrada inválida :::\n");
			strcpy(c,"");
		} else {
			i = 0;
		}
	} while(i != 0);
	return '1';
}


char entrCEP(char* c) {
	int i = 1;
	do {
		printf("\n--CEP: ");
		scanf(" %s%*[-]",c);
		if (strlen(c) == 1 && c[0] == '0') {
			return '0';
		}
		if (valCEP(c)) {
			printf("\n::: Entrada inválida :::\n");
			strcpy(c,"");
		} else {
			i = 0;
		}
	} while(i != 0);
	return '1';
}


char entrEmail(char* c) {
	int i = 1;
	do {
		printf("\n--E-mail: ");
		clBuf
		scanf(" %[A-Za-z0-9.!#$&+-/=?^_`{|}){@\"]",c);
		if (strlen(c) == 1 && c[0] == '0') {
			return '0';
		}
		if (valEmail(c) == 0) {
			printf("\n::: Entrada inválida :::");
			strcpy(c, "" );
		} else {
			i = 0;
		}
	} while(i != 0);
	return '1';
}


char entrTestEmail(char * c) {
	int op = 0, i = 1;
	char test[128] = "";
	do {
		printf("\n--Comfirme o E-mail: ");
		scanf(" %s",test);
		if (strlen(c) == 1 && c[0] == '0') {
			return '0';
		}
		if (strcmp(c,test) != 0) {
			strcpy(c,"");
			printf("::: Os Email's Nao Combinam :::\n");
			printf("    Alterar e-mail anterior:\n[1] Alterar\t[0] Tentar novamente\n");
			scanf(" %d",&op);
			if (op == 1) {
				entrEmail(c);
			} else {
				continue;
			}
		} else {
			i = 0;
		}
	} while(i != 0);
	return '1';
}


char entrKey(char* c) {
	int i = 1;
	do {
		printf("\n\n--Senha: ");
		scanf(" %s",c);
		if (strlen(c) == 1 && c[0] == '0') {
			return '0';
		}
		if (!valKeyA(c)) {
			strcpy(c,"");
			printf("::: Entrada inválida :::\n-- A senha deve ter pelo menos 8 digitos, dentre eles ao menos UM número, UMA letra maiuscula, UMA letra minuscula e UM simbolo. --\n");
		} else {
			i = 0;
		}
	} while(i != 0);
	return '1';
}


char entrTestKey(char * key) {
	int op = 0, i = 1;
	char c[32] = "";
	do {
		printf("\n--Comfirme a senha: ");
		scanf(" %s",c);
		if (strlen(c) == 1 && c[0] == '0') {
			return '0';
		}
		if (strcmp(key,c) != 0) {
			strcpy(c,"");
			printf("::: As Senhas Nao Combinam :::\n");
			printf("Alterar senha anterior:\n[1] SIM\t[0] NÃO\n");
			clBuf
			scanf(" %d",&op);
			if (op == 1) {
				strcpy(key,"");
				entrKey(key);
			} else {
				continue;
			}
		} else {
			i = 0;
		}
	} while(i != 0);
	return '1';
}
