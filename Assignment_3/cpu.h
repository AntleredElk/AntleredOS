//
// Created by antler on 2020-02-29.
//

typedef struct{
    int IP; //points to next instruction in ram
    char IR[1000];  //current instruction to be sent to interpreter
    int quanta; // 2 instructions per quanta
}CPU;

extern int isBusy;
extern CPU *core;

void runCore(int quanta);