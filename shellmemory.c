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
    int checkIndex = 0;

    //Compares the first n bytes to exclude the \n
    while(strncmp(array[checkIndex].var,argument1, strlen(array[checkIndex].var))!=0){
      checkIndex++;
    }
    printf("%s", array[checkIndex].value);
}