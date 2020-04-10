//
// Created by antler on 2020-04-07.
//

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "ram.h"
#include "kernel.h"
#include "pcb.h"

#define CODE_LINES_PER_PAGE 4

int launcher(FILE *p);
int countTotalPages(FILE *f);
char* createFilePath(char* BackingStoreDir, char* PCBTemplate, int PID);
void populatePage(FILE *swapFile, char*pageFile);
void loadPage(int PID, FILE *f, int frameNumber);
void createPage(FILE *swapFile, char **logicalMemory);
int findFrame();
int findVictim(PCB* pcb);

int PID = 0;
int startPage;

int launcher(FILE *p){
    int offset = 0;
    char *logicalMemory[10];
    int frameNumber = 0;

    if (1){
        startPage = PID;
        int Totalpages = countTotalPages(p);
        createPage(p, logicalMemory);
        int frame = findFrame();
        if(frame > -1){
        }
        else{
           //TODO find Victim
        }
        for (int pagesRemaining = 0; pagesRemaining < Totalpages; pagesRemaining++) {
            loadPage(pagesRemaining, fopen(logicalMemory[startPage + pagesRemaining], "r"), frame);
            flag = 1;
        }

        PID++;
        return 1;
    }
    else{
        //TODO what happens if launcher is unsuccessful?
        return 0;
    }
}

int countTotalPages(FILE *swapFile){
    int numberOfLines =  countLine(swapFile);

    int numberOfPages = (int)ceil(numberOfLines/(float)4);
    rewind(swapFile);

    return numberOfPages;

}
void createPage(FILE *swapFile, char **logicalMemory){
    int numberOfLines =  countLine(swapFile);

    char pageFilePath[100];
    char BackingStoreDir[100] = "./BackingStore/";
    char PCBTemplate[30] = "PCB";

    int numberOfPages = ceil(numberOfLines/(float)4);

    rewind(swapFile);

    strcpy(pageFilePath, createFilePath(BackingStoreDir, PCBTemplate, PID));
    populatePage(swapFile, pageFilePath);
    //Stores page address into logical memory
    logicalMemory[PID] = malloc(sizeof(char*)+1);
    strcpy(logicalMemory[PID], pageFilePath);


    for(int i=0; i<numberOfPages-1; i++){
        //Resets for each new page
        PID++;
        strcpy(BackingStoreDir, "./BackingStore/");
        strcpy(PCBTemplate, "PCB");
        //  ^

        strcpy(pageFilePath, createFilePath(BackingStoreDir, PCBTemplate, PID));
        populatePage(swapFile, pageFilePath);
        //Stores page address into logical memory
        logicalMemory[PID] = malloc(sizeof(char*)+1);
        strcpy(logicalMemory[PID], pageFilePath);
    }
    strcpy(BackingStoreDir, "./BackingStore/");

    //Prints array for logicalMemory
    for(int page = 0; page < numberOfPages; page++){
        printf("Page address: %s\n", logicalMemory[page]);
    }
}
char* createFilePath(char* BackingStoreDir, char* PCBTemplate, int PID){
    BackingStoreDir[100] = "./BackingStore/";

    char PIDString[30];
    char command[30] = "touch ";

    snprintf(PIDString, 30,"%d", PID);
    strcat(PCBTemplate, PIDString);
    strcat(BackingStoreDir, PCBTemplate);
    strcat(BackingStoreDir, ".txt\0");
    strcat(command, BackingStoreDir);

    system(command);



    return BackingStoreDir;
}
void populatePage(FILE *swapFile, char *pageFile){
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
    fclose(newPage);
}

void loadPage(int offset, FILE *page, int frameNumber){
    addToRAM(page, frameNumber);

}

int findFrame(){
    int cell;

    for(cell = 0; cell < SIZE_OF_RAM; cell+=3){
        if(ram[cell] == NULL && ram[cell+1] == NULL && ram[cell+2] == NULL && ram[cell+3] == NULL){
            return floor((cell+1)/4);
        }
    }
    return -1;
   // for (int cell = 0;)
}

int findVictim(PCB* pcb){

}

