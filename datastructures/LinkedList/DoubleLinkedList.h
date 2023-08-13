#ifndef DOUBLE_LINKED_LIST_H_
#define DOUBLE_LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include "Platform_Types.h"

struct Node{
    uint32 NodeData;
    struct Node *LeftNodeLink;
    struct Node *RightNodeLink;
};


void insertNodeAtBeginning(struct Node **List, uint32 Data);
void insertNodeAtEnd(struct Node **List, uint32 Data);
void insertNodeAfter(struct Node *List, uint32 Data, uint32 position);
void insertNodeBefore(struct Node **List, uint32 Data, uint32 position);
void deleteNodeAtBeginning(struct Node **List);
void deleteNodeAtEnd(struct Node *List);
void deleteNodeAtIntermediate(struct Node **List, uint32 position);
void displayAllNodesForward(struct Node *List);


#endif /*DOUBLE_LINKED_LIST_H_*/