#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef VALID_H
	#include "../valid/valid.h"
#endif
 
#ifndef USER_H
	#include "../../controls/users/user.h"
#endif

#define cls system("clear||cls");
#define clBuf setbuf(stdin,NULL);


// entradas para usuário //


char inputUserName(User* user) {
	char i = '1', c[256] = " ";
	do {
		printf("\n\n--Nome: ");
		clBuf;
		scanf(" %[^\n]s",c);
		clBuf;
		if (strlen(c) == 1 && c[0] == '0') {
			return '0';
		} if (valName(c) == 0) {
			printf("\n::: Entrada inválida :::");
			memset(c, '\0', sizeof(c));
		} else {
			strcpy(user->name,c);
			i = '0';
		}
	} while(i != '0'); 
	return '1';
}


char inputUserCPF(User* user) {
	char i = '1', c[11] = " ";
	do {
		printf("\n--CPF: ");
		clBuf;
		scanf(" %s",c);
		clBuf;
		if (strlen(c) == 1 && c[0] == '0') {
			return '0';
		}
		if (!valCPF(c)) {
			printf("\n::: Entrada inválida :::\n");
			memset(c, '\0', sizeof(c));
		} else {
			c[strlen(c)] = '\0';
			strcpy(user->cpf,c);
			i = '0';
		}
	} while(i != '0'); 
	return '1';
}


char inputUserRua(User* user) {
	char i = '1', c[64] = " ";
	do {
		printf("\n\n--Rua: ");
	  	clBuf;
		scanf(" %[^\n]s",c);
		clBuf;
		if (strlen(c) == 1 && c[0] == '0') {
			return '0';
		} if(!valRua(c)) {
			printf("\n::: Entrada inválida :::\n");
			memset(c, '\0', sizeof(c));
		} else {
			strcpy(user->rua,c);
			i = 0;
		}
	} while(i != 0);
	return '1';
}


char inputUserNum(User* user) {
	char i = '1', c[10] = " ";
	do {
		printf("\n--Número: ");
		clBuf;
		scanf(" %s",c);
		clBuf;
		if (strlen(c) == 1 && c[0] == '0') {
			return '0';
		} if (valAlphaNum(c) == 0) {
			printf("\n::: Entrada inválida :::\n");
			memset(c, '\0', sizeof(c));
		} else {
			strcpy(user->num,c);
			i = '0';
		}
	} while(i != '0');
	return '1';
}


char inputUserCEP(User* user) {
	char i = '1', c[9] = " ";
	do {
		printf("\n--CEP: ");
		clBuf;
		scanf(" %s%*[-]s",c);
		clBuf;
		if (strlen(c) == 1 && c[0] == '0') {
			return '0';
		}
		if (valCEP(c)) {
			printf("\n::: Entrada inválida :::\n");
			memset(c, '\0', sizeof(c));
		} else {
			strcpy(user->cep,c);
			i = '0';
		}
	} while(i != '0');
	return '1';
}


char inputUserEmail(User* user) {
	char i = '1', c[128] = "";
	do {
		printf("\n--E-mail: ");
		clBuf;
		scanf(" %[A-Za-z0-9.!#$&+-/=?^_`{|}){@\"]s",c); 
		clBuf;
		if (strlen(c) == 1 && c[0] == '0') {
			return '0';
		} 
		if (valEmail(c) == 0) {
			printf("\n::: Entrada inválida :::");
			memset(c, '\0', sizeof(c));
		} else {
			strcpy(user->email,c);
			i = '0';
		}
	} while(i != '0');
	return '1';
}
