!/bin/bash
clear
gcc -o Sig_Library controls/menu/menu.h controls/menu/menu.c entries/book/entriesBook.c entries/book/entriesBook.h entries/user/entriesUser.c entries/user/entriesUser.h controls/books/book.c controls/books/book.h controls/users/user.c controls/users/user.h controls/loans/loan.c controls/loans/loan.h entries/valid/valid.c entries/valid/valid.h
 
#gcc -o Sig_Library menu.o entriesBook.o entriesUser.o book.o user.o loan.o valid.o

#sleep 10

./Sig_Library