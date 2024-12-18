#include <iostream>
#include <vector>


void merge(int arr[], int left, int mid, int right){

    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1];
    int rigthArr[n2];

    for(int i = 0; i < n1; i++){
        leftArr[i] = arr[left + i];
    }

    for(int i = 0; i < n2; i++){
        rigthArr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0;

    // This indicates where to place the next smallest element 
    //as we merge elements from leftPart and rightPart back into the original array.

    int k = left; 
    
    while(i < n1 && j < n2){
        if(leftArr[i] <= rigthArr[j]){
            arr[k] = leftArr[i];
            i++;
        }else{
            arr[k] = rigthArr[j];
            j++;
        }
        k++;
    }
}

void mergeSort(int arr[], int left, int right){

    if(left < right){
        int mid = left + (right - left)/2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

