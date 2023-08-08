#include "Stack.h"

/**
 * @brief Check if the stack is full
 * 
 * @param stack A pointer to the stack
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
 * @param stack A pointer to the stack
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
 * @param stack A pointer to the stack
 * @return return_status_t If the operation is successful, it returns R_OK; otherwise, it returns R_NOK.
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
 * @brief Push value to the stack
 * 
 * @param stack A pointer to the stack
 * @param value Value to be pushed to the stack
 * @return return_status_t If the operation is successful, it returns R_OK; otherwise, it returns R_NOK.
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
    return ret;
}

/**
 * @brief Pop value to the stack
 * 
 * @param stack A pointer to the stack
 * @param value Value to be popped to the stack
 * @return return_status_t If the operation is successful, it returns R_OK; otherwise, it returns R_NOK.
 */
return_status_t stackPop(Stack_t *stack, uint32 *value)
{
    return_status_t ret = R_OK;

    if(NULL == stack || STACK_EMPTY == isEmpty(stack) || NULL == value)
    {
        ret = R_NOK;

        printf("Erorr, cannot pop from the stack\n");
    }
    else
    {
        *value = stack->data[stack->stack_pointer];
        stack->stack_pointer--;
        printf("Value %d popped from the stack\n", *value);
    }
    return ret;
}

/**
 * @brief Returns the current size of the stack.
 * 
 * @param stack A pointer to the stack
 * @param size  A pointer to a variable where the calculated stack size will be stored.
 * @return return_status_t If the operation is successful, it returns R_OK; otherwise, it returns R_NOK.
 */
return_status_t stackSize(Stack_t *stack, uint32 *size)
{
    return_status_t ret = R_OK;

    if(NULL == stack || NULL == size)
    {
        ret = R_NOK;
    }
    else
    {
        *size = stack->stack_pointer + 1;
    }
    return ret;
}

/**
 * @brief Retrieves the value at the top of the stack.
 * 
 * @param stack A pointer to the stack
 * @param value A pointer to a variable where the retrieved value will be stored.
 * @return return_status_t If the operation is successful, it returns R_OK; otherwise, it returns R_NOK.
 */
return_status_t stackTop(Stack_t *stack, uint32 *value)
{
     return_status_t ret = R_OK;

    if(NULL == stack || STACK_EMPTY == isEmpty(stack) || NULL == value)
    {
        ret = R_NOK;
        printf("Erorr, stack is empty !!\n");
    }
    else
    {
        *value = stack->data[stack->stack_pointer];
        printf("Value %d is the top of the stack\n", *value);
    }
    return ret;
}

/**
 * @brief Displays the contents of the stack.
 * 
 * @param stack A pointer to the stack
 * @return return_status_t If the operation is successful, it returns R_OK; otherwise, it returns R_NOK. 
 */
return_status_t stackDisplay(Stack_t *stack)
{
    return_status_t ret = R_OK;
    sint32 c = ZERO;

    if(NULL == stack || STACK_EMPTY == isEmpty(stack))
    {
        ret = R_NOK;
        printf("Erorr, stack is empty !!\n");
    }
    else
    {
        printf("Stack data: ");
        for (c = stack->stack_pointer; c >= 0; c--)
        {
            printf("%d\t", stack->data[c]);
        }
        printf("\n");
    }
    return ret;
}
