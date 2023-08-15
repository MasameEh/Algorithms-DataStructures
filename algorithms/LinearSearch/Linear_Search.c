#include <stdio.h>
#include <stdlib.h>

#define DATA_MAX_SIZE     10
#define ELEMENT_NOT_FOUND -1

typedef unsigned int uint32;
typedef signed int sint32;

uint32 My_Data[DATA_MAX_SIZE] = {11, 22, 33, 44, 55, 66, 77, 88 ,99 ,100};

sint32 linearSearchAlgorithm_1(uint32 data[], uint32 size, uint32 reqData);
sint32 linearSearchAlgorithm_2(uint32 data[], uint32 size, uint32 reqData);

int main()
{
    
    sint32 ret = linearSearchAlgorithm_1(My_Data, DATA_MAX_SIZE, 99); //6
    printf("Element is found with index = %i \n", ret);
    
    ret = linearSearchAlgorithm_2(My_Data, DATA_MAX_SIZE, 99); //6
    printf("Element is found with index = %i \n", ret);

    return  0;
}


/**
 * @brief Performs a linear search on an array to find a specific element.
 * 
 * This function searches for a given element in an array using the linear search algorithm.
 * It iterates through each element of the array and compares it with the specified element
 * to determine if a match is found.
 * 
 * @param data The array of elements to be searched.
 * @param size The number of elements in the array.
 * @param reqData The element to be searched for.
 * @return uint32 The index of the first occurrence of the requested element in the array,
 *         or ELEMENT_NOT_FOUND if the element is not present in the array.
 */
sint32 linearSearchAlgorithm_1(uint32 data[], uint32 size, uint32 reqData)
{
    uint32 index = 0;

    for (index = 0; index < size; index++)
    {
        if(reqData == data[index])
        {
            return index;
        }
    }
    // If we reach here, then element was not present
    return ELEMENT_NOT_FOUND;
}


sint32 linearSearchAlgorithm_2(uint32 data[], uint32 size, uint32 reqData)
{
    uint32 leftIndex = 0;
    uint32 rightIndex = size - 1;
    
    for (leftIndex = 0; leftIndex < rightIndex;)
    {
        if(reqData == data[leftIndex])
        {
            return leftIndex;
        }
        else if (reqData == data[rightIndex])
        {
            return rightIndex;
        }else{ }
        
        leftIndex++;
        rightIndex--;
    }
    // If we reach here, then element was not present
    return ELEMENT_NOT_FOUND;
}