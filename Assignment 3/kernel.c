//
// Created by antler on 2020-02-22.
//
#include "shell.h"
#include "pcb.h"
#include "ram.h"
#include "cpu.h"
#include "interpreter.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

void myinit(const char* path);
void scheduler();
void boot();
int kernel();

int main(int argc, const char *argv[]){
    int error = 0;
    boot();
    error = kernel();
    return error;
}

void myinit(const char* path){
    addToRAM(path);
    head = addToReady(head, start, end);
    //scheduler

}

void boot(){
    // Assumes RAM array is of size 40

    //Initializes every cell of the array to NULL
    for (int i = 0; i < 40; i++ ){
        ram[i] == NULL;
    }
    char command[30];
    strcpy(command, "rm -rf BackingStore");
    system(command);
    strcpy(command, "mkdir BackingStore");
    system(command);
}

int kernel(){
    return shellUI();
}

void scheduler(){
    core = malloc(sizeof(CPU));
    int running = 1;

    while(running) {
        PCB *removedPCB = readFromReady(head);
        core->IP = removedPCB->pCounter;
        core->quanta = 2;
        runCore(core->quanta);
        if (core->IP <= removedPCB->endAdd) {
            removeFromReady();
            head = addToReady(head, core->IP, removedPCB->endAdd);
        }
        else if (core->IP > removedPCB->endAdd) {
            for (int cell = removedPCB->endAdd-removedPCB->pCounter; cell <= removedPCB->endAdd; cell++) {
                ram[cell] = NULL;
            }
        }
        for(int cell = 0; cell<= SIZE_OF_RAM; cell++){
            if (ram[cell] != NULL){
                break;
            }
            running = 0;
        }
    }
}


