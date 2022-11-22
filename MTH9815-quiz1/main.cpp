//
//  main.cpp
//  MTH9815-quiz1
//
//  Created by Nicolas Buchwalder on 22.11.22.
//

#include "MaxHeap.h"

#include <iostream>



// EXERCISE 1

// function to print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

// function to split the array into values smaller or bigger than pivot (last element)
int split(int arr[], int low, int high)
{
    // value of pivot (chose the highest value here)
    int p = arr[high];
    // starting index
    int i = low - 1;
    
    // iterating over the whole array (or subarray)
    for (int j = low; j < high; j++) {
        // putting values before if smaller than pivot
        if (arr[j] < p) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    // swapping with pivot
    std::swap(arr[i + 1], arr[high]);
    // returning where to do the partition
    return i + 1;
}
  
// recursive implementation of quicksort algorithm
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        // getting the partition split index
        int split_idx = split(arr, low, high);
        // doing it recursively for both sub arrays
        quickSort(arr, low, split_idx - 1);
        quickSort(arr, split_idx + 1, high);
    }
}


// EXERCISE 2 : see MaxHeap.h file



int main(int argc, const char * argv[]) {

    // EXERCISE 1
    
    int arr1[7] = {6, 4, 3, 2, 3, 7, 1};
    std::cout << "Unsorted array:" << std::endl;
    printArray(arr1, 7);
    
    // getting the size of one element
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    quickSort(arr1, 0, size1 - 1);
    
    
    std::cout << "Sorted array:" << std::endl;
    printArray(arr1, 7);
    
    
    // EXERCISE 2
    
    MaxHeap h;
    
    h.Add(1);
    h.print();
    
    h.Add(2);
    h.print();
    
    h.Add(2);
    h.print();
    
    h.Add(5);
    h.print();
    
    h.Add(3);
    h.print();
    
    h.Add(4);
    h.print();
    
    
    
    
}
