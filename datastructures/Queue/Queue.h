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

/**
 * @brief Creates a new queue with the specified maximum size.
 * 
 * @param maxSize Maximum size of the queue.
 * @return A pointer to the newly created Queue.
 */
Queue_t *QueueCreate(uint32 maxSize);

/**
 * @brief Enqueues an element into the queue.
 * 
 * @param queue Pointer to the queue.
 * @param item Pointer to the item to be enqueued.
 * @return Queue_Status_t indicating the result of the operation.
 */
Queue_Status_t EnqueueElement(Queue_t *queue, void *item);

/**
 * @brief Dequeues an element from the queue.
 * 
 * @param queue Pointer to the queue.
 * @param ret Pointer to a Queue_Status_t to store the operation result.
 * @return Pointer to the dequeued element.
 */
void *DequeueElement(Queue_t *queue, Queue_Status_t *status);

/**
 * @brief Gets the front element of the queue without removing it.
 * 
 * @param queue Pointer to the queue.
 * @param ret Pointer to a Queue_Status_t to store the operation result.
 * @return Pointer to the front element of the queue.
 */
void *QueueFront(Queue_t *queue, Queue_Status_t *ret);

/**
 * @brief Gets the rear element of the queue without removing it.
 * 
 * @param queue Pointer to the queue.
 * @param ret Pointer to a Queue_Status_t to store the operation result.
 * @return Pointer to the rear element of the queue.
 */
void *QueueRear(Queue_t *queue, Queue_Status_t *ret);

/**
 * @brief Gets the count of elements in the queue.
 * 
 * @param queue Pointer to the queue.
 * @param queueCount Pointer to a uint32 variable to store the queue count.
 * @return Queue_Status_t indicating the result of the operation.
 */
Queue_Status_t GetQueueCount(Queue_t *queue, uint32 *queueCount);

/**
 * @brief Destroys the queue and frees associated memory.
 * 
 * @param queue Pointer to the queue to be destroyed.
 * @return Queue_Status_t indicating the result of the operation.
 */
Queue_Status_t QueueDestroy(Queue_t *queue);

#endif /*_Queue_H_*/