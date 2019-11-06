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

void newUser(void);
void buscaUser();
int searchUser(User*);
void updateUser(void);
void removeUser(void);
void showInfoUser(User*);
void recUser(User*);
void listUser(void);