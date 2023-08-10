#ifndef _Queue_H_
#define _Queue_H_

#include <stdio.h>
#include <stdlib.h>
#include "Platform_Types.h"

typedef struct 
{
    void **QueueArray;
    uint32 maxSize;
    uint32 elementCount;
    sint32 front;
    sint32 rear;
}Queue_t;

typedef enum
{
    QUEUE_NOK = 0,
    QUEUE_OK,
    QUEUE_FULL,
    QUEUE_EMPTY,
    QUEUE_NULL_POINTER
}Queue_Status_t ;

Queue_t *QueueCreate(uint32 maxSize);
Queue_Status_t EnqueueElement(Queue_t *queue, void *item);
void *DequeueElement(Queue_t *queue, Queue_Status_t *status);
void *QueueFront(Queue_t *queue, Queue_Status_t *ret);
void *QueueRear(Queue_t *queue, Queue_Status_t *ret);
Queue_Status_t GetQueueCount(Queue_t *queue, uint32 *queueCount);
Queue_Status_t QueueDestroy(Queue_t *queue);

#endif /*_Queue_H_*/