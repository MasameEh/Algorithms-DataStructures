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

/**
 * @brief Inserts a new node at the beginning of the doubly linked list.
 * 
 * @param List Pointer to the head pointer of the list.
 * @param Data Data value to be stored in the new node.
 */
void insertNodeAtBeginning(struct Node **List, uint32 Data);

/**
 * @brief Inserts a new node at the end of the doubly linked list.
 * 
 * @param List Pointer to the head pointer of the list.
 * @param Data Data value to be stored in the new node.
 */
void insertNodeAtEnd(struct Node **List, uint32 Data);

/**
 * @brief Inserts a new node after a specified position in the doubly linked list.
 * 
 * @param List Pointer to the head node of the list.
 * @param Data Data value to be stored in the new node.
 * @param position Position after which the new node is to be inserted.
 */
void insertNodeAfter(struct Node *List, uint32 Data, uint32 position);

/**
 * @brief Inserts a new node before a specified position in the doubly linked list.
 * 
 * @param List Pointer to the head node of the list.
 * @param Data Data value to be stored in the new node.
 * @param position Position after which the new node is to be inserted.
 */
void insertNodeBefore(struct Node **List, uint32 Data, uint32 position);

/**
 * @brief Delete a new node at the beginning of the list
 * 
 * @param List Pointer to the head node of the list.
 */
void deleteNodeAtBeginning(struct Node **List);

/**
 * @brief Delete a new node at the end of the list
 * 
 * @param List Pointer to the head node of the list.
 */
void deleteNodeAtEnd(struct Node *List);

/**
 * @brief Delete a new node at a specified position in the doubly linked list.
 * 
 * @param List Pointer to the head node of the list.
 * @param position Position which the node is to be deleted.
 */
void deleteNodeAtIntermediate(struct Node **List, uint32 position);

/**
 * @brief Displays all nodes in the doubly linked list in forward order.
 * 
 * @param List Pointer to the head node of the list.
 */
void displayAllNodesForward(struct Node *List);


#endif /*DOUBLE_LINKED_LIST_H_*/