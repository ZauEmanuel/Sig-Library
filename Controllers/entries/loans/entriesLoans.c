#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../Models/checks/valid.h"

 
#define cls system("clear||cls");
#define clBuf setbuf(stdin,NULL);


// entradas para usuário //


char entrName(char* c) {
	char i = '1';
	do {
		printf("\n\n--Nome: ");
		clBuf; scanf(" %[^\n]",c); clBuf;
		if (strlen(c) == 1 && c[0] == '0') {
			return '0';
		} if (valName(c) == 0) {
			printf("\n::: Entrada inválida :::");
			strcpy(c,"");
		} else {
			i = '0';
		}
	} while(i != '0'); 
	return '1';
}


char entrCPF(char* c) {
	char i = '1';
	do {
		printf("\n--CPF: ");
		clBuf; scanf(" %s",c); clBuf;
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
	char i = '1';
	do {
		printf("\n\n--Rua: ");
	  	clBuf; scanf(" %[^\n]",c); clBuf;
		if (strlen(c) == 1 && c[0] == '0') {
			return '0';
		} if(!valRua(c)) {
			printf("\n::: Entrada inválida :::\n");
			strcpy(c,"");
		} else {
			i = 0;
		}
	} while(i != 0);
	return '1';
}


char entrNum(char* c) {
	char i = '1';
	do {
		printf("\n--Número: ");
		clBuf; scanf(" %s",c); clBuf;
		if (strlen(c) == 1 && c[0] == '0') {
			return '0';
		} if (valAlphaNum(c) == 0) {
			printf("\n::: Entrada inválida :::\n");
			strcpy(c,"");
		} else {
			i = '0';
		}
	} while(i != '0');
	return '1';
}


char entrCEP(char* c) {
	char i = '1';
	do {
		printf("\n--CEP: ");
		clBuf; scanf(" %s%*[-]",c); clBuf;
		if (strlen(c) == 1 && c[0] == '0') {
			return '0';
		}
		if (valCEP(c)) {
			printf("\n::: Entrada inválida :::\n");
			strcpy(c,"");
		} else {
			i = '0';
		}
	} while(i != '0');
	return '1';
}


char entrEmail(char* c) {
	char i = '1';
	do {
		printf("\n--E-mail: ");
		clBuf; scanf(" %[A-Za-z0-9.!#$&+-/=?^_`{|}){@\"]",c); clBuf;
		if (strlen(c) == 1 && c[0] == '0') {
			return '0';
		} if (valEmail(c) == 0) {
			printf("\n::: Entrada inválida :::");
			strcpy(c,"");
		} else {
			i = '0';
		}
	} while(i != '0');
	return '1';
}


char entrTestEmail(char* c) {
	char op = '0', i = '1';
	char test[128] = "";
	do {
		printf("\n--Comfirme o E-mail: ");
		clBuf; scanf(" %s",test); clBuf;
		if (strlen(c) == 1 && c[0] == '0') {
			return '0';
		} if (strcmp(c,test) != 0) {
			strcpy(c,"");
			printf("::: Os Email's Não Combinam :::\n");
			printf("\tAlterar e-mail anterior:\n[1] Alterar\t[0] Tentar novamente\n");
			scanf(" %d",&op);
			if (op == '1') {
				entrEmail(c);
			} else {
				continue;
			}
		} else {
			i = '0';
		}
	} while(i != '0');
	return '1';
}