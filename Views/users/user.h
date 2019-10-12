void newUser(void);
int searchUser(User*);
void updateUser(void);
void updateOP(char);
void showInfoUser(User*);


typedef struct{
	char name[256];
	char user[32];
	char cpf[10];
	char rua[64];
	char num[10];
	char cep[9];
	char city[32];
	char email[128];
	char key[32];
}User;