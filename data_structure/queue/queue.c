#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define MAX_ELEMENTS 30

typedef struct queue Queue;

struct queue{

    int elements[MAX_ELEMENTS];
    int first;
    int last;

};

Queue* create(void){

    Queue* q;
    q = malloc(sizeof(Queue));

    if(!q){

        perror(NULL);
        exit(1);

    }

    q->last = 0;
    q->firt = 0;

    return q;

}

Queue* insert(Queue* q, int value){

    if((q->last + 1 == q->first) || (q->last == MAX_ELEMENTS - 1 && q->first == 0)){

        printf("Queue is full...");
        exit(1);

    }

    q->elements[q->last] = value;
    q->last = q->last + 1;

    if(q->last == MAX_ELEMENTS){

        q->-last = 0;

    }

}

int unqueue(Queue* q){

    if(q->first == q->last){

        printf("Queue is empty...");
        exit(1);

    }

    q->first = q->first + 1;

    if(q->first == MAX_ELEMENTS){

        q->first = 0;

    }

    return q->elements[q->first - 1];

}

int range(Queue* q){

    int r = q->last - q->first;

    if(r <= 0){

        r = r + MAX_ELEMENTS;

    }

    return r;

}

void destroy(Queue* q){

free(q);

}







