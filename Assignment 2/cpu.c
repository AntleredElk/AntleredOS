//
// Created by antler on 2020-02-22.
//

struct CPU{
    int IP; //points to next instruction in ram
    char IR[1000];  //current instruction to be sent to interpreter
    int quanta; // 2 instructions per quanta
};
