#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interpreter.h"

void parse();

int main() {

    printf("Welcome to the Antlered shell!\n");
    printf("Version 1.0 Created January 2020\n");

    do{
        printf("$ ");
        parse();
    }while(1);

    return 0;
}

void parse() {
    char input[100]; // here, a character array of 100 is used, as directly using a pointer * is not initialized, and will throw segmentation fault
    char **arguments;
    char command[100];
    int index = 0;
    int nbrOfArguments = 1;

    fgets(input ,100 ,stdin);

    for(int positionInString = 0; positionInString <strlen(input); positionInString++){
        if(input[positionInString] == ' '){
            nbrOfArguments++;
        }
    }

//    Test to determine argument count
//    printf("%d\n", nbrOfArguments);

    arguments = (char**)malloc(nbrOfArguments*sizeof(char*));

    for (int index = 0; index < nbrOfArguments; index++){
        arguments[index] = (char*)malloc(100*sizeof(char));
    }

    char *tokenizer = strtok(input, " ");

    while (tokenizer != NULL) {
        arguments[index++] = tokenizer;
        tokenizer = strtok(NULL, " ");

    }
    strcpy(command, arguments[0]); // Stores argument 0 in command so that interpreter can read

//    Test to see if correct arguments are isolated
//    for (index = 0; index < nbrOfArguments; index++){
//        printf("%s\n", arguments[index]);
//    }
    interpreter(command, arguments);

    free(arguments);
    free(*arguments);
}
