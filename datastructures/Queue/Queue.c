#include "Queue.h"

/**
 * @brief Creates a new queue with the specified maximum size.
 * 
 * @param maxSize Maximum size of the queue.
 * @return A pointer to the newly created Queue_t structure.
 */
Queue_t *QueueCreate(uint32 maxSize)
{
    // Allocate memory for the queue structure
    Queue_t *queue;
    queue = (Queue_t*)malloc(sizeof(Queue_t));

    if(NULL == queue)
    {
        printf("Error !! unable to create an object");
    }
    else
    {
        // Initialize queue properties
        queue->QueueArray = (void **)calloc(maxSize,sizeof(void*));
        queue->elementCount = ZERO;
        queue->front = -1;
        queue->rear = -1;
        queue->maxSize = maxSize;
    }
    return queue;
}

/**
 * @brief Enqueues an element into the queue.
 * 
 * @param queue Pointer to the queue.
 * @param item Pointer to the item to be enqueued.
 * @return Queue_Status_t indicating the result of the operation.
 */
Queue_Status_t EnqueueElement(Queue_t *queue, void *item)
{
    Queue_Status_t ret = QUEUE_NOK; 

    if(NULL == queue || NULL == item)
    {
        ret = QUEUE_NULL_POINTER;
    }
    else 
    {
        // Check if the queue is full
        if(queue->elementCount == queue->maxSize)
        {
            ret = QUEUE_FULL;
            printf("Queue is FULL\n");
        }
        else
        {
            // Add item to the rear of the queue
            queue->rear++;
            queue->elementCount++;

            // Handle circular queue wrapping
            if(queue->rear == queue->maxSize)
            {
                queue->rear = ZERO;
            }
            
            queue->QueueArray[queue->rear] = item;

            // Update front index if this is the first element
            if(queue->rear == ZERO)
            {
                queue->front = ZERO;
            }
            
            ret = QUEUE_OK;
        }
    }

    return ret;
}

/**
 * @brief Dequeues an element from the queue.
 * 
 * @param queue Pointer to the queue.
 * @param ret Pointer to a Queue_Status_t to store the operation result.
 * @return Pointer to the dequeued element.
 */
void *DequeueElement(Queue_t *queue, Queue_Status_t *ret)
{
    void *returnedElement = NULL;

    if(NULL == queue || NULL == ret)
    {
        *ret = QUEUE_NULL_POINTER;
    }
    else 
    {   
        // Check if the queue is empty
        if(!queue->elementCount)
        {
            *ret = QUEUE_EMPTY;
            returnedElement = NULL;
        }
        else
        {
            // Dequeue element from the front
            returnedElement = queue->QueueArray[queue->front];
            queue->front++;

            // Handle circular queue wrapping
            if(queue->front == queue->maxSize)
            {
                queue->front = ZERO;
            }

            // Check if this was the last element in the queue
            if(1 == queue->elementCount)
            {   
                queue->front = -1;
                queue->rear = -1;
            }

            queue->elementCount--;
            *ret = QUEUE_OK;
        }
    }
    return returnedElement;
}

/**
 * @brief Gets the front element of the queue without removing it.
 * 
 * @param queue Pointer to the queue.
 * @param ret Pointer to a Queue_Status_t to store the operation result.
 * @return Pointer to the front element of the queue.
 */
void *QueueFront(Queue_t *queue, Queue_Status_t *ret)
{
    void *returnedElement = NULL;

    if(NULL == queue || NULL == ret)
    {
        *ret = QUEUE_NULL_POINTER;
    }
    else 
    {
         // Check if the queue is empty
        if(!queue->elementCount)
        {
            *ret = QUEUE_EMPTY;
            returnedElement = NULL;
        }
        else
        {
             // Get the front element without dequeuing
            returnedElement = queue->QueueArray[queue->front];
            *ret = QUEUE_OK;
        }

    }
    return returnedElement;
}

/**
 * @brief Gets the rear element of the queue without removing it.
 * 
 * @param queue Pointer to the queue.
 * @param ret Pointer to a Queue_Status_t to store the operation result.
 * @return Pointer to the rear element of the queue.
 */
void *QueueRear(Queue_t *queue, Queue_Status_t *ret)
{
    void *returnedElement = NULL;

    if(NULL == queue || NULL == ret)
    {
        *ret = QUEUE_NULL_POINTER;
    }
    else 
    {
         // Check if the queue is empty
        if(!queue->elementCount)
        {
            *ret = QUEUE_EMPTY;
            returnedElement = NULL;
        }
        else
        {
             // Get the rear element without removing
            returnedElement = queue->QueueArray[queue->rear];
            *ret = QUEUE_OK;
        }

    }
    return returnedElement;
}

/**
 * @brief Gets the count of elements in the queue.
 * 
 * @param queue Pointer to the queue.
 * @param queueCount Pointer to a uint32 variable to store the queue count.
 * @return Queue_Status_t indicating the result of the operation.
 */
Queue_Status_t GetQueueCount(Queue_t *queue, uint32 *queueCount)
{
    Queue_Status_t ret = QUEUE_OK; 

    if(NULL == queue || NULL == queueCount)
    {
        ret = QUEUE_NULL_POINTER;
    }
    else 
    {
         // Check if the queue is empty
        if(!queue->elementCount)
        {
            *queueCount = ZERO;
            ret = QUEUE_EMPTY; ;
        }
        else
        {
             // Get the element count of the queue
            *queueCount = queue->elementCount;
        }

    }
    return ret;
}

/**
 * @brief Destroys the queue and frees associated memory.
 * 
 * @param queue Pointer to the queue to be destroyed.
 * @return Queue_Status_t indicating the result of the operation.
 */
Queue_Status_t QueueDestroy(Queue_t *queue)
{
    Queue_Status_t ret = QUEUE_OK; 
    if(NULL == queue)
    {
        ret = QUEUE_NULL_POINTER;
    }
    else 
    {
        // Free memory allocated for the queue's element array and the queue structure
        free(queue->QueueArray);
        free(queue);
    }
    return ret;
}
