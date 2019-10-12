#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../../Models/checks/valid.h"

 
#define cls system("clear||cls");
#define clBuf setbuf(stdin,NULL);


// entradas para livros //


char inputBookTitle(char* c) {
	char i = '1';
	do {
		printf("\n\n--Título: ");
		clBuf; scanf(" %[ ^\n]",c); clBuf;
		if (strlen(c) == 1 && c[0] == '0') {
			return '0';
		} else {
			i = '0';
		}
	} while(i != '0'); 
	return '1';
}


char inputBookSubtitle(char* c) {
	char i = '1';
	do {
		printf("\n\n--Título: ");
		clBuf; scanf(" %[ ^\n]",c); clBuf;
		if (strlen(c) == 1 && c[0] == '0') {
			return '0';
		} else {
			i = '0';
		}
	} while(i != '0'); 
	return '1';
}


char inputBookPublisher(char* c) {
	char i = '1';
	do {
		printf("\n\n--Editora: ");
		clBuf; scanf(" %[ ^\n]",c); clBuf;
		if (strlen(c) == 1 && c[0] == '0') {
			return '0';
		} else {
			i = '0';
		}
	} while(i != '0'); 
	return '1';
}


char inputBookUnity(char* c) {
	char i = '1';
	do {
		printf("\n\n--Unidade do acervo: ");
		clBuf; scanf(" %[^\n]",c); clBuf;
		if (strlen(c) == 1 && c[0] == '0') {
			return '0';
		} if (valNum(c) == 0) {
			printf("\n::: Entrada inválida :::");
			strcpy(c,"");
		} else {
			i = '0';
		}
	} while(i != '0'); 
	return '1';
}


char inputBookStatus(char* c) {
	char i = '1';
	do {
		printf("\n\n--Status: ");
		printf("[r] Reservado\n");
		printf("[e] Emprestado\n");
		printf("[d] Disponível\n\n");
		clBuf; scanf(" %[ ^\n]",c); clBuf;
		if (strlen(c) == 1 && c[0] == '0') {
			return '0';
		} if ((c[0] == 'r' || c[0] == 'e' || c[0] == 'd') && (strlen(c) == 1)) {
			printf("\n::: Entrada inválida :::");
			strcpy(c,"");
		} else {
			i = '0';
		}
	} while(i != '0'); 
	return '1';
}


char inputBookAuthor(char* c) {
	char i = '1';
	do {
		printf("\n\n--Autor: ");
		clBuf; scanf(" %[ ^\n]",c); clBuf;
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


char inputBookidentifier(char* c) {
	char i = '1';
	do {
		printf("\n\n--Identificador: ");
		clBuf; scanf(" %[ ^\n]",c); clBuf;
		if (strlen(c) == 1 && c[0] == '0') {
			return '0';
		} if (valISN(c) == 0) {
			printf("\n::: Entrada inválida :::");
			strcpy(c,"");
		} else {
			i = '0';
		}
	} while(i != '0'); 
	return '1';
}


char inputBookCoauthor(char* c) {
	char i = '1';
	do {
		printf("\n\n--Coautor: ");
		printf("Caso não exista, digite - e enter.");
		clBuf; scanf(" %[ ^\n]",c); clBuf;
		if(strlen(c) == 1 && c[0] == '0') {
			return '0';
		if(strlen(c) == 1 && c[0] == '-'){
			return 1;
		}
		} if (valName(c) == 0) {
			printf("\n::: Entrada inválida :::");
			strcpy(c,"");
		} else {
			i = '0';
		}
	} while(i != '0'); 
	return '1';
}


char inputBookYear(char* c) {
	char i = '1';
	time_t timer;
	struct tm* tm_info;
	char year[5];
	time(&timer);
	tm_info = localtime(&timer);
	strftime(year, 5, "%Y", tm_info);
	int y = atoi(year);
	do {
		printf("\n--Ano: ");
		clBuf; scanf(" %s",c); clBuf;
		if (strlen(c) == 1 && c[0] == '0') {
			return '0';
		}
		if (atoi(c) > y) {
			printf("\n::: Entrada inválida :::\n");
			strcpy(c,"");
		} else {
			i = '0';
		}
	} while(i != '0'); 
	return '1';
}


char inputBookVersion(char* c) {
	char i = '1';
	do {
		printf("\n--Versão: ");
		clBuf; scanf(" %s",c); clBuf;
		if (strlen(c) == 1 && c[0] == '0') {
			return '0';
		}
		if (!(valAlphaNum(c))) {
			printf("\n::: Entrada inválida :::\n");
			strcpy(c,"");
		} else {
			i = '0';
		}
	} while(i != '0'); 
	return '1';
}