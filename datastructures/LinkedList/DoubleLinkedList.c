#include "DoubleLinkedList.h"

void insertNodeAtBeginning(struct Node **List, uint32 Data)
{
    // Allocate memory for the new node
    struct Node *tempNode = NULL;
    tempNode = (struct Node *) malloc(sizeof(struct Node));

    if(NULL != tempNode)
    {
        tempNode->NodeData = Data;
        // Check if the list is empty 
        if(NULL == *List)
        {
            tempNode->LeftNodeLink = NULL;
            tempNode->RightNodeLink = NULL;
            *List = tempNode; // Make the head pointer points to this only node
        }
        else
        {
            // Make the new node the head
            tempNode->RightNodeLink = *List; 
            tempNode->LeftNodeLink = NULL;
            (*List)->LeftNodeLink = tempNode;
            *List = tempNode;
        }
    }
    else
    {
        printf("Out of Memory Space:\n");
    }

}


void insertNodeAtEnd(struct Node **List, uint32 Data)
{
    // Allocate memory for the new node
    struct Node *tempNode = NULL;
    tempNode = (struct Node *) malloc(sizeof(struct Node));
    struct Node *lastNode = NULL;

    if(NULL != tempNode)
    {
        tempNode->NodeData = Data;
        tempNode->RightNodeLink = NULL;
        // Check if the list is empty 
        if(NULL == *List)
        {
            tempNode->LeftNodeLink = NULL;
            *List = tempNode; // Make the head pointer points to this only node
        }
        else
        {
            lastNode = *List;
            // Traverse to the last node
            while (NULL != lastNode->RightNodeLink)
            {
                lastNode = lastNode->RightNodeLink;
            }
            lastNode->RightNodeLink = tempNode; // Make the last node points to the new node
            tempNode->LeftNodeLink = lastNode; 
        }
    }
    else
    {
        printf("Out of Memory Space:\n");       
    }
}


void insertNodeAfter(struct Node *List, uint32 Data, uint32 position)
{
    struct Node *tempNode = NULL; // Points to the new node 
    struct Node *previousNode = NULL;  // Traverse to the needed node 
    struct Node *nextNode = NULL;  
    
    previousNode = List; // Points to the head node now 
    // Traverse to the needed node
    while(1 != position)
    {
        previousNode = previousNode->RightNodeLink;
        position--;
    }

    tempNode = (struct Node *) malloc(sizeof(struct Node));

    if(NULL != tempNode)
    {
        tempNode->NodeData = Data;
        // Check if we reach the End Node of the List :: Adding the new node at the end 
        if(NULL == previousNode->RightNodeLink)
        {
            previousNode->RightNodeLink = tempNode;
            tempNode->RightNodeLink = NULL;
            tempNode->LeftNodeLink = previousNode;
        }
        else
        {   
            nextNode = previousNode->RightNodeLink;
            // Update the information of the new node
            tempNode->RightNodeLink = nextNode;
            tempNode->LeftNodeLink = previousNode;
            nextNode->LeftNodeLink = tempNode;
            previousNode->RightNodeLink = tempNode; 
        }
        
    }
    else
    {
        printf("Out of Memory Space:\n");       
    }

}


void insertNodeBefore(struct Node **List, uint32 Data, uint32 position)
{
    struct Node *tempNode = NULL; // Points to the new node 
    struct Node *previousNode = NULL;  // Traverse to the needed node 
    struct Node *nextNode = NULL; 
    uint32 nodePos = position;
    nextNode = *List; 
    // Traverse to the needed node 
    while(1 != position)
    {
        nextNode = nextNode->RightNodeLink;
        position--;
    }

    tempNode = (struct Node *) malloc(sizeof(struct Node));

    if(NULL != tempNode)
    {
        tempNode->NodeData = Data;
        // Check if we at first Node of the List :: Adding the new node at the beginning
        if(1 == nodePos)
        {
            tempNode->RightNodeLink = *List;
            tempNode->LeftNodeLink = NULL;
            (*List)->LeftNodeLink = tempNode;
            *List = tempNode;
        }
        else
        {   
            previousNode = nextNode->LeftNodeLink;
            // Update the information of the new node
            tempNode->RightNodeLink = nextNode;
            tempNode->LeftNodeLink = previousNode;
            nextNode->LeftNodeLink = tempNode;
            previousNode->RightNodeLink = tempNode; 
        }
        
    }
    else
    {
        printf("Out of Memory Space:\n");       
    }

}


void deleteNodeAtBeginning(struct Node **List)
{
    // Check if the list is empty
    if(NULL != *List)
    {
        *List = (*List)->RightNodeLink;
        /* Free the first node */
        free((*List)->LeftNodeLink);
        (*List)->LeftNodeLink = NULL;
    }
    else
    {
        // List is empty
        printf("List is Empty , nothing to be deleted !! \n");
    }
}


void deleteNodeAtEnd(struct Node *List)
{
    struct Node *prevLastNode = NULL;
    struct Node *lastNode = List;
    // Check if the list is empty
    if(NULL != List)
    {
        while (NULL != lastNode->RightNodeLink)
        {
            lastNode = lastNode->RightNodeLink;
        }
        prevLastNode = lastNode->LeftNodeLink;
        prevLastNode->RightNodeLink = NULL;
        free(lastNode);
        lastNode = NULL;
    }
    else
    {
        // List is empty
        printf("List is Empty , nothing to be deleted !! \n");
    }
}


void deleteNodeAtIntermediate(struct Node **List, uint32 position)
{   
    struct Node *previousNode = NULL;  // Traverse to the needed node 
    struct Node *nextNode = *List; 
    
    // Check if the list is empty
    if(NULL != *List)
    {
        if(1 == position)
        {
            deleteNodeAtBeginning(List);
        }
        else
        {
            while(1 != position)
            {
                nextNode = nextNode->RightNodeLink;
                position--;
            }
            if (NULL != nextNode->RightNodeLink)
            {
                previousNode = nextNode->LeftNodeLink;
                previousNode->RightNodeLink = nextNode->RightNodeLink;
                nextNode->RightNodeLink->LeftNodeLink = previousNode;
            
                free(nextNode);
                nextNode = NULL;
            }
            else
            {
                deleteNodeAtEnd(*List);
            }
            
        }
    }
    else
    {
        // List is empty
        printf("List is Empty , nothing to be deleted !! \n");
    }
}


void displayAllNodesForward(struct Node *List)
{
    struct Node *tempNode = List;

    printf("\nTraversal in forward direction ==> ");
    printf("Data : ");
    printf("%d -> ", tempNode->NodeData);
    while(tempNode->RightNodeLink != NULL){
        tempNode = tempNode->RightNodeLink;
        printf("%d -> ", tempNode->NodeData);
    }
    if(NULL == tempNode->RightNodeLink){
        printf("NULL");
    }
    printf("\n");
}