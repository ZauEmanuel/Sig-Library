typedef struct{
	char name[256];
	char cep[10];
	char cpf[12];
	char rua[64];
	char num[10];
	char email[128];
	int loans;
	char status;
}User;
typedef struct lista Lista;

struct lista {
	User* user;
	Lista* prox;
};

User* searchUser(char*);
void freeList(Lista*);
void searchUserShow(void);
void showInfoUser(User*);
void listUser(void);
void newUser(void);
void buscaUser();
void updateUser(void);
void removeUser(void);
void recUser(User*);
Lista* listaDiretaUsers(void);
void showInfoUserList(Lista*);
void showListUser(void);