//
// Created by antler on 2020-04-07.
//

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "ram.h"
#define CODE_LINES_PER_PAGE 4

int launcher(FILE *p);
int countTotalPages(FILE *f);
char* createFilePath(char* BackingStoreDir, char* PCBTemplate, int pageNumber);
void populatePage(FILE *swapFile, FILE *pageFile);
void loadPage(int pageNumber, FILE *f, int frameNumber);

int launcher(FILE *p){

    if (1){
        char command[100];
        char source[100];
        char destination[100];
        char fullCommand[100];
        char temp[100];
        ssize_t r;

        sprintf(temp, "/proc/self/fd/%d", fileno(p));
        r = readlink(temp, source, 100);

        strcpy(command, "cp");
        strcpy(destination, "./BackingStore");


        sprintf(fullCommand, "%s %s %s", command, source, destination);

        system(fullCommand);
        fclose(p);

        FILE *swapFile = fopen(source, "r");
        countTotalPages(p);

        rewind(p);
        addToRAM(p);

        return 1;
    }
    else{
        //TODO what happens if launcher is unsuccessful?
        return 0;
    }
}

int countTotalPages(FILE *swapFile){
    int numberOfLines =  countLine(swapFile);

    int pageNumber = 0;

    char pageFilePath[100];
    char BackingStoreDir[100] = "./BackingStore/";
    char PCBTemplate[30] = "PCB00";

    int numberOfPages = ceil(numberOfLines/(float)4);

    rewind(swapFile);

    strcpy(pageFilePath, createFilePath(BackingStoreDir, PCBTemplate, pageNumber));
    populatePage(swapFile, pageFilePath);

    for(int i=0; i<numberOfPages-1; i++){
        //Resets for each new page
        pageNumber++;
        strcpy(BackingStoreDir, "./BackingStore/");
        strcpy(PCBTemplate, "PCB00");
        //  ^

        strcpy(pageFilePath, createFilePath(BackingStoreDir, PCBTemplate, pageNumber));
        populatePage(swapFile, pageFilePath);
    }

    return numberOfPages;

}

char* createFilePath(char* BackingStoreDir, char* PCBTemplate, int pageNumber){
    BackingStoreDir[100] = "./BackingStore/";

    char pageNumberString[30];
    char command[30] = "touch ";

    snprintf(pageNumberString, 30,"%d", pageNumber);
    strcat(PCBTemplate, pageNumberString);
    strcat(BackingStoreDir, PCBTemplate);
    strcat(BackingStoreDir, ".txt");
    strcat(command, BackingStoreDir);

    system(command);



    return BackingStoreDir;
}
void populatePage(FILE *swapFile, FILE *pageFile){
    FILE *newPage = fopen(pageFile, "w");
    char *line[100];

    for(int lineNumber = 0; lineNumber < CODE_LINES_PER_PAGE; lineNumber++ ){
        if(fgets(line, MAX_LENGTH, swapFile) != NULL){
            fprintf(newPage,"%s", line);
        }
        else{
            break;
        }
    }
}

void loadPage(int pageNumber, FILE *f, int frameNumber){

}

