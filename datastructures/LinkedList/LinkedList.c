#include "LinkedList.h"

void insertNodeAtBeginning(struct Node **List)
{
    struct Node *tempNode = NULL;
    tempNode = (struct Node *) malloc(sizeof(struct Node));

    if(NULL != tempNode)
    {
        printf("Enter Node Data : ");
        scanf("%i", &tempNode->NodeData);

        if(NULL == *List)
        {
            tempNode->NodeLink =NULL;
            *List = tempNode;
        }
        else
        {
            tempNode->NodeLink = *List;
            *List = tempNode;
        }
    }
    else
    {
        printf("Out of Memory Space:\n");
    }
}

void insertNodeAtEnd(struct Node **List)
{
    struct Node *tempNode = NULL;
    struct Node *lastNode = NULL;
    tempNode = (struct Node *) malloc(sizeof(struct Node));

    if(NULL != tempNode)
    {
        printf("Enter Node Data : ");
        scanf("%i", &tempNode->NodeData);
        tempNode->NodeLink = NULL;

        if(NULL == *List)
        {
            *List = tempNode;
        }
        else
        {   
            lastNode = *List;
            while (lastNode->NodeLink != NULL)
            {
                lastNode = lastNode->NodeLink;
            }
            lastNode->NodeLink = tempNode;
        }
    }
    else
    {
        printf("nOut of Memory Space:n");
    }
}

void insertNodeAfter(struct Node *List)
{
    struct Node *tempNode = NULL, *nodeListCounter = List;
    uint32 nodePosition = ZERO;    /*  */
    uint32 listLength = ZERO;      /*  */
    uint32 nodeCounter = 1;     /* Points to the first node */

    printf("Enter Node Position (First node is position = 1): ");
    scanf("%i", &nodePosition);

    listLength = getLength(List);

    if(nodePosition > listLength)
    {
        printf("Invalid Node Position -> List has ( %i ) Nodes \n", listLength);
    }
    else
    {
        
        // while (nodeCounter < nodePosition)
        // {
        //     nodeCounter++;
        //     nodeListCounter = nodeListCounter->NodeLink;
        // }
        for (nodeCounter = 1; nodeCounter < nodePosition; nodeCounter++)
        {
            nodeListCounter = nodeListCounter->NodeLink;
        }

        tempNode = (struct Node *)malloc(sizeof(struct Node));
         if(NULL != tempNode)
        {
            printf("Enter Node Data : ");
            scanf("%i", &tempNode->NodeData);

            tempNode->NodeLink = nodeListCounter->NodeLink;
            nodeListCounter->NodeLink = tempNode;
        }else{}

    }
}

void deleteNodeAtBeginning(struct Node**List)
{
    struct Node *tempNode = *List;
    uint32 listLength = ZERO;

    listLength = getLength(*List);
    if (ZERO == listLength)
    {
        printf("List is Empty , nothing to be deleted !! \n");
    }
    else
    {
       *List = tempNode->NodeLink;
       tempNode->NodeLink = NULL;
       free(tempNode); 
    }
    
}

void deleteNode(struct Node **List)
{
    struct Node *nextNode = NULL;
    struct Node *nodeListCounter = *List;
    uint32 nodePosition = ZERO;
    uint32 listLength = ZERO;
    uint32 nodeCounter = 1;

    printf("Enter Node Position (First node is position = 1): ");
    scanf("%i", &nodePosition);

    listLength = getLength(*List);

    if (nodePosition > listLength)
    {
        printf("Invalid Node Position -> List has ( %i ) Nodes\n", listLength);
    }
    else if (1 == listLength)
    {
        deleteNodeAtBeginning(List);
    }
    else
    {
        for (nodeCounter = 1; nodeCounter < (nodePosition - 1); nodeCounter++)
        {
            nodeListCounter = nodeListCounter->NodeLink;
        }
        nextNode = nodeListCounter->NodeLink;
        nodeListCounter->NodeLink = nextNode->NodeLink;
        free(nextNode);
    }
}


void displayAllNodes(struct Node *List)
{
    struct Node *tempNode = List;

    printf("Node Values : ");
    if(NULL == tempNode){
        printf("List is empty !! \n");
    }
    else{
        while(tempNode != NULL){
            printf("%i -> ", tempNode->NodeData);
            tempNode = tempNode->NodeLink;
        }
        if(NULL == tempNode){
            printf("NULL \n");
        }
    }
}

uint32 getLength(struct Node *List)
{
    struct Node *tempNode = List;
    uint32 nodeCount = ZERO;

    while(tempNode != NULL){
        nodeCount++;
        tempNode = tempNode->NodeLink;
    }

    return nodeCount;
}