package algorithms.Insertion_Sort;

import java.util.Arrays;

public class InsertionSort
{
    void insertionSort(int arr[])
    {
        int size = arr.length;

        for(int i = 1; i < size; i++)
        {
            int temp = arr[i];
            int j = i - 1;
            while(j >= 0 && arr[j] > temp)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = temp;
        }
    }
 

    public static void main(String args[])
    {
        int arr[] = { 44, 1, 13, 9, 6 };
        
        InsertionSort ob = new InsertionSort();
        ob.insertionSort(arr);
        
        System.out.println(Arrays.toString(arr));
    }
};