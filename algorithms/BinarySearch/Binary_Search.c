#include <stdio.h>
#include <stdlib.h>

#define DATA_MAX_SIZE     10
#define ELEMENT_NOT_FOUND -1

typedef unsigned int uint32;
typedef signed int sint32;

sint32 My_Data[DATA_MAX_SIZE] = {11, 22, 33, 44, 55, 66, 77, 88 ,99 ,100};

sint32 binarySearchAlgorithm_1(sint32 data[], uint32 endIndex, uint32 startIndex, sint32 reqData);
sint32 binarySearchAlgorithm_2(sint32 data[], uint32 endIndex, uint32 startIndex, sint32 reqData);

int main()
{
    
    sint32 ret = 0;
    
    ret = binarySearchAlgorithm_1(My_Data, DATA_MAX_SIZE-1, 0, 11); //0
    printf("Element is found with index = %i \n", ret);

    ret = binarySearchAlgorithm_2(My_Data, DATA_MAX_SIZE-1, 0, 12); //-1
    printf("Element is found with index = %i \n", ret);

    ret = binarySearchAlgorithm_1(My_Data, DATA_MAX_SIZE-1, 0, 100); //9
    printf("Element is found with index = %i \n", ret);


    return  0;
}


/**
 * @brief Performs a binary search on a sorted array to find a specific element.
 * 
 * This function searches for a given element in a sorted array using the binary search algorithm.
 * It divides the array into two halves, compares the middle element with the requested value,
 * and adjusts the search range accordingly. The search continues until the element is found
 * or the search range is exhausted.
 * 
 * @param data The sorted array of elements to be searched.
 * @param endIndex The index representing the end of the search range.
 * @param startIndex The index representing the start of the search range.
 * @param reqData The element to be searched for.
 * @return sint32 The index of the first occurrence of the requested element in the array,
 *         or ELEMENT_NOT_FOUND if the element is not present in the array.
 */
sint32 binarySearchAlgorithm_1(sint32 data[], uint32 endIndex, uint32 startIndex, sint32 reqData)
{
    uint32 mid = 0;

    while (startIndex <= endIndex)
    {
        mid = startIndex + (endIndex - startIndex) / 2;

        if(reqData == data[mid])
        {
            return mid;
        }
        else if (reqData > data[mid])
        {
            startIndex = mid + 1;
        }
        else
        {
            endIndex = mid - 1; 
        }

    }
    // If we reach here, then element was not present
    return -1;
}

// Binary search but using recursion.
sint32 binarySearchAlgorithm_2(sint32 data[], uint32 endIndex, uint32 startIndex, sint32 reqData)
{
    uint32 mid = 0;

    while (startIndex <= endIndex)
    {
        mid = startIndex + (endIndex - startIndex) / 2;

        if(reqData == data[mid])
        {
            return mid;
        }
        else if (reqData > data[mid])
        {
            return binarySearchAlgorithm_2(data, endIndex, mid+1 , reqData);
        }
        else
        {
            return binarySearchAlgorithm_2(data, mid-1, startIndex , reqData);
        }

    }
    // If we reach here, then element was not present
    return -1;
}

