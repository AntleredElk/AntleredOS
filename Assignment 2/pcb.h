//
// Created by antler on 2020-02-28.
//

typedef struct{
    int pCounter; // The program counter will be an integer number that refers to the cell number of ram[] containing the instruction to execute
    int startAdd; // Ram start cell
    int endAdd; // Ram end cell
    struct PCB* next;
}PCB;

extern PCB* head;

PCB* makePCB(int start, int end, PCB* next);
PCB* addToReady(PCB* head, int start, int end);
PCB* removeFromReady(PCB* head);
void print_list(PCB* head);