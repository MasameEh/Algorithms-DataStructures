#ifndef _STACK_H_
#define _STACK_H_

#include "std_types.h"
#include <stdio.h>

#define STACK_MAX_SIZE 5


typedef struct Stack{
    uint32 stack_pointer;
    uint32 data[STACK_MAX_SIZE];
}Stack_t;

typedef enum stack_status{
    STACK_EMPTY,
    STACK_FULL,
    STACK_NOT_FULL
}stack_status_t;

/**
 * @brief Create a Stack object
 * 
 * @param stack Pointer to the stack
 * @return return_status_t Status of initilaiztion process
 */
return_status_t stackCreate(Stack_t *stack);
return_status_t stackPush(Stack_t *stack, uint32 value);
// return_status_t stackPop(Stack_t *stack, uint32 *value);
// return_status_t stackSize(Stack_t *stack, uint32 *size);
// return_status_t stackTop(Stack_t *stack, uint32 *value);
// return_status_t stackDisplay(Stack_t *stack);



#endif 