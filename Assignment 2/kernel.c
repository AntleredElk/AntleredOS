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

int main(int argc, const char *argv[]){
    shellUI();
}

void myinit(const char* path){
    addToRAM(path);
    head = addToReady(head, start, end);
    //scheduler

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


