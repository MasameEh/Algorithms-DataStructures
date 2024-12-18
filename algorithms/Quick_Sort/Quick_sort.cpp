#include <iostream>
#include <vector>

using namespace std;

void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}


int partition(vector<int>& arr, int low, int high) {

    int pivot = arr[high];

    // to put smaller elements in the right position
    int i = low - 1; 

    for(int j = low; j <= high - 1; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);  
    return i + 1;
}


// The QuickSort function implementation
void quickSort(vector<int>& arr, int low, int high) {
  
    if (low < high) {
      
        // p is the partition return index of pivot
        int p = partition(arr, low, high);

        // Recursion calls for smaller elements
        // and greater or equals elements
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main(){

    return 0;
}