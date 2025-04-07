#include<iostream>
#include <climits> 

using namespace std;

void findSecondOrThirdLargest(int arr[], int n, bool findThird = false) {
    if (n < 2) {
        cout << "Array does not have enough elements." << endl;
        return;
    }

    
    int first = INT_MIN, second = INT_MIN, third = INT_MIN;

    
    for (int i = 0; i < n; i++) {
        
        if (arr[i] > first) {
            third = second;
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            third = second;
            second = arr[i];
        } else if (arr[i] > third && arr[i] != second && arr[i] != first) {
            third = arr[i];
        }
    }

    if (findThird) {
        
        if (third == INT_MIN) {
            cout << "Array does not have a third largest distinct element." << endl;
        } else {
            cout << "Third largest: " << third << endl;
        }
    } else {
       
        if (second == INT_MIN) {
            cout << "Array does not have a second largest distinct element." << endl;
        } else {
            cout << "Second largest: " << second << endl;
        }
    }
}

int main() {
    int arr[] = {120, 45, 67, 89, 34, 23, 90, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    
    findSecondOrThirdLargest(arr, n, false);

    
    findSecondOrThirdLargest(arr, n, true);

    return 0;
}