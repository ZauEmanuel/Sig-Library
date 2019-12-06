#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#ifndef ENTRIESBOOK_H
	#include "../../entries/book/entriesBook.h"
#endif

#ifndef VALID_H
	#include "../../entries/valid/valid.h"
#endif

#define cls system("clear||cls");
#define clBuf setbuf(stdin,NULL);
#define enter printf("\n           ::: ENTER :::\n\n"); clBuf; getchar(); clBuf;
#define confirm cls; printf("Continuar:\n [1] SIM \n [0] NÃO \n Digite: "); clBuf;;

void listBook(void){
	Book *book = (Book*) malloc(sizeof(Book));
	FILE *f = fopen("books.bin","rb");
	if(!f){
		printf("Erro ao tantar abrir o arquivo.\n");
		enter;
		return;
		}
	while(fread(book,sizeof(Book),1,f)){
		showInfoBook(book);
		printf("\n\n");
		}
	fclose(f);
	free(book);
	enter;
}

void recBook(Book *book){
	FILE *f = fopen("books.bin","ab");
	Book *bookChk = (Book*) malloc(sizeof(Book));
	if(searchBook(book->ISN) != NULL){
		bookChk = searchBook(book->ISN);
		while(bookChk->unity < book->unity){
			book->unity += 1;
		}
	} if(f==NULL){
		printf("ERRO ao criar arquivo.\n");
		enter;
		return;
	} else {
		cls;
		fwrite(book, sizeof(Book),1,f);
		fclose(f);
		}
	free(bookChk);
}

void showInfoBook(Book *book){
	setlocale( LC_ALL, "Portuguese");
	printf("\n [1] Título          :       %s",book->title);
	printf("\n [2] Subtítulo       :       %s",book->subTitle);
	printf("\n [3] Autor           :       %s",book->author);
	printf("\n [4] Editora         :       %s",book->publisher);
	printf("\n [5] Versão          :       %s",book->version);
	printf("\n [6] Ano             :       %d",book->year);
	printf("\n [7] Identificador   :       %s",book->ISN);
	printf("\n [8] Status          :       %c",book->status);
	printf("\n [9] Unidade         :       %d\n",book->unity);
}

void newBook(void) {
	Book *book = (Book*) malloc(sizeof(Book));
	char op = '1';

	do {
		printf("\n||||||||||||||||||||||||||||||||||||||||||||||\n");
		printf("                 Adicionar Livro\n");
		printf("||||||||||||||||||||||||||||||||||||||||||||||\n\n");
		printf("        ::: DIGITE 0 PARA VOLTAR :::\n");
		
		op = inputBookTitle(book);
		if(op == '0')
			return;
		
		op = inputBookSubtitle(book);
		if(op == '0')
			return;
		
		op = inputBookAuthor(book);
		if(op == '0')
			return;
		
		op = inputBookPublisher(book);
		if(op == '0')
			return;
		
		op = inputBookYear(book);
		if(op == '0')
			return;
		
		op = inputBookVersion(book);
		if(op == '0')
			return;
		
		op = inputBookIdentifier(book);
		if(op == '0')
			return;
		
		op = inputBookUnity(book);
		if(op == '0')
			return;
		book->status = 'D';
		cls;
		showInfoBook(book);
		enter;
		confirm;
		clBuf; scanf("%c",&op);
		if (op == '1')	
			recBook(book);
		op = '0';
	} while(op != '0');
	free(book);
}

Book* searchBook(char* isn) {
	FILE* f = fopen("books.bin", "rb");
	Book* book;
	int found;
	cls;
	if (!f) {
		fclose(f);
		printf("Erro ao abrir o arquivo de registro de livros !");
		return NULL;
		}
	book = (Book*) malloc(sizeof(Book));
	found = 0;
	while((!found) && (fread(book, sizeof(book), 1, f))) {
		if (strcmp(book->ISN, isn) == 0){
			found = 1;
			break;
			}
		}
	if (found)
		return book;
	else{
		printf("Livro não encontrado !");
		return NULL;
	}
	fclose(f);
	return NULL;
}

void updateBook(void) {
	char op = ' ';
	char controlP = '0';
	char book[13] = "";
	Book *bookUp = (Book*) malloc(sizeof(Book));

	do {
		printf("\n========================================\n");
		printf("               Atualizar Livro");
		printf("\n========================================\n");
		printf("\n [1] Listar os livros\n [0] Sair\n");
		printf("\n Digite o código de identificação do livro: ");
		scanf(" %s",book);
		if ( (book[0] == '1') && (strlen(book) == 1))
			listBook();
		if ( (book[0] == '0') && (strlen(book) == 1))
			return;
		else {
			bookUp = searchBook(book);
			if (bookUp != NULL)
				controlP = '1';
			}

	} while (controlP == '0');

	do {
		setlocale( LC_ALL, "Portuguese" );
		printf("\n||||||||||||||||||||||||||||||||||||||||||||||");
		printf("\n||      Atualizar informações de Livro     |||");
		printf("\n||||||||||||||||||||||||||||||||||||||||||||||\n");
		printf("        ::: DIGITE 0 PARA VOLTAR :::\n");
		printf("\n ::: Informações Atuais Do Livro :::\n");
		showInfoBook(bookUp);
		printf("Alterar: ");
		clBuf; scanf(" %c",&op); clBuf;
		if(op == '0'){
			return;
		} if(op == '1'){
			op = inputBookTitle(bookUp);
			if(op == '0')
				return;
		} if(op == '2'){
			op = inputBookSubtitle(bookUp);
			if(op == '0')
				return;
		} if(op == '3'){
			op = inputBookAuthor(bookUp);
			if(op == '0')
				return;
		} if(op == '4'){
			op = inputBookPublisher(bookUp);
			if(op == '0')
				return;
		} if(op == '5'){
			op = inputBookVersion(bookUp);
			if(op == '0')
				return;
		} if(op == '6'){
			op = inputBookYear(bookUp);
			if(op == '0')
				return;
		} if(op == '7'){
			op = inputBookIdentifier(bookUp);
			if(op == '0')
				return;
		} if(op == '8'){
			op = inputBookStatus(bookUp);
			if(op == '0')
				return;
		} if(op == '9'){
			op = inputBookUnity(bookUp);
			if(op == '0')
				return;
		}
		confirm;
		scanf("%c",&op);	
	} while(op != '1');

	if (op == '1'){
		rmBook(bookUp->ISN);
		recBook(bookUp);
		printf("Livro atualizado com sucesso!");
		enter;
		}

	free(bookUp);
}

void removeBook(void){
	char controlP = ' ';
	char isn[13] = "";
	int op = 0;
	Book *book = (Book*) malloc(sizeof(Book));

	do{
		printf("\n========================================\n");
		printf("               Remover Livro");
		printf("\n========================================\n");
		printf("\n [1] Listar os livros\n [0] Sair\n");
		printf("\n Digite o código de identificação do livro: ");
		scanf(" %s",isn);
		if ( (isn[0] == '1') && (strlen(isn) == 1))
			listBook();
		if ( (isn[0] == '0') && (strlen(isn) == 1))
			return;
		else{
			printf("%s",isn);
			book = searchBook(isn);
			if(book != NULL)
				controlP = '0';
		}
	} while (controlP !='0');
	
	setlocale( LC_ALL, "Portuguese" );
	printf("\n||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("                Remover Livro\n");
	printf("||||||||||||||||||||||||||||||||||||||||||||||\n\n");
	showInfoBook(book);
	enter;
	scanf("%d",&op);
	if(op == '1')
		rmBook(isn);
	else
		free(book);
}

void rmBook(char* isn) {
	FILE* f = fopen("books.bin", "r+b");
	Book *book = (Book*) malloc(sizeof(Book));
	int found = 0;
	
	while((!found) && (fread(book, sizeof(Book), 1, f))) {
		if ( (strcmp(book->ISN, isn) == 0) ) {
			found = 1;
			break;
			}
		}	
	book->status = 'I';
	fseek(f, (-1)*sizeof(Book), SEEK_CUR);
	fwrite(book, sizeof(Book), 1, f);
}

void searchBookShow(void){
	Book *book = (Book*) malloc(sizeof(Book));
	char isn[13] = "";
	char op = ' ';
	do{
		printf("Digite o código do livro: ");
		scanf(" %c",&op);
		if (!valISN(isn)){
			printf("Código do livro inválido!");
			printf("\n [1] Tentar Novamente \n [0] Sair \n Digite: ");
			scanf(" %c",&op);
			} else {
				book = searchBook(isn);
				if (book != NULL){
					showInfoBook(book);
					} else { 
						printf("Livro não encontrado! \n [1] Tentar Novamente \n [0] Sair \n Digite: ");
						scanf(" %c",&op);
					}
		}
	} while(op != '0');	
}