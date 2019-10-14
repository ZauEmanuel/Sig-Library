#!/bin/bash
clear

gcc -Wall -o Sig_Library Views/menu/menu.h Views/menu/menu.c Controllers/entries/book/entriesBook.c Controllers/entries/book/entriesBook.h Controllers/entries/user/entriesUser.c Controllers/entries/user/entriesUser.h Views/books/book.c Views/books/book.h Views/users/user.c Views/users/user.h Views/loans/loan.c Views/loans/loan.h Models/valid.c Models/valid.h
 
#gcc -o Sig_Library menu.o entriesBook.o entriesUser.o book.o user.o loan.o valid.o

sleep 10

./Sig_Library
