#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#ifndef ENTRIESBOOK_H
	#include "../../entries/book/entriesBook.h"
#endif



#define cls system("clear||cls");
#define clBuf setbuf(stdin,NULL);

void listBook(void){
	Book *book = (Book*) malloc(sizeof(Book));
	FILE *f = fopen("books.bin","rb");
	if(!f){
		printf("Erro ao tantar abrir o arquivo.\n");
		printf("::: ENTER :::");
		clBuf;
		getchar();
		clBuf;
		return;
	}
	while(fread(book,sizeof(Book),1,f)){
		showInfoBook(book);
		printf("\n\n");
	}
	fclose(f);
	free(book);
	printf("	::: ENTER :::");
	getchar();
	getchar();
}

void recBook(Book *book){
	FILE *f = fopen("books.bin","ab");
	if(f==NULL){
		printf("ERRO ao criar arquivo.\n");
		clBuf; 
		printf("::: ENTER :::"); 
		getchar();
		return;
	}else{
		fwrite(book, sizeof(Book),1,f);
		fclose(f);
	}
}

void showInfoBook(Book *book){
	setlocale( LC_ALL, "Portuguese" );
	printf(" [1] Título :    %s \n [5] Ano :           %d \n",book->title,book->year);
	printf(" [2] Subtítulo : %s \n [6] Versão :        %s \n",book->subTitle,book->version);
	printf(" [3] Autor :     %s \n [7] Identificador : %s \n",book->author,book->ISN);
	printf(" [4] Editora :   %s \n [8] Status :        %c \n",book->publisher,book->status);
	printf(" [9] Unidade :      %d \n",book->unity);
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
		showInfoBook(book);
		printf("::: ENTER :::");
		clBuf;
		getchar();
		printf("Continuar:\n [1] SIM \n [0] NÃO \n Digite: ");
		clBuf;
		scanf("%c",&op);	
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
		return book;
	}
	book = (Book*) malloc(sizeof(Book));
	found = 0;
	while((!found) && (fread(book, sizeof(book), 1, f))) {
		if (strcmp(book->ISN, isn) == 0){
			found = 1;
		}
	}
	fclose(f);
	if (found)
		return book;
	else
		printf("Livro não encontrado !");
	fclose(f);
}

void updateBook(void) {
	char op = ' ';
	char controlP = '0';
	char book[13] = "";
	Book *bookUp = (Book*) malloc(sizeof(Book));
	do{
		printf("Digite o código de identificação do livro: ");
		scanf(" %s",book);
		bookUp = searchBook(book);
		printf("Se o livro não foi encontrado: \n[1] Tente novamente \n[0] Sair\n Digite: ");
		scanf(" %c",&controlP);
		if (controlP == '0')
			return;
		if (controlP == '1')
			continue;
	} while (controlP !='0');
	do {
		setlocale( LC_ALL, "Portuguese" );
		printf("\n||||||||||||||||||||||||||||||||||||||||||||||");
		printf("\n||      Atualizar informações de Livro     |||");
		printf("\n||||||||||||||||||||||||||||||||||||||||||||||\n");
		printf("        ::: DIGITE 0 PARA VOLTAR :::\n");
		printf("\n ::: Informações Atuais Do Livro :::\n");
		showInfoBook(bookUp);
		printf("Alterar: ");
		scanf(" %c",&op);
		if(op>='0' && op<='9'){
			switch (op) {

				case '0':
					return;

				case '1':
					op = inputBookTitle(bookUp);
					if(op == '0')
						return;
					break;
				
				case '2':
					op = inputBookSubtitle(bookUp);
					if(op == '0')
						return;
					break;
				
				case '3':
					op = inputBookAuthor(bookUp);
					if(op == '0')
						return;
					break;


				case '4':
					op = inputBookPublisher(bookUp);
					if(op == '0')
						return;
					break;

				case '5':
					op = inputBookYear(bookUp);
					if(op == '0')
						return;
					break;

				case '6':
					op = inputBookVersion(bookUp);
					if(op == '0')
						return;
					break;

				case '7':
					op = inputBookIdentifier(bookUp);
					if(op == '0')
						return;
					break;

				case '8':
					op = inputBookStatus(bookUp);
					if(op == '0')
						return;
					break;

				case '9':
					op = inputBookUnity(bookUp);
					if(op == '0')
						return;
					break;
			}
		}
		printf("Continuar:\n [1] SIM \n [0] NÃO \n Digite: ");
		scanf("%c",&op);	
	} while(op != '0');
	free(bookUp);
	if(op==1){
		rmBook(bookUp->status);
		recBook(book);
		printf("Livro atualizado com sucesso!");
		clBuf;
		printf("::: ENTER :::");
		getchar();
	}
}

void removeBook(void){
	char controlP = '0';
	char isn[13] = "";
	Book *book = (Book*) malloc(sizeof(Book));
	do{
		printf("Digite o código de identificação do livro: ");
		scanf(" %s",isn);
		book = searchBook(isn);
		printf("Se o livro não foi encontrado: \n[1] Tente novamente \n[0] Sair\n Digite: ");
		scanf(" %c",&controlP);
		if (controlP == '0')
			return;
		if (controlP == '1')
			continue;
		} while (controlP !='0');
	int op = 0;
	printf("\n||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("                Remover Livro\n");
	printf("||||||||||||||||||||||||||||||||||||||||||||||\n\n");
	showInfoBook(book);
	clBuf;
	printf("::: ENTER :::");
	getchar();
	printf("Continuar:\n [1] SIM \n [0] NÃO \n Digite: ");
	scanf("%d",&op);
	rmBook(isn);
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
		scanf(" %c",op);
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