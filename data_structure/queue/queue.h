#ifndef QUEUE_H
#define QUEUE_H

#define MAX_ELEMENTS 30

typedef struct queue Queue;

struct queue{

    int elements[MAX_ELEMENTS];
    int first;
    int last;

};

Queue* create(void);

Queue* insert(Queue* q, int value);

int unqueue(Queue* q);

int range(Queue* q);

void destroy(Queue* q);

#endif
