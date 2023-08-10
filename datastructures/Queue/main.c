#include "Queue.h"

uint32 queueMaxSize = 0;
Queue_t *queue;
uint32 num1 = 0x11, num2 = 0x22,  num3 = 0x33, num4 = 0x44, num5 = 0x55;
void *retVal;
uint32 queueCount = 0;
int main()
{
    Queue_Status_t queueStatus = QUEUE_NOK;
    printf("please enter the number of elements in the Queue : ");
    scanf("%d", &queueMaxSize);

    queue = QueueCreate(queueMaxSize);
    printf("%i\n", queueMaxSize);
    printf("0x%X \n", queue);

    queueStatus =  EnqueueElement(queue, &num1); printf("=> %d\n", queueStatus);
    queueStatus =  EnqueueElement(queue, &num2); printf("=> %d\n", queueStatus);
    queueStatus =  EnqueueElement(queue, &num3); printf("=> %d\n", queueStatus);
    retVal = QueueRear(queue, &queueStatus); printf("=> %d\n", queueStatus);
    printf("Rear Value is 0x%X \n", *((uint32 *)retVal));
    // queueStatus =  EnqueueElement(queue, &num4); printf("=> %d\n", queueStatus);
    queueStatus =  EnqueueElement(queue, &num5); printf("=> %d\n", queueStatus);
    
    queueStatus = GetQueueCount(queue, &queueCount); printf("=> %d\n", queueStatus);
    printf("Number of Elements at the Queue is %i\n", queueCount);

    retVal = DequeueElement(queue, &queueStatus); printf("=> %d\n", queueStatus);
    printf("Value is 0x%X \n", *((uint32 *)retVal)); 

    retVal = DequeueElement(queue, &queueStatus); printf("=> %d\n", queueStatus);
    printf("Value is 0x%X \n", *((uint32 *)retVal)); 
    retVal = DequeueElement(queue, &queueStatus); printf("=> %d\n", queueStatus);
    printf("Value is 0x%X \n", *((uint32 *)retVal)); 
    retVal = DequeueElement(queue, &queueStatus); printf("=> %d\n", queueStatus);
    retVal = DequeueElement(queue, &queueStatus); printf("=> %d\n", queueStatus);

    //queueStatus =  EnqueueElement(queue, &num5); printf("=> %d\n", queueStatus);

    // retVal = QueueFront(queue, &queueStatus); printf("=> %d\n", queueStatus);
    // printf("Front Value is 0x%X \n", *((uint32 *)retVal)); 

    // retVal = QueueRear(queue, &queueStatus); printf("=> %d\n", queueStatus);
    // printf("Rear Value is 0x%X \n", *((uint32 *)retVal));
    queueStatus =  QueueDestroy(queue); printf("Queue destroy status => %d\n", queueStatus);

    return 0;
}