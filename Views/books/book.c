#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "../../Controllers/entries/books/entriesBooks.h"
#include "book.h"


#define cls system("clear||cls");
#define clBuf setbuf(stdin,NULL);


void showInfoBook(Book *book){
	setlocale( LC_ALL, "Portuguese" );
	printf(" [1] Título :    %s \n [5] Editora :       %s \n",book->title,book->publisher);
	printf(" [2] Subtítulo : %s \n [6] Ano :           %s \n",book->subTitle,book->year);
	printf(" [3] Autor :     %s \n [7] Versão :        %s \n",book->author,book->version);
	printf(" [4] Coautor :   %s \n [8] Identificador : %s \n",book->coAuthor,book->ISN);
	printf(" [9] Status :    %s \n [10] Unidade :      %d \n",book->status,book->unity);
}


void newBook(void) {
	Book *book = calloc(sizeof *book, 0);
	char op = '1';
	do {
		printf("\n||||||||||||||||||||||||||||||||||||||||||||||\n");
		printf("                 Adicionar Livro\n");
		printf("||||||||||||||||||||||||||||||||||||||||||||||\n\n");
		printf("        ::: DIGITE 0 PARA VOLTAR :::\n");
		op = inputBookTitle(book->title);
		if(op == '0'){
			return;
		}
		op = inputBookSubtitle(book->subTitle);
		if(op == '0'){
			return;
		}
		op = inputBookAuthor(book->author);
		if(op == '0'){
			return;
		}
		op = inputBookCoauthor(book->coAuthor);
		if(op == '0'){
			return;
		}
		op = inputBookPublisher(book->publisher);
		if(op == '0'){
			return;
		}
		op = inputBookYear(book->publisher);
		if(op == '0'){
			return;
		}
		op = inputBookVersion(book->version);
		if(op == '0'){
			return;
		}
		op = inputBookIdentifier(book->ISN);
		if(op == '0'){
			return;
		}
		op = inputBookUnity(book->unity);
		if(op == '0'){
			return;
		}
		showInfoBook(book);
		getchar();
		break;
		printf("Continuar:\n [1] SIM \n [0] NÃO \n Digite: ");
		scanf("%c",&op);	
	} while(op != '0');
	op = writeData(book,'uR');
	if(op==0){
		cls;
		printf("Erro! Conflito de dados. Dados idênticos encontrados.");
		getchar();
		return;
	} else if(op==1) {
		printf("Livro atualizado com sucesso!");
	}
}




int searchBook(Book *book) {
	char any[256] = "";
	char op = ' ';
	op = '1';
	printf("   ::: PESQUISAR LIVRO :::");
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
	op = search(book,any,'b');
	if(op == 1){
		return 1;
	} else {
		return 0;
	}
}


void updateBook(void) {
	char op = '1';
	char controlP= '0';
	Book *bookUp = calloc(sizeof *bookUp, 0);
	do {
		do{
			controlP = searchBook(bookUp);
		 	if(controlP == 0){
				printf("Livro não encontrado.\n");
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
		printf("\n||      Atualizar informações de Livro     |||");
		printf("\n||||||||||||||||||||||||||||||||||||||||||||||\n");
		printf("        ::: DIGITE 0 PARA VOLTAR :::\n");
		printf("\n ::: Informações Atuais Do Livro :::\n");
		showInfoBook(bookUp);
		printf("Alterar: ");
		scanf(" %c",&op);
		if(op>='0' && op<='10'){
			switch (op) {

				case '0':
					return;

				case '1':
					op = inputBookTitle(bookUp->title);
					if(op == '0')
						return;
					break;
				
				case '2':
					op = inputBookSubtitle(bookUp->subTitle);
					if(op == '0')
						return;
					break;
				
				case '3':
					op = inputBookAuthor(bookUp->author);
					if(op == '0')
						return;
					break;

				case '4':
					op = inputBookCoauthor(bookUp->coAuthor);
					if(op == '0')
						return;
					break;

				case '5':
					op = inputBookPublisher(bookUp->publisher);
					if(op == '0')
						return;
					break;

				case '6':
					op = inputBookYear(bookUp->publisher);
					if(op == '0')
						return;
					break;

				case '7':
					op = inputBookVersion(bookUp->version);
					if(op == '0')
						return;
					break;

				case '8':
					op = inputBookidentifier(bookUp->version);
					if(op == '0')
						return;
					break;

				case '9':
					op = inputBookStatus(bookUp->status);
					if(op == '0')
						return;
					break;

				case '10':
					op = inputBookUnity(bookUp->unity);
					if(op == '0')
						return;
					break;
			}
		}
		printf("Continuar:\n [1] SIM \n [0] NÃO \n Digite: ");
		scanf("%c",&op);	
	} while(op != '0');
	op = writeData(bookUp,'bR');
	if(op==0){
		cls;
		printf("Erro! Conflito de dados. Dados idênticos encontrados.");
		getchar();
		return;
	} else if(op==1) {
		printf("Livro atualizado com sucesso!");
	}
}


