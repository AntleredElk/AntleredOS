//
// Created by antler on 2020-04-07.
//

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int launcher(FILE *p);

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

        return 1;
    }
    else{
        //TODO
        return 0;
    }
}
