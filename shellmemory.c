//
// Created by antler on 2020-01-28.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct memory {
    char var[100];
    char value[100];
};

struct memory array[100];

int arrayIndex = 0;

void store( char* argument1, char* argument2){
    struct memory data;
    strcpy(data.var,argument1);
    strcpy(data.value, argument2);

    array[arrayIndex] = data;
    arrayIndex++;
};

void retrieve(char* argument1){
    int checkIndex = 99;
    int match = 0;

    // Works down the array to determine which variable was last updated, and to use that.
    //If variable is not declared then say so
    for(int index = 0; index < 100; index++){
        if(strncmp(array[checkIndex].var,argument1, strlen(array[checkIndex].var))==0
        && strlen(array[checkIndex].var) > 0){
            match = 1;
            printf("%s", array[checkIndex].value);
            break;
        }
        else {
            match = 0;
            checkIndex--;
        }
    }
    if(match == 0) printf("Variable does not exist\n");

    //TODO implement error for if not found
}