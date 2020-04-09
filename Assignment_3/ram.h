//
// Created by antler on 2020-02-27.
//
#include <stdio.h>
#define SIZE_OF_RAM 1000
#define MAX_LENGTH 100

extern int start;
extern int end;
extern char *ram[SIZE_OF_RAM];

void addToRAM(FILE *file);
int countLine(FILE *file);
