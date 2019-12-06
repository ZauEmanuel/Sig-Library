#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

#ifndef VALID_H
	#include "../valid/valid.h"
#endif
 
#ifndef BOOK_H
	#include "../../controls/books/book.h"
#endif
 
#define cls system("clear||cls");
#define clBuf setbuf(stdin,NULL);

char inputBookTitle(Book *book) {
	char i = '1', c[256] = "";
	do {
		printf("\n\n--Título: ");
		clBuf; scanf(" %[^\n]",c); clBuf;
		if (strlen(c) == 1 && c[0] == '0') {
			return '0';
		} else {
			strcpy(book->title,c);
			i = '0';
		}
	} while(i != '0');
	return '1';
}

char inputBookSubtitle(Book *book) {
	char i = '1', c[32] = "";
	do {
		printf("\n Digite [p] para pular.");
		printf("\n\n--Sub Título: ");
		clBuf; scanf(" %[^\n]",c); clBuf;
		if (strlen(c) == 1 && c[0] == 'p') {
			return '1';
		} if (strlen(c) == 1 && c[0] == '0') {
			return '0';
		} else {
			strcpy(book->subTitle,c);
			i = '0';
		}
	} while(i != '0'); 
	return '1';
}

char inputBookPublisher(Book *book) {
	char i = '1', c[32] = "";
	do {
		printf("\n\n--Editora: ");
		clBuf; scanf(" %[^\n]",c); clBuf;
		if (strlen(c) == 1 && c[0] == '0') {
			return '0';
		} else {
			strcpy(book->publisher,c);
			i = '0';
		}
	} while(i != '0'); 
	return '1';
}

char inputBookUnity(Book *book) {
	char i = '1';
	char c[5] = "";
	do {
		printf("\n\n--Unidade do acervo: ");
		clBuf; scanf(" %s",c); clBuf;
		if (strlen(c) == 1 && c[0] == '0') {
			return '0';
		} if (valDec(c) == 0) {
			printf("\n::: Entrada inválida :::");
			strcpy(c,"");
		} else {
			book->unity = atoi(c);
			i = '0';
		}
	} while(i != '0'); 
	return '1';
}

char inputBookStatus(Book *book) {
	char i = ' '; char c = ' ';
	do {
		printf("\n\n--Status: ");
		printf("[r] Reservado\n");
		printf("[e] Emprestado\n");
		printf("[d] Disponível\n\n");
		clBuf; scanf(" %c",&c); clBuf;
		if (c == '0') {
			return '0';
		} if ((c == 'r' || c == 'e' || c == 'd') && (c == 1)) {
			printf("\n::: Entrada inválida :::");
			c = ' ';
		} else {
			book->status = c;
			i = '0';
		}
	} while(i != '0'); 
	return '1';
}

char inputBookAuthor(Book *book) {
	char i = '1', c[256] = "";
	do {
		printf("\n\n--Autor: ");
		clBuf; scanf(" %[^\n]",c); clBuf;
		if (strlen(c) == 1 && c[0] == '0') {
			return '0';
		} if (valName(c) == 0) {
			printf("\n::: Entrada inválida :::");
			strcpy(c,"");
		} else {
			strcpy(book->author,c);
			i = '0';
		}
	} while(i != '0'); 
	return '1';
}

char inputBookIdentifier(Book *book) {
	char i = '1', c[13] = "";
	do {
		printf("\n\n--Identificador: ");
		clBuf; scanf(" %[^\n]",c); clBuf;
		if (strlen(c) == 1 && c[0] == '0') {
			return '0';
		} if (valISN(c) == 0) {
			printf("\n::: Entrada inválida :::");
			strcpy(c,"");
		} else {
			strcpy(book->ISN,c);
			i = '0';
		}
	} while(i != '0'); 
	return '1';
}

char inputBookYear(Book *book) {
	char i = '1';
	char buffer[5];
	char year[5];
	int y;
	time_t time_y;
	struct tm *info;
	time(&time_y);
	info = localtime( &time_y);
	strftime(buffer,5,"%Y", info);
	y = atoi(buffer);
	do {
		printf("\n--Ano: ");
		clBuf; scanf(" %s",year); clBuf;
		if (strlen(year) == 1 && year[0] == '0')
			return '0';
		if(atoi(year) <= y){
			book->year = atoi(year);
			i = '0';
		}
	} while(i != '0'); 
	return '1';
}

char inputBookVersion(Book *book) {
	char i = '1', c[10] = " ";
	do {
		printf("\n Digite [p] para pular");
		printf("\n\n--Versão ou Edição: ");
		clBuf; scanf(" %s",c); clBuf;
		if (strlen(c) == 1 && c[0] == 'p') {
			return '1';
		} if (strlen(c) == 1 && c[0] == '0') {
			return '0';
		} if (!(valAlphaNum(c))) {
			printf("\n::: Entrada inválida :::\n");
			strcpy(c,"");
		} else {
			strcpy(book->version,c);
			i = '0';
		}
	} while(i != '0'); 
	return '1';
}