#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_


#include <stdio.h>
#include <stdlib.h>
#include "Platform_Types.h"



struct Node{
    uint32 NodeData;
    struct Node *NodeLink;
};

/**
 * @brief Inserts a new node at the beginning of the linked list.
 * 
 * @param List A pointer to the head of the linked list.
 */
void insertNodeAtBeginning(struct Node **List);

/**
 * @brief Inserts a new node at the end of the linked list.
 * 
 * @param List A pointer to the head of the linked list.
 */
void insertNodeAtEnd(struct Node **List);

/**
 * @brief Inserts a new node after a specified position in the linked list.
 * 
 * @param List A pointer to the head of the linked list.
 */
void insertNodeAfter(struct Node *List);

/**
 * @brief Deletes the first node in the linked list.
 * 
 * @param List A pointer to the head of the linked list.
 */
void deleteNodeAtBeginning(struct Node **List);

/**
 * @brief Deletes a node at a specified position in the linked list.
 * 
 * @param List A pointer to the head of the linked list.
 */
void deleteNode(struct Node **List);

/**
 * @brief Displays all nodes in the linked list.
 * 
 * @param List A pointer to the head of the linked list.
 */
void displayAllNodes(struct Node *List);

/**
 * @brief Calculates the length of the linked list.
 * 
 * @param List A pointer to the head of the linked list.
 * @return uint32 The length of the linked list.
 */
uint32 getLength(struct Node *List);

#endif