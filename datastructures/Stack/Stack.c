#include "Stack.h"

/**
 * @brief Check if the stack is full
 * 
 * @param stack Pointer to the stack
 * @return stack_status_t status of the stack
 */
static stack_status_t isFull(Stack_t *stack)
{
    if(stack->stack_pointer == STACK_MAX_SIZE - 1)
    {
        return STACK_FULL;
    }
    else
        return STACK_NOT_FULL;
}

/**
 * @brief Check if the stack is empty
 * 
 * @param stack Pointer to the stack
 * @return stack_status_t status of the stack
 */
static stack_status_t isEmpty(Stack_t *stack)
{
    if(stack->stack_pointer == -1)
    {
        return STACK_EMPTY;
    }
    else
        return STACK_NOT_FULL;
}

/**
 * @brief initialize the Stack pointer
 * 
 * @param stack Pointer to the stack
 * @return return_status_t Status of initializtion process
 */
return_status_t stackCreate(Stack_t *stack)
{
    return_status_t ret = R_OK;

    if (NULL == stack)
    {
        ret = R_NOK;
    }
    else
    {
        stack->stack_pointer = -1;
    }
    
    return ret;
}

/**
 * @brief 
 * 
 * @param stack 
 * @param value 
 * @return return_status_t 
 */
return_status_t stackPush(Stack_t *stack, uint32 value)
{
    return_status_t ret = R_OK;
    if(NULL == stack || STACK_FULL == isFull(stack))
    {
        ret = R_NOK;
        printf("Erorr, cannot push %i to the stack\n", value);
    }
    else
    {
        stack->stack_pointer++;
        stack->data[stack->stack_pointer] = value;
        printf("%d pushed to stack\n", value);
    }
}
// return_status_t stackPop(Stack_t *stack, uint32 *value);
// return_status_t stackSize(Stack_t *stack, uint32 *size);
// return_status_t stackTop(Stack_t *stack, uint32 *value);
// return_status_t stackDisplay(Stack_t *stack);
