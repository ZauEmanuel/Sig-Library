#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "../../Controllers/userControl/user.h"
#include"../../Controllers/bookControl/book.h"


#define cls system("clear||cls");
#define clBuf setbuf(stdin,NULL);


void acervo(void){
    char op = '1';
    do {
	    cls;
	    printf("\n|||||||||||||||||||||||||||||||||\n");
        printf("              Acervo");
        printf("\n|||||||||||||||||||||||||||||||||\n");
        printf(" [1] Acervo\n [2] Pesquisar material\n [3] Cadastrar material\n");
        printf(" [4] Atualizar material\n [5] Remover material\n [0] Voltar\n\n");
        printf("Digite: ");
        scanf(" %c",&op);
        cls;
        clBuf;
        if(op >= '0' && op <= '5'){
            switch (op){

                case '0':
                    return;
                
                case '1':
                    //library();
                    break;
                
                case '2':
                    //newItem();
                    break;
                
                case '3':
                    //registerItem();
                    break;
                
                case '4':
                    //updateItem():
                    break;
                
                case '5':
                    //delItem();
                    break;
            }
        }
  } while(!(op >= '0' && op <= '5'));
}


void users(void) {
	char op = '1';
	do {
		cls;
		printf("|||||||||||||||||||||||||||||||||\n");
		printf("              Usuario\n");
		printf("|||||||||||||||||||||||||||||||||\n");
		printf(" [1] Pesquisar\n [2] Cadastrar\n [3] Atualizar\n");
        printf(" [4] Remover\n [0] Voltar\n\n");
        printf("Digite: ");
        scanf(" %c",&op);
        cls;
        setbuf;
        if(op >= '0' && op <= '4'){
            switch (op){

                case '0':
                    return;

                case '1':
                    pesqUser();
                    break;
            
                case '2':
                    newUser();
                    break;

                case '3':
                    //updateUser();
                    break;
            
                case '4':
                    //delUser();
                    break;
            }
        }
    } while(!(op >= '0' && op <= '4'));
}


void bibli(void){
  char op = 1;
    do {
        cls;
        printf("\n////////////////////////////////////\n");
        printf("             Biblioteca\n");
        printf("///////////////////////////////////\n");
        printf(" [1] Relatório\n [2] Gerenciamento de Funcionários\n");
        printf(" [3] Entrada e Saída de Livros\n [4] Usuário\n [0] Voltar\n\n");
        printf("Digite: ");
        scanf(" %c",&op);
        cls;
        setbuf;
        if(op >= '0' && op <= '5'){
            switch (op){

                case 0:
                    break;

                case 1:
                    //Função Relatório
                    printf("Função não implementada!\n");
                    getchar();
                    break;

                case 2:
                    //Função Gerenciamento de Funcionários
                    printf("Função não implementada!\n");
                    getchar();
                    break;

                case 3:
                    //Função Entrada e Saída de Livros
                    printf("Função não implementada!\n");
                    getchar();
                    break;

                case 4:
                    //Função Usuário
                    printf("Função não implementada!\n");
                    getchar();
                    break;
                }
            }
    } while (op != 0);
}


void config(void){
    char op = '1';
    do {
        cls;
        printf("\n////////////////////////////////////\n");
        printf("              Opções.\n");
        printf("///////////////////////////////////\n");
        scanf("%c",&op);
        cls;
        setbuf;
        if(op>= '0' && op<= '1'){
            switch (op){
            
            case 0:
                return;
                
            case '1':
                break;
            }
        }
    }while(0);
  }


void configUser(void){
    char op = '1';
    do {
        cls;
        printf("\n---------------------------------");
        printf("\n       Opções de Usuario");  
        printf("\n---------------------------------");
        printf(" [1] Cadrastrar\n [2] Atualizar\n [3] Excluir\n [0] Volta\n\n");
        printf("Digite: ");
        scanf(" %c",&op);
        cls;
        setbuf;
        if(op >= '0' && op <= '3'){
            switch (op){

                case '0':
                    return;

                case '1':
                    newUser();
                    break;

                case '2':
                    updateUser();
                    break;

                case '3':
                    //deleteUser();
                    break;
            }
        }
    } while(!(op >= '0' && op <= '2'));
}


void about(void) {
    cls;
    printf("=================================================\n");
    printf("                         Sobre\n");
    printf("=================================================\n");
    printf("\nSIG-Library: Um Sistema de Controle de Biblioteca.\n");
    printf("\nCriadores:\n");
    printf("\n  Emanuel Oliveira - emanueldasilva011@gmail.com");
    printf("\n  Zaú Galvão - zauhf@gmail.com - https://github.com/ZauJulio\n\n\n");
    printf("            2019 - Caicó/RN\n\n");
    printf("==================================================\n");
    clBuf;
    getchar();
    cls;
}


void menuAdmin(void) {
  char op = '1';
  do {
    cls;
    setlocale( LC_ALL, "Portuguese" );
    printf("////////////////////////////////////\n");
    printf("           SIG - Library\n");
    printf("///////////////////////////////////\n");
    printf(" [1] Usuario\n [2] Acervo\n [3] Biblioteca\n [4] Sobre \n [5] Opções\n [0] Sair\n\n");
	printf("Digite: ");
    scanf(" %c",&op);
    cls;
    setbuf;
    if (op >= '0' && op <= '5') {
			switch (op) {

				case '1':
				    users();
				    break;
				
				case '2':
				    acervo();
				    break;
				
				case '3':
				    bibli();
				    break;
				
				case '4':
				    about();
				    break;

				case '5':
				    config();
				    break;
				
				case '0' :
				    return;
			}
    } 
    cls;
  } while (op != '0');
}
