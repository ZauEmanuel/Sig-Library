typedef struct{
	char title[256];
	char subTitle[32];
	char ISN[13];
	char author[256];
	char version[10];
	char publisher[32];
	char status;
	int year;
    int unity;
}Book;

void newBook(void); 
Book* searchBook(char*);
void searchUserShow(void);
void updateBook(void);
void showInfoBook(Book*);
void removeBook(void);
void listBook(void);
void recBook(Book*);
void rmBook(char*);
