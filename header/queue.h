//
// Created by daquan on 2019/1/17.
//
#include "binaryTree.h"
#ifndef DEMO2_QUEUE_H
#define DEMO2_QUEUE_H
typedef struct Queue Queue;
typedef struct Value Value;
struct Value{
    void *node;
};
struct Queue{
    Value value;
    Queue *first;
    Queue *next;
};
Queue* enqueue(Queue *,Value);
Queue* dequeue(Queue *);
int isEmpty(Queue *);
#endif //DEMO2_QUEUE_H
