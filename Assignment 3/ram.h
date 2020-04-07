//
// Created by antler on 2020-02-27.
//
#define SIZE_OF_RAM 1000

extern int start;
extern int end;
extern char *ram[SIZE_OF_RAM];

void addToRAM(const char *path);
