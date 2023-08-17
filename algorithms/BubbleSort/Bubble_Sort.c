#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DATA_MAX_SIZE  10

typedef unsigned int uint32;
typedef signed int sint32;

void swap(sint32 *num1, sint32 *num2);
void bubbleSortAlgorithm(sint32 data[], uint32 size);
void printArray(sint32 data[], uint32 size);

unsigned int data[DATA_MAX_SIZE] = {8, -1, 9, 5, 0, 7, 3, 2, 4, 6};


int main()
{
    printArray(data, DATA_MAX_SIZE);
    bubbleSortAlgorithm(data, DATA_MAX_SIZE);
    printArray(data, DATA_MAX_SIZE);

    return 0;
}

/**
 * @brief Swaps the values of two integers.
 * 
 * This function swaps the values of two integers using pointers. The values pointed to by
 * `num1` and `num2` are exchanged, effectively swapping the contents of the two variables.
 * 
 * @param num1 A pointer to the first integer.
 * @param num2 A pointer to the second integer.
 */
void swap(sint32 *num1, sint32 *num2)
{
    sint32 temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

/**
 * @brief Sorts an array of integers using the bubble sort algorithm.
 * 
 * This function performs the bubble sort algorithm on an array of integers. It iteratively
 * compares adjacent elements and swaps them if they are out of order, gradually pushing
 * the largest elements to the end of the array. The process is repeated until the entire
 * array is sorted.
 * 
 * @param data The array of integers to be sorted.
 * @param size The number of elements in the array.
 */
void bubbleSortAlgorithm(sint32 data[], uint32 size)
{
    uint32 i = 0, j = 0;
    bool swapped = false;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - 1 - i; j++)
        {
            if(data[j] > data[j + 1])
            {
                swap(&data[j], &data[j + 1]);
                swapped = true;
            }
        }
        // If no two elements were swapped by inner loop, then break
        if (swapped == false)
        {
            break;
        }
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