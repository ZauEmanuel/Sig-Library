typedef struct Loan{
    char cpf[10];
	char ISN[13];
    char data[10];
    char status;
    int unity;
}Loan;

Loan* searchLoan(char* cpf, char* isn);
void loan(void);
void devolution(void);
void listLoan(void);
void recLoan(Loan*);


