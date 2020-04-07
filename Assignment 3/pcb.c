//
// Created by antler on 2020-02-22.
//

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int pCounter; // The program counter will be an integer number that refers to the cell number of ram[] containing the instruction to execute
    int startAdd; // Ram start cell
    int endAdd; // Ram end cell
    struct PCB* next;
}PCB;

PCB* head;

PCB* makePCB(int start, int end, PCB* next){
    PCB* new_pcb = (PCB*)malloc(sizeof(PCB));
    if(new_pcb == NULL){
        printf("Error");
        return 1;
    }
    new_pcb ->startAdd = start;
    new_pcb ->pCounter = start;
    new_pcb ->endAdd = end;
    new_pcb ->next = next;
    return new_pcb;
}

PCB* addToReady(PCB* head, int start, int end){
    if(head == NULL){
        head = (PCB*)malloc(sizeof(PCB));
        head = makePCB(start, end, NULL);
    }
    else {
        PCB *cursor = head;
        while (cursor->next != NULL) {
            cursor = cursor->next;
        }
        PCB *new_pcb = makePCB(start, end, NULL);
        cursor->next = new_pcb;
    }

    return head;
}

void removeFromReady(){
    if(head == NULL) {
        //return NULL;
    }
    PCB *front = head;
    head = head->next;
    front->next = NULL;

    if(front == head) {
        head = NULL;
    }
    free(front);
    //return head;
}

PCB* readFromReady(PCB* head){
    if(head == NULL) {
        return NULL;
    }
    PCB *front = head;
    //head = head->next;
    //front->next = NULL;

    if(front == head) {
        head = NULL;
    }
    //free(front);
    return front;
}

void print_list(PCB* head){
    PCB* cursor = head;
    while(cursor != NULL){
        printf("%d\n", cursor -> endAdd);
        cursor = cursor -> next;
    }
}
