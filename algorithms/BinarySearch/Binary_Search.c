#include <stdio.h>
#include <stdlib.h>

#define DATA_MAX_SIZE     10
#define ELEMENT_NOT_FOUND -1

typedef unsigned int uint32;
typedef signed int sint32;

uint32 My_Data[DATA_MAX_SIZE] = {11, 22, 33, 44, 55, 66, 77, 88 ,99 ,100};

sint32 binarySearchAlgorithm_1(uint32 data[], uint32 endIndex, uint32 startIndex ,uint32 reqData);
sint32 binarySearchAlgorithm_2(uint32 data[], uint32 endIndex, uint32 startIndex ,uint32 reqData);

int main()
{
    
    uint32 ret = 0;
    
    ret = binarySearchAlgorithm_1(My_Data, DATA_MAX_SIZE-1, 0, 22); //1
    printf("Element is found with index = %i \n", ret);

    ret = binarySearchAlgorithm_2(My_Data, DATA_MAX_SIZE-1, 0, 22); //4
    printf("Element is found with index = %i \n", ret);

    return  0;
}


/**
 * @brief 
 * 
 * @param data 
 * @param endIndex 
 * @param startIndex 
 * @param reqData 
 * @return sint32 
 */
sint32 binarySearchAlgorithm_1(uint32 data[], uint32 endIndex, uint32 startIndex ,uint32 reqData)
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
    return ELEMENT_NOT_FOUND;
}


sint32 binarySearchAlgorithm_2(uint32 data[], uint32 endIndex, uint32 startIndex ,uint32 reqData)
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
            //startIndex = mid + 1;
        }
        else
        {
            return binarySearchAlgorithm_2(data, mid-1, startIndex , reqData);
            //endIndex = mid - 1; 
        }

    }
    // If we reach here, then element was not present
    return ELEMENT_NOT_FOUND;
}