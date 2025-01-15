#include <iostream>
using namespace std;

// Function to search in the 2D matrix
bool searchInMatrix(int matrix[][4], int rows, int cols, int target) {
    int i = 0;       // Start from the first row
    int j = cols - 1; // Start from the last column
    
    while (i < rows && j >= 0) {
        if (matrix[i][j] == target) {
            cout << "Element found at (" << i << ", " << j << ")" << endl;
            return true; // Element found
        } else if (matrix[i][j] < target) {
            i++; // Move down
        } else {
            j--; // Move left
        }
    }
    return false; // Element not found
}

int main() {
    // Example 2D matrix (sorted in ascending order)
    int matrix[4][4] = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };
    
    int target = 5;
    
    if (!searchInMatrix(matrix, 4, 4, target)) {
        cout << "Element not found in the matrix." << endl;
    }
    
    return 0;
}

