#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right) {
    if (left > right) return nullptr;

    int mid = left + (right - left) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBST(nums, left, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, right);

    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBST(nums, 0, nums.size() - 1);
}

void printPreOrder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode* bst = sortedArrayToBST(nums);
    cout << "Preorder Traversal of BST: ";
    printPreOrder(bst);
    cout << endl;
    return 0;
}
