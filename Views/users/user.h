typedef struct{
	char name[256];
	char cep[10];
	char cpf[11];
	char rua[64];
	char num[10];
	char email[128];
	int loans;
}User;

void newUser(void);
int searchUser(User*);
void updateUser(void);
void removeUser(void);
void showInfoUser(User*);
void recUser(User*);
void listUser(void);