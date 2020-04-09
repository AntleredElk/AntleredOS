//
// Created by antler on 2020-02-22.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "memorymanager.h"
#define MAX_LENGTH 100
#define SIZE_OF_RAM 1000

char *ram[SIZE_OF_RAM]; //array of strings;

// Start and End flag for a script or program
int start, end, flag;


void addToRAM(FILE *file){
    //FILE *file = fopen(path, "r");
    //Added launcher function within exec
    //launcher(file);
    char line[MAX_LENGTH];

    for(int cell=0; cell< SIZE_OF_RAM; cell++) {
        if (ram[cell] == NULL) {
            fgets(line, MAX_LENGTH, file);
            ram[cell] = malloc(sizeof(char*));
            strcpy(ram[cell],line);
            if (flag == 0) {
                start = cell;
            }
            flag = 1;
        }
        if (start != 0) {
            end = cell;
        }
        if(feof(file)) {
            end = cell-1;
            ram[cell] = NULL;
            fclose(file);
            break;
        }
    }
    //Tracks the end of a program and resets RAM

    if(end-start > 33){
        printf("error");
    }
    else {
        flag = 0;
//           for (int cell = start; cell <= end; cell++) {
//               ram[cell] = NULL;
//               }
    }

}

int countLine(FILE *file){

    char line[MAX_LENGTH];
    int count = 0;

    while(fgets(line, MAX_LENGTH, file) != NULL){
        count++;
    }
    return count;
}