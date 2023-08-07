
#include "Stack.h"

Stack_t stack;

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
    ret = stackPush(&stack, 22);
    ret = stackPush(&stack, 17);
    ret = stackPush(&stack, 55);
    ret = stackPush(&stack, 17);

   }
  
    return 0;
}