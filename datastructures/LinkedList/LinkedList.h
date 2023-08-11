#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_


#include <stdio.h>
#include <stdlib.h>
#include "Platform_Types.h"



struct Node{
    uint32 NodeData;
    struct Node *NodeLink;
};

void insertNodeAtBeginning(struct Node **List);
void insertNodeAtEnd(struct Node **List);
void insertNodeAfter(struct Node *List);
void deleteNodeAtBeginning(struct Node **List);
void deleteNode(struct Node **List);
void displayAllNodes(struct Node *List);
uint32 getLength(struct Node *List);

#endif