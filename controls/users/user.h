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

User* searchUser(char*);
void searchUserShow(void);
void showInfoUser(User*);
void listUser(void);
void newUser(void);
void buscaUser();
void updateUser(void);
void removeUser(void);
void recUser(User*);