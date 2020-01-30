//
// Created by antler on 2020-01-28.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "shellmemory.h"
#include "shell.h"

void interpreter(char *command, int nbrOfArguments, char **arguments){

    //If statements to figure out which command was used and how to proceed from there
    if(strncmp(command,"help", strlen("help")) == 0){ // Note that fgets will store a newline character or enter in the array. strncmp compares the first n bytes
        printf("help %15s Displays all the commands\n", " ");
        printf("quit %15s Exits / terminates the shell with “Bye!”\n", " ");
        printf("set VAR STRING %5s Assigns a value to shell memory\n", " ");
        printf("print VAR %10s Displays the STRING assigned to VAR\n", " ");
        printf("run %16s Executes the file SCRIPT.TXT\n", " ");
    }
    else if(strncmp(command,"quit", strlen("quit"))  == 0 ){
        printf("Bye!\n");
        exit(0);
    }
    else if(strncmp(command,"set", strlen("set"))  == 0){

        if(nbrOfArguments > 3 || nbrOfArguments < 3){
            printf("Invalid number of arguments\n");
        }
        else{
            store( arguments[1], arguments[2]);
        }

    }
    else if(strncmp(command,"print", strlen("print"))  == 0 ){

        if(nbrOfArguments > 2 || nbrOfArguments < 2){
            printf("Invalid number of arguments\n");
        }
        else{
           retrieve(arguments[1]);
        }
    }
    else if(strncmp(command,"run", strlen("run"))  == 0 ){

        if(nbrOfArguments > 2 || nbrOfArguments < 2){
            printf("Invalid number of arguments\n");
        }
        else{
            //Buffer to get rid of newline
            char *fileName;
            strcpy(fileName, arguments[1]);
            fileName[strlen(fileName)-1] = '\0';

            char line[1000];

            FILE *file = fopen(fileName, "r");

            if(file == NULL){
                printf("%s could not be found\n", fileName);
            }
            else {
                while (EOF != fscanf(file, "%1000[^\n]\n", line)) {
                    parseArgument(line);
                }
                fclose(file);
            }
        }
    }
    else{
        printf("Unknown command\n");
    }
}