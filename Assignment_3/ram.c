//
// Created by antler on 2020-02-22.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "memorymanager.h"
#define MAX_LENGTH 100
#define SIZE_OF_RAM 40

char *ram[SIZE_OF_RAM]; //array of strings;

// Start and End flag for a script or program
int start, end, flag;


void addToRAM(FILE *file, int frameNumber){
    //FILE *file = fopen(path, "r");
    //Added launcher function within exec
    //launcher(file);
    char line[MAX_LENGTH];

    if (frameNumber > -1) {

        for (int cell = 4*frameNumber; cell < 4*frameNumber + 4; cell++) {

            fgets(line, MAX_LENGTH, file);
            ram[cell] = malloc(sizeof(char *));
            strcpy(ram[cell], line);

            if (flag == 0) {
                start = cell;
                flag = 1;
            }

            if (start % 4 != 0) {
                end = cell;
            }
            if (feof(file)) {
                end = cell - 1;
                ram[cell] = NULL;
                fclose(file);
                break;

            }
        }
       flag = 0;
    }
    else{
        printf("Nothing is empty");
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