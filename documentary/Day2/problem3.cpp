#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;

    int uniqueIndex = 0; // Points to the last unique element
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[uniqueIndex]) {
            ++uniqueIndex; // Move the unique index forward
            nums[uniqueIndex] = nums[i]; // Update the position with the unique value
        }
    }
    return uniqueIndex + 1; // Number of unique elements
}

int main() {
    vector<int> nums = {1, 1, 2, 3, 3, 4};
    int uniqueCount = removeDuplicates(nums);

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < uniqueCount; ++i) {
        cout << nums[i] << " ";
    }
    cout << "\nNumber of unique elements: " << uniqueCount << endl;

    return 0;
}
