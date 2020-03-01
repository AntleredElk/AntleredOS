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

    while(1) {
        PCB *removedPCB = removeFromReady(head);
        core->IP = removedPCB->pCounter;
        core->quanta = 2;
        runCore(core->quanta);
        if (!(core->IP > removedPCB->endAdd)) {
            head = addToReady(head, core->IP, removedPCB->endAdd);
        } else {
            for (int cell = removedPCB->startAdd; cell <= removedPCB->endAdd; cell++) {
                ram[cell] = NULL;
            }
        }
    }
}


