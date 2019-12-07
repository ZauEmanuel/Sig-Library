#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#ifndef ENTRIESUSER_H
	#include "../../entries/user/entriesUser.h"
#endif

#ifndef VALID_H
	#include "../../entries/valid/valid.h"
#endif

#define cls system("clear||cls");
#define clBuf setbuf(stdin,NULL);
#define enter printf("\n           ::: ENTER :::\n\n"); clBuf; getchar(); clBuf;

User* searchUser(char* cpf){
	cls;
	FILE* f = fopen("users.bin", "rb");
	User* user;
	int found;
	if(!f){
		return NULL;
	}
	user = (User*) malloc(sizeof(User));
	found = 0;
	while((!found) && (fread(user, sizeof(User), 1, f))) {
		if ((strcmp(user->cpf, cpf) == 0) && (user->status == '1')){
			found = 1;
		}
	}
	fclose(f);
	if (found)
		return user;
	return NULL;
}

//Devolve memória alocada de uma lista
void freeList(Lista* lista){
	if(lista != NULL){
		free(lista->user);
		freeList(lista->prox);
		free(lista);
	}
}

//Exibe dados de uma estrutura de usuário
void showInfoUser(User *user){
	printf("\n===============================\n\n");
	printf(" [1] Nome :    %s \n [2] CPF :     %s \n",user->name,user->cpf);
	printf(" [3] Rua :     %s \n [4] Número :  %s \n",user->rua,user->num);
	printf(" [5] CEP :     %s \n [6] e-mail :  %s \n",user->cep,user->email);
	printf("\n\n===============================\n");
}

//Troca os valores
void swap(Lista *a, Lista *b){
	User *temp;

	temp = a->user;
	a->user = b->user;
	b->user = temp;
}

//Exibe dados do usuário em uma lista
void showInfoUserList(Lista *user){
	Lista *search;
 	search = user;
	cls;
	while (search != NULL) {
		showInfoUser(search->user);
		search = search->prox;
	}
}

//Calcula o tamanho da lista
int size(Lista* lista){
	int cont = 0;
	while(lista != NULL){
		cont++;
		lista = lista->prox;
	}
	return cont;
}

//Lista ordenada de usuários
void sortUserList(Lista* lista){
	int cont = size(lista), aux;

	while(cont > 0){
		aux = 1;
		for(Lista* i = lista; aux < cont; i = i->prox, aux++){
			if(strcmp(i->user->name, i->prox->user->name) > 0){
				swap(i, i->prox);
			}
		}
		cont--;
	}
}

//Lista ordenada inversa
void inverSorttortUserList(Lista* lista){
	int cont = size(lista), aux;

	while(cont > 0){
		aux = 1;
		for(Lista* i = lista; aux < cont; i = i->prox, aux++){
			if(strcmp(i->user->name, i->prox->user->name) < 0){
				swap(i, i->prox);
			}
		}
		cont--;
	}
}
 
//Lista usuários a partir do arquivo users.bin
void listUser(void){
	User *user = (User*) malloc(sizeof(User));
	FILE *f = fopen("users.bin","rb");
	if(!f){
		printf("Erro ao tantar abrir o arquivo.\n");
		enter;
		return;
	}
	while((fread(user,sizeof(User),1,f)) && (user->status == '1')){
		showInfoUser(user);
		printf("\n\n");
	}
	enter;
	getchar();
	fclose(f);
	free(user);
	cls;
}

void recUser(User *user){
	FILE *f = fopen("users.bin","ab");
	if(f == NULL){
		printf("ERRO ao criar arquivo.\n");
		enter;
		return;
	}else{
		fwrite(user, sizeof(User),1,f);
		fclose(f);
	}
}

void newUser(void) {
	User *user = (User*) malloc(sizeof(User));
	char op = '1';
	cls;
	printf("\n||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("                 Novo Usuario\n");
	printf("||||||||||||||||||||||||||||||||||||||||||||||\n\n");
	printf("        ::: DIGITE 0 PARA VOLTAR :::\n");
	op = inputUserName(user);
	if(op == '0'){
		free(user);
		return;
	}
	
	op = inputUserCPF(user);
	if(op == '0'){
		free(user);
		return;
	}
	
	op = inputUserRua(user);
	if(op == '0'){
		free(user);
		return;
	}
	
	op = inputUserNum(user);
	if(op == '0'){
		free(user);
		return;
	}
	
	op = inputUserCEP(user);
	if(op == '0'){
		free(user);
		return;
	}
	
	op = inputUserEmail(user);
	if(op == '0'){
		free(user);
		return;
	}
	cls;
	showInfoUser(user);
	enter;
	do{
		printf(" --Continuar:\n    [1] SIM\n    [0] NÃO\n Digite: ");
		clBuf;
		scanf("%c",&op);
		if(op =='1'){
			user->status = '1';
			recUser(user);
			break;
		} if (op == '0'){
			free(user);
			return;
		}
	} while(1);
	clBuf;
	free(user);
}

void updateUser(void) {
	FILE* f = fopen("users.bin", "r+b");
	User* user;
	int found;
	char op;
	char cpf[12];
	cls;
	if(!f){
		printf("Erro ao tantar abrir o arquivo.\n");
		enter;
		return;
	}
	do{
		printf("\n\n\n||||||||||||||||||||||||||||||||||||||||||||||\n");
		printf("                 Atualizar Usuario\n");
		printf("||||||||||||||||||||||||||||||||||||||||||||||\n\n");
		printf(" \n[1] Listar Usuários \n[0] Sair\n\n");
		printf(" Digite o CPF: ");
		scanf(" %11[^\n]", cpf);
		if(cpf[0] == '1' && (strlen(cpf) == 1))
			listUser();
		if(cpf[0] == '0' && (strlen(cpf) == 1))
			return;
	} while(!valCPF(cpf));
	user = (User*) malloc(sizeof(User));
	found = 0;
	while((!found) && (fread(user, sizeof(User), 1, f))) {
		if ((strcmp(user->cpf, cpf) == 0) && (user->status == '1')) {
			found = 1;
			break;
		}
	}

   if (found) {
	showInfoUser(user);
	enter;
	printf("\n --Continuar:\n\n    [1] SIM\n    [0] NÃO\n\nDigite: ");
	clBuf; scanf("%c", &op); clBuf;
	cls;
	if(op=='1'){
		cls;
		showInfoUser(user);
		printf(" \n[0] Sair\n");
		printf(" \nDigite o número da categoria: ");
		scanf(" %c",&op);
		if(op == '1')
			inputUserName(user);
		if(op == '2')
			inputUserCPF(user);
		if(op == '3')
			inputUserRua(user);
		if(op == '4')
			inputUserNum(user);
		if(op == '5')
			inputUserCEP(user);
		if(op == '6')
			inputUserEmail(user);
		if(op == '0')
			return;
		cls;
		getchar();
		showInfoUser(user);
		printf("\n --Deseja REALMENTE continuar?\n\n    [1] SIM\n    [0] NÃO\n\n Digite: ");
		clBuf; scanf("%c",&op); clBuf;
		cls;
		if(op == '1'){
			fseek(f, (-1)*sizeof(User), SEEK_CUR);
			fwrite(user, sizeof(User), 1, f);
			printf("\nDados alterados com sucesso!\n");
			enter;
			getchar();
		}
    } else {
		printf("\nOperação cancelada\n");
		enter;
    }
  } else {
		printf("O usuário não foi encontrado...\n");
		enter;
		getchar();
  }
  free(user);
  fclose(f);
}

void removeUser(void) {
	FILE* f = fopen("users.bin", "r+b");
	User* user;
	user = (User*) malloc(sizeof(User));
	int found = 0;
	char op;
	char cpf[12];
	cls;
	if(!f){
		printf("Erro ao tantar abrir o arquivo.\n");
		enter;
		getchar();
		return;
	}
  	printf("\n\n");
	printf("\n============================================\n");
	printf("                 Remover Usuario");
	printf("\n============================================\n\n");
	printf("\n [1] Listar os Usuários\n [0] Sair\n\n");
	printf(" Digite o CPF do usuário: ");
	scanf(" %s",cpf);
	if ( (cpf[0] == '1') && (strlen(cpf) == 1))
		listUser();
	if ( (cpf[0] == '0') && (strlen(cpf) == 1))
		return;
	if (valCPF(cpf)){
		while((!found) && (fread(user, sizeof(User), 1, f))) {
			if ((strcmp(user->cpf, cpf) == 0) && (user->status == '1')) {
				found = 1;
			}
		}
		if (found) {
			showInfoUser(user);
			printf("\n --Deseja RALMENTE continuar? \n    [1] SIM\n    [0] NÃO\n Digite: ");
			clBuf; scanf("%c", &op); clBuf;
			cls;
			if(op=='1'){
				user->status = '0';
				fseek(f, (-1)*sizeof(User), SEEK_CUR);
				fwrite(user, sizeof(User), 1, f);
				printf("\nUsuário removido com sucesso!\n");
				enter;
				getchar();
			} else {
				printf("\nOperação cancelada\n");
				enter;
				getchar();
			}
		} else {
			printf("\nO usuário não foi encontrado...\n");
			enter;
			getchar();
		}
	}
	free(user);
	fclose(f);
}

void showListUser(void){
	char op = ' ';
	Lista* lUser;
	do{
		lUser = listaDiretaUsers();
		cls;
		printf("\n|||||||||||||||||||||||||||||||||\n");
		printf("         Listar Usuarios\n");
		printf("|||||||||||||||||||||||||||||||||\n");
		printf("\n [1] Listar Todos os Usuários\n [2] Lista Diretas de Usuários\n [3] Lista Ordenada de Usuários\n [4] Lista Invertida de Usuários\n [0] Sair\n\n");
		printf("Digite: ");
		clBuf; scanf(" %c",&op); clBuf;
		if (op == '1'){
			listUser();
		}if (op == '2'){
			showInfoUserList(lUser);
			freeList(lUser);
			enter; getchar();
		} if(op == '3'){
			sortUserList(lUser);
			showInfoUserList(lUser);
			enter; getchar();
		} if(op == '4'){
			inverSorttortUserList(lUser);
			showInfoUserList(lUser);
			enter; getchar();
		}
	}while (op != '0');
}

void searchUserShow(void){
	User *user = (User*) malloc(sizeof(User));
	char cpf[11] = "";
	char op = ' ';
	do{
		cls;
		printf("\n==================================\n");
		printf("        Pesquisar Usuário");
		printf("\n==================================\n");
		printf("\n [0] Sair\n\n  Digite o CPF: ");
		scanf(" %s",cpf);
		if( (cpf[0] == '0') && (strlen(cpf) == 1) )
			return;
		if (!valCPF(cpf)){
			printf("CPF inválido!");
			printf("\n [1] Tentar Novamente \n [0] Sair \n Digite: ");
			scanf(" %c",&op);
		} else {
			user = searchUser(cpf);
			if (user != NULL){
				showInfoUser(user);
				clBuf; getchar(); clBuf; 
			} else { 
				printf("Usuário não encontrado! \n [1] Tentar Novamente \n [0] Sair \n Digite: ");
				scanf(" %c",&op);
			}
		}
	} while(op != '0');	
}

Lista* listaDiretaUsers(void) {
  FILE* f = fopen("users.bin", "rb");
  User* user;
  Lista* lista, *lUser;
  Lista* ultimo;

  lista = NULL;
  if(!f){
		printf("Erro ao tantar abrir o arquivo.\n");
		printf("	::: ENTER :::\n"); 
		clBuf;
		getchar();
		getchar();
		return NULL;
	}

  user = (User*) malloc(sizeof(User));
  while(fread(user, sizeof(User), 1, f)) {
    if (user->status == '1') {
      lUser = (Lista*) malloc(sizeof(Lista));
      lUser->user = user;
      if (lista == NULL) {
        lista = lUser;
		lUser->prox = NULL;
      } else {
        ultimo->prox = lUser;
		lUser->prox = NULL;
      }
	  user = (User*) malloc(sizeof(User));
      ultimo = lUser;
    }
  }
  fclose(f);
  return lista;
}