//
// Created by antler on 2020-04-07.
//

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "ram.h"

int launcher(FILE *p);
int countTotalPages(FILE *f);

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
        countTotalPages(swapFile);

        addToRAM(swapFile);
        return 1;
    }
    else{
        //TODO what happens if launcher is unsuccessful?
        return 0;
    }
}

int countTotalPages(FILE *f){
    //TODO count the number of code line
    int numberOfLines =  countLine(f);
    //TODO If statement such that if total number of lines is less than 4 or inbetween, etc
    if(numberOfLines <= 4){

    }
    else if(numberOfLines <= 8 && numberOfLines > 4){

    }
    else{

    }
    //TODO Return total number of pages
}
