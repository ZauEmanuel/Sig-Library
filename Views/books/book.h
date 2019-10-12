void newBook(void);
int searchBook(Book*);
void updateBook(void);
void showInfoBook(Book*);

typedef struct Book{
	char title[256];
	char subTitle[32];
	char ISN[13];
	char author[64];
    char coAuthor[64];
	char version[10];
	char year[4];
	char publisher[32];
    char status [1];
    int unity;
}Book;