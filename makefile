!/bin/bash
clear
gcc -o Sig_Library controls/menu/menu.h controls/menu/menu.c entries/book/entriesBook.c entries/book/entriesBook.h entries/user/entriesUser.c entries/user/entriesUser.h controls/books/book.c controls/books/book.h controls/users/user.c controls/users/user.h controls/loans/loan.c controls/loans/loan.h entries/valid/valid.c entries/valid/valid.h

sleep 5

./Sig_Library