
#include "Stack.h"

Stack_t stack;
uint32 stackPopValue = ZERO;
uint32 stackTopValue = ZERO;
uint32 stackSizeValue = ZERO;

int main()
{
   return_status_t ret = R_NOK;
   ret = stackCreate(&stack);

   if(ret == R_NOK)
   {
        printf("Stack failed to be initialized\n");
   }
   else
   {
     ret = stackPush(&stack, 11);
     ret = stackPush(&stack, 12);
     ret = stackPush(&stack, 13);
     ret = stackPush(&stack, 14);
     ret = stackPush(&stack, 7);
     ret = stackTop(&stack, &stackTopValue);
     ret = stackDisplay(&stack);
     stackSize(&stack, &stackSizeValue);
     printf("Size of the Stack is %d", stackSizeValue);
   }
  
    return 0;
}