#!/bin/bash
clear
gcc -Wall -c main.c users/user.c users/user.h entries/valid.c entries/valid.h entries/files.c entries/files.h entries/entries.c entries/entries.h entries/clients/menuClient.c entries/clients/menuClient.h entries/admin/menuAdmin.h entries/admin/menuAdmin.c config/library.c config/library.h config/control.c config/control.h
gcc -o Sig_Library main.c user.o valid.o files.o entries.o menuClient.o menuAdmin.o library.o control.o
./Sig_Library
