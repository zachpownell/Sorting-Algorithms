/*

 Name : Zach Pownell
 Description: C++ implementation of MergeSort sorting algorithm.

 */

#include <iostream>
using namespace std;

// Merges into two sub arrays from array[].
// First subarray is from the beginning of the array to the middle.
// Second subarray is from the middle + 1 of the array to the end.
void merge(int array[], int const left, int const middle, int const right) {

    int const subArrayOne = middle - left + 1;
    int const subArrayTwo = right - middle;

    // Create temp arrays.
    int *leftArray = new int[subArrayOne];
    int *rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[].
    for (int i = 0; i < subArrayOne; i++) leftArray[i] = array[left + i];
    for (int j = 0; j < subArrayTwo; j++) rightArray[j] = array[middle + 1 + j];

    int indexOfSubArrayOne = 0, // Initial index of first sub-array.
         indexOfSubArrayTwo = 0; // Initial index of second sub-array.
    int indexOfMergedArray = left; // Initial index of merged array.

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {

        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {

            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;

        } else {

            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;

        }

        indexOfMergedArray++;

    }
    // Copy the remaining elements of left[], if there are any.
    while (indexOfSubArrayOne < subArrayOne) {

        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;

    }
    // Copy the remaining elements of right[], if there are any.
    while (indexOfSubArrayTwo < subArrayTwo) {

        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;

    }

}

// begin is for left index and end is right index of the sub-array of arr to be sorted
void mergeSort(int array[], int const begin, int const end) {

    if (begin >= end) return; // Returns recursively

    auto middle = begin + (end - begin) / 2;
    mergeSort(array, begin, middle);
    mergeSort(array, middle + 1, end);
    merge(array, begin, middle, end);

}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int array[], int size) {

    for (int i = 0; i < size; i++) cout << array[i] << " ";

}

// Main method.
int main() {

    int array[] = {333, 11, 13, 5, 6, 7, 12};
    int arraySize = sizeof(array) / sizeof(array[0]);

    cout << "Unsorted Array: \n";
    printArray(array, arraySize);

    mergeSort(array, 0, arraySize - 1);

    cout << "\nSorted Array using MergeSort: \n";
    printArray(array, arraySize);

    return 0;

}
