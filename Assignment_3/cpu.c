//
// Created by antler on 2020-02-22.
//
#include <stdlib.h>
#include <string.h>
#include "pcb.h"
#include "interpreter.h"
#include "ram.h"
#include <stdio.h>

typedef struct{
    int IP; //points to next instruction in ram
    char IR[1000];  //current instruction to be sent to interpreter
    int quanta; // 2 instructions per quanta

}CPU;

CPU *core;
int isBusy;

void runCore(int quanta){
    isBusy = 1;

    for(int instruction = quanta; instruction > 0; instruction--){
        strcpy(core->IR, ram[core->IP]);
        core->IP++;
        interpret(core->IR);
    }

    isBusy = 0;
}

