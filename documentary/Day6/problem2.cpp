#include <iostream>
using namespace std;

// Function to search for an element in an array
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Return the index where the element is found
        }
    }
    return -1;  // Return -1 if the element is not found
}

int main() {
    int arr[] = {5, 3, 7, 2, 8, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Enter the element to search: ";
    cin >> target;

    int result = linearSearch(arr, size, target);
    
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
