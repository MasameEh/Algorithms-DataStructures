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
 * @return return_status_t If the operation is successful, it returns R_OK; otherwise, it returns R_NOK.
 */
return_status_t stackCreate(Stack_t *stack);

/**
 * @brief Push value to the stack
 * 
 * @param stack A pointer to the stack
 * @param value Value to be pushed to the stack
 * @return return_status_t If the operation is successful, it returns R_OK; otherwise, it returns R_NOK.
 */
return_status_t stackPush(Stack_t *stack, uint32 value);

/**
 * @brief Pop value to the stack
 * 
 * @param stack A pointer to the stack
 * @param value Value to be popped to the stack
 * @return return_status_t If the operation is successful, it returns R_OK; otherwise, it returns R_NOK.
 */
return_status_t stackPop(Stack_t *stack, uint32 *value);

/**
 * @brief Returns the current size of the stack.
 * 
 * @param stack A pointer to the stack
 * @param size  A pointer to a variable where the calculated stack size will be stored.
 * @return return_status_t If the operation is successful, it returns R_OK; otherwise, it returns R_NOK.
 */
return_status_t stackSize(Stack_t *stack, uint32 *size);

/**
 * @brief Retrieves the value at the top of the stack.
 * 
 * @param stack A pointer to the stack
 * @param value A pointer to a variable where the retrieved value will be stored.
 * @return return_status_t If the operation is successful, it returns R_OK; otherwise, it returns R_NOK.
 */
return_status_t stackTop(Stack_t *stack, uint32 *value);

/**
 * @brief Displays the contents of the stack.
 * 
 * @param stack A pointer to the stack
 * @return return_status_t If the operation is successful, it returns R_OK; otherwise, it returns R_NOK. 
 */
return_status_t stackDisplay(Stack_t *stack);



#endif 