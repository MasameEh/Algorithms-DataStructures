#include "Queue.h"



Queue_t *QueueCreate(uint32 maxSize)
{
    Queue_t *queue;
    queue = (Queue_t*)malloc(sizeof(Queue_t));

    if(NULL == queue)
    {
        printf("Error !! unable to create an object");
    }
    else
    {
        queue->QueueArray = (void **)calloc(maxSize,sizeof(void*));
        queue->elementCount = 0;
        queue->front = -1;
        queue->rear = -1;
        queue->maxSize = maxSize;
    }
    return queue;
}

Queue_Status_t EnqueueElement(Queue_t *queue, void *item)
{
    Queue_Status_t ret = QUEUE_NOK; 

    if(NULL == queue || NULL == item)
    {
        ret = QUEUE_NULL_POINTER;
    }
    else 
    {
        if(queue->elementCount == queue->maxSize)
        {
            ret = QUEUE_FULL;
            printf("Queue is FULL\n");
        }
        else
        {
            queue->rear++;
            queue->elementCount++;

            if(queue->rear == queue->maxSize)
            {
                queue->rear = 0;
            }else {}

            queue->QueueArray[queue->rear] = item;

            if(queue->rear == 0)
            {
                queue->front = 0;
            }else {}

            ret = QUEUE_OK;
        }
    }

    return ret;
}

void *DequeueElement(Queue_t *queue, Queue_Status_t *ret)
{
    void *returnedElement = NULL;

    if(NULL == queue || NULL == ret)
    {
        *ret = QUEUE_NULL_POINTER;
    }
    else 
    {   
        /* Check if the queue is empty */
        if(!queue->elementCount)
        {
            *ret = QUEUE_EMPTY;
            returnedElement = NULL;
        }
        else
        {
            /* Queue is not empty*/
            returnedElement = queue->QueueArray[queue->front];
            queue->front++;
            /* Queue front has wrapped to element 0 (cicrular queue)*/
            if(queue->front == queue->maxSize)
            {
                queue->front = 0;
            }else {}
            /* Check if the element is the last element in the queue*/
            if(1 == queue->elementCount)
            {   
                queue->front = -1;
                queue->rear = -1;
            }else{}

            queue->elementCount--;
            *ret = QUEUE_OK;
        }
    }
    return returnedElement;
}

void *QueueFront(Queue_t *queue, Queue_Status_t *ret)
{
    void *returnedElement = NULL;

    if(NULL == queue || NULL == ret)
    {
        *ret = QUEUE_NULL_POINTER;
    }
    else 
    {
         /* Check if the queue is empty */
        if(!queue->elementCount)
        {
            *ret = QUEUE_EMPTY;
            returnedElement = NULL;
        }
        else
        {
             /* Queue is not empty*/
            returnedElement = queue->QueueArray[queue->front];
            *ret = QUEUE_OK;
        }

    }
    return returnedElement;
}

void *QueueRear(Queue_t *queue, Queue_Status_t *ret)
{
    void *returnedElement = NULL;

    if(NULL == queue || NULL == ret)
    {
        *ret = QUEUE_NULL_POINTER;
    }
    else 
    {
         /* Check if the queue is empty */
        if(!queue->elementCount)
        {
            *ret = QUEUE_EMPTY;
            returnedElement = NULL;
        }
        else
        {
             /* Queue is not empty*/
            returnedElement = queue->QueueArray[queue->rear];
            *ret = QUEUE_OK;
        }

    }
    return returnedElement;
}

Queue_Status_t GetQueueCount(Queue_t *queue, uint32 *queueCount)
{
    Queue_Status_t ret = QUEUE_OK; 

    if(NULL == queue || NULL == queueCount)
    {
        ret = QUEUE_NULL_POINTER;
    }
    else 
    {
         if(!queue->elementCount)
        {
            *queueCount = 0;
            ret = QUEUE_EMPTY; ;
        }
        else
        {
             /* Queue is not empty*/
            *queueCount = queue->elementCount;
        }

    }
    return ret;
}

Queue_Status_t QueueDestroy(Queue_t *queue)
{
    Queue_Status_t ret = QUEUE_OK; 
    if(NULL == queue)
    {
        ret = QUEUE_NULL_POINTER;
    }
    else 
    {
        free(queue->QueueArray);
        free(queue);
    }
    return ret;
}