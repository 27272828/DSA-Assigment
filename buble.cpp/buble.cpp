#include <iostream>
using namespace std;

void pointerBubbleSort(int* arr[], int n) {
    for (int i = 0; i < n - 1; i++) {  // Loop through each pass
        for (int j = 0; j < n - i - 1; j++) {  // Loop through the unsorted portion
            if (*arr[j] > *arr[j + 1]) {  // Compare the values pointed to by arr[j] and arr[j + 1]
                // Swap the values if they are out of order
                swap(*arr[j], *arr[j + 1]);  // Dereference the pointers to swap the values
            }
        }
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Create an array of pointers
    int* ptrArr[n];
    for (int i = 0; i < n; i++) {
        ptrArr[i] = &arr[i];  // Point each element of ptrArr to the corresponding element in arr
    }

    // Call pointerBubbleSort
    pointerBubbleSort(ptrArr, n);
    
    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << *ptrArr[i] << " ";  // Dereference the pointer to print the value
    }
    return 0;
}