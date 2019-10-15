#include "../books/book.h"
#include "../users/user.h"
typedef struct Loan{
	//User user;
	//Book book;
    char cpf[10];
	char ISN[13];
    int unity;
}Loan;

void loan(void);
void devolution(void);
void listLoan(void);
void recLoan(Loan*);


