#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../../../Models/valid.h"
#include "../../../Views/books/book.h"

 
#define cls system("clear||cls");
#define clBuf setbuf(stdin,NULL);


// entradas para livros //


char inputBookTitle(Book *book) {
	char i = '1', c[256] = "";
	do {
		printf("\n\n--Título: ");
		clBuf; scanf(" %[ ^\n]",c); clBuf;
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
		printf("\n\n--Título: ");
		clBuf; scanf(" %[ ^\n]",c); clBuf;
		if (strlen(c) == 1 && c[0] == '0') {
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
		clBuf; scanf(" %[ ^\n]",c); clBuf;
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
		clBuf; scanf(" %[ ^\n]",c); clBuf;
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
		clBuf; scanf(" %[ ^\n]",c); clBuf;
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
	char i = '1', c[4] = "";
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
		if (atoi(c) >= y) {
			printf("\n::: Entrada inválida :::\n");
			strcpy(c,"");
		} else {
			book->year = atoi(c);
			i = '0';
		}
	} while(i != '0'); 
	return '1';
}


char inputBookVersion(Book *book) {
	char i = '1', c[10] = " ";
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
			strcpy(book->version,c);
			i = '0';
		}
	} while(i != '0'); 
	return '1';
}
