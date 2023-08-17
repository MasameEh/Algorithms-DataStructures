#include <stdio.h>
#include <stdlib.h>

#define DATA_MAX_SIZE  10

typedef unsigned int uint32;
typedef signed int sint32;

void insertionSortAlgorithm(sint32 data[], uint32 size);
void printArray(sint32 data[], uint32 size);

sint32 data[DATA_MAX_SIZE] = {80, 18, 59, -5, -3, 17, 3, -12, 43, 56};

int main()
{

    printArray(data, DATA_MAX_SIZE);
    insertionSortAlgorithm(data, DATA_MAX_SIZE);
    printArray(data, DATA_MAX_SIZE);

    return 0;
}


/**
 * @brief Sorts an array of integers using the insertion sort algorithm.
 * 
 * This function performs the insertion sort algorithm on an array of integers. It iterates through
 * the array, gradually building a sorted portion by inserting each element into its correct position
 * among the already sorted elements. The process is repeated until the entire array is sorted.
 * 
 * @param data The array of integers to be sorted.
 * @param size The number of elements in the array.
 */
void insertionSortAlgorithm(sint32 data[], uint32 size)
{
    uint32 i = 0;
    sint32 compIndex = 0, key = 0;
    
    for (i = 1; i < size; i++)
    {
        key = data[i];
        compIndex = i - 1;

        while (compIndex >= 0 && data[compIndex] > key)
        {
            data[compIndex + 1] = data[compIndex];
            compIndex--; 
        }
        data[compIndex + 1] = key;
    }
    
}

/**
 * @brief Prints the elements of an array.
 * 
 * This function prints the elements of an array to the standard output. It iterates through
 * the array and prints each element, separated by a tab, followed by a newline character.
 * 
 * @param data The array of elements to be printed.
 * @param size The number of elements in the array.
 */
void printArray(sint32 data[], uint32 size)
{
    uint32 i = 0;

    for (i = 0; i < size; i++)
    {
        printf("%d\t", data[i]);
    }
    printf("\n");
}