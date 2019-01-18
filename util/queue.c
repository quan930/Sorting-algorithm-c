//
// Created by daquan on 2019/1/17.
//

#include "../header/queue.h"
#include "stdio.h"
#include <stdlib.h>
/**
 * 入队
 * @param queue 队尾
 * @param value 值
 * @return 队尾
 */
Queue* enqueue(Queue* queue,Value value){
    if (queue==NULL){
        queue = calloc(1,sizeof(Queue));
        queue->value = value;
        queue->first = queue;
        return queue;
    } else{
        queue->next = calloc(1,sizeof(Queue));
        queue->next->first = queue->first;
        queue->next->value = value;
        return queue->next;
    }
}
Queue* dequeue(Queue* queue){
    if (!isEmpty(queue))
        return NULL;
    else{
        Queue *queue1 = queue->first;
        queue->first = queue->first->next;
        free(queue1);
        return queue;
    }
}
int isEmpty(Queue* queue){
    if (queue->first==NULL)
        return 0;
    return 1;
}
