#include "LinkedList.h"

/**
 * @brief Inserts a new node at the beginning of the linked list.
 * 
 * @param List A pointer to the head of the linked list.
 */
void insertNodeAtBeginning(struct Node **List)
{
    // Allocate memory for the new node
    struct Node *tempNode = NULL;
    tempNode = (struct Node *) malloc(sizeof(struct Node));

    if(NULL != tempNode)
    {
        // Prompt user for input
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

/**
 * @brief Inserts a new node at the end of the linked list.
 * 
 * @param List A pointer to the head of the linked list.
 */
void insertNodeAtEnd(struct Node **List)
{
    // Allocate memory for the new node
    struct Node *tempNode = NULL;
    struct Node *lastNode = NULL;
    tempNode = (struct Node *) malloc(sizeof(struct Node));

    if(NULL != tempNode)
    {
        // Prompt user for input
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
        printf("Out of Memory Space:\n");
    }
}

/**
 * @brief Inserts a new node after a specified position in the linked list.
 * 
 * @param List A pointer to the head of the linked list.
 */
void insertNodeAfter(struct Node *List)
{
    struct Node *tempNode = NULL, *nodeListCounter = List;
    uint32 nodePosition = ZERO;    /*  */
    uint32 listLength = ZERO;      /*  */
    uint32 nodeCounter = 1;     /* Points to the first node */

    // Prompt user for position
    printf("Enter Node Position (First node is position = 1): ");
    scanf("%i", &nodePosition);

    listLength = getLength(List);

    if(nodePosition > listLength)
    {
        printf("Invalid Node Position -> List has ( %i ) Nodes \n", listLength);
    }
    else
    {
        // Find the node after which to insert
        for (nodeCounter = 1; nodeCounter < nodePosition; nodeCounter++)
        {
            nodeListCounter = nodeListCounter->NodeLink;
        }

        tempNode = (struct Node *)malloc(sizeof(struct Node));
        if(NULL != tempNode)
        {
            // Prompt user for input
            printf("Enter Node Data : ");
            scanf("%i", &tempNode->NodeData);

            // Insert the new node
            tempNode->NodeLink = nodeListCounter->NodeLink;
            nodeListCounter->NodeLink = tempNode;
        }
    }
}

/**
 * @brief Deletes the first node in the linked list.
 * 
 * @param List A pointer to the head of the linked list.
 */
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
       // Update the head and free the first node
       *List = tempNode->NodeLink;
       tempNode->NodeLink = NULL;
       free(tempNode); 
    }
}

/**
 * @brief Deletes a node at a specified position in the linked list.
 * 
 * @param List A pointer to the head of the linked list.
 */
void deleteNode(struct Node **List)
{
    struct Node *nextNode = NULL;
    struct Node *nodeListCounter = *List;
    uint32 nodePosition = ZERO;
    uint32 listLength = ZERO;
    uint32 nodeCounter = 1;

    // Prompt user for position
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
        // Traverse to the node before the one to be deleted
        for (nodeCounter = 1; nodeCounter < (nodePosition - 1); nodeCounter++)
        {
            nodeListCounter = nodeListCounter->NodeLink;
        }
        nextNode = nodeListCounter->NodeLink;

        // Update pointers and free the deleted node
        nodeListCounter->NodeLink = nextNode->NodeLink;
        free(nextNode);
    }
}

/**
 * @brief Displays all nodes in the linked list.
 * 
 * @param List A pointer to the head of the linked list.
 */
void displayAllNodes(struct Node *List)
{
    struct Node *tempNode = List;

    printf("Node Values : ");
    if(NULL == tempNode)
    {
        printf("List is empty !! \n");
    }
    else
    {
        while(tempNode != NULL)
        {
            printf("%i -> ", tempNode->NodeData);
            tempNode = tempNode->NodeLink;
        }
        if(NULL == tempNode)
        {
            printf("NULL \n");
        }
    }
}

/**
 * @brief Calculates the length of the linked list.
 * 
 * @param List A pointer to the head of the linked list.
 * @return uint32 The length of the linked list.
 */
uint32 getLength(struct Node *List)
{
    struct Node *tempNode = List;
    uint32 nodeCount = ZERO;

    while(tempNode != NULL)
    {
        nodeCount++;
        tempNode = tempNode->NodeLink;
    }

    return nodeCount;
}
