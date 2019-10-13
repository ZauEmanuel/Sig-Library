typedef struct{
	char name[256];
	char cpf[10];
	char rua[64];
	char num[10];
	char cep[9];
	char city[32];
	char email[128];
	int loans;
}User;

void newUser(void);
int searchUser(User*);
void updateUser(void);
void removeUser(void);
void showInfoUser(User*);