#include <vector>

// Assuming TreeNode is already defined in the environment
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution {
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
    }
    
private:
    TreeNode* sortedArrayToBSTHelper(const std::vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        
        // Choose the middle element as the root
        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        
        // Recursively build the left and right subtrees
        node->left = sortedArrayToBSTHelper(nums, left, mid - 1);
        node->right = sortedArrayToBSTHelper(nums, mid + 1, right);
        
        return node;
    }
};