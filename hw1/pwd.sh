#!/bin/sh
objdump -d pwd > pwd.dump
objdump -sj .rodata pwd > pwd.rodata
gcc -o pwd_decrypt password_decryption.c
./pwd_decrypt > password.txt
./pwd < password.txt
