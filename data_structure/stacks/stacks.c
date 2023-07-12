#include <stdio.h>
#include <stdlib.h>
#include "stacks.h"

#define MAX_ELEMENTS 30

typedef struct stack Stack;

struct stack{

    int elements[MAX_ELEMENTS];
    int top;

};

Stack* creat(void){

    Stack* s;
    s = malloc(sizeof(Stack));

    if(!s){

        perror(NULL);//perguntar
        exit(1);
        p->top = 0;

    }
}

Stack* stackup(Stack* s, int value){

    if(s->top == MAX_ELEMENTS - 1){

        printf("Stack is full...");
        exit(1);

    }

    s->elements[s->top] = value;
    s->top = s->top + 1;

}

Stack* unstack(Stack* s){

    if(s->top == 0){

        printf("Stack is empty...");
        exit(1);

    }
    s->top = s->top - 1;

    return s->elements[s->top];

}

int size(Stack* s){

    return s->top;

}

void free(Stack* s){

    free(s);

}



