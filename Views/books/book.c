#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#ifndef ENTRIESBOOK_H
	#include "../../Controllers/entries/book/entriesBook.h"
#endif



#define cls system("clear||cls");
#define clBuf setbuf(stdin,NULL);

// Lista todos os livros 
void listBook(void){
	Book *book = calloc(1,sizeof(Book));
	FILE *f = fopen("books.bin","rb");
	if(!f){
		printf("Erro ao tantar abrir o arquivo.\n");
		clBuf; 
		printf("::: ENTER :::"); 
		getchar();
		return;
	}
	while(fread(book,sizeof(Book),1,f)){
		showInfoBook(book);
		printf("\n\n");
	}
	clBuf;
	printf("::: ENTER :::"); 
	getchar();
	fclose(f);
	free(book);
}


// Grava livro em arquivo binário 
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
	//Book *book = calloc(sizeof *book, 0);
	Book *book = calloc(1,sizeof(Book));
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
		
		showInfoBook(book);
		printf("::: ENTER :::");
		clBuf; getchar();
		printf("Continuar:\n [1] SIM \n [0] NÃO \n Digite: ");
		clBuf; scanf("%c",&op);	
		recBook(book);
	} while(op != '0');
	free(book);
}




int searchBook(Book *book,char typ) {
	char any[256] = "";
	char op = ' ';
	op = '1';
	printf("   ::: PESQUISAR:::");
	printf("::: DIGITE 0 PARA VOLTAR :::\n");
	if(typ == 'l')
		//op = search(book,any,typ);
		return 1;
	do {
		memset(any, 0, sizeof any);
		printf("Pesquisar: ");
		scanf("%s",any);
		if(strlen(any) == 1 && any[0] == 0){
			return 2;
		} else {
			op = '0';
		}
	} while(op != '0');
	cls;
	//op = search(book,any,typ);
	if(op == 1){
		return op;
	} else if(op == 0) {
		printf("\nLivro não encontrado!");
		clBuf; printf("::: ENTER :::"); getchar();
		return op;
	} else if(op == 2){
		printf("\nLivro não disponível!");	
		clBuf; printf("::: ENTER :::"); getchar();
		return op;
	}
	return 0;
}


void updateBook(void) {
	char op = ' ';
	char controlP= '0';
	//Book *bookUp = calloc(sizeof *bookUp, 0);
	Book *bookUp = calloc(1,sizeof(Book));
	do {
		do{
			controlP = searchBook(bookUp,'b');
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
	//op = writeDataBook(bookUp,'bR');
	if(op==1){
		printf("Livro atualizado com sucesso!");
		clBuf; printf("::: ENTER :::"); getchar();
	}
}


void removeBook(void){
	//Book *book = calloc(sizeof *book, 0);
	Book *book = calloc(1,sizeof(Book));
	int op = 0;
	printf("\n||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("                Remover Livro\n");
	printf("||||||||||||||||||||||||||||||||||||||||||||||\n\n");

	do{
		op = searchBook(book,'b');
		if(op == 2)
			return;
	}while(op == 0);

	showInfoBook(book);
	clBuf; printf("::: ENTER :::"); getchar();
	printf("Continuar:\n [1] SIM \n [0] NÃO \n Digite: ");
	scanf("%d",&op);
	free(book);
	//if(op == 1){
	//	op = writeDataBook(book,'R');
	//	if(op == 1){
	//		printf("Livro removido com sucesso!");
	//		clBuf; printf("::: ENTER :::"); getchar();
	//	}
	//}
}
