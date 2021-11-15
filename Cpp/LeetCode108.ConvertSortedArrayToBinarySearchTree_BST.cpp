// time complexity: O(N)
// space complexity: O(N)

#include <vector>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return constructMinHeightBST(nums, 0, nums.size() -1);
    }
    
    TreeNode* constructMinHeightBST(std::vector<int>& nums, int startIdx, int endIdx) {
        if (endIdx<startIdx) {
            return nullptr;
        }
        
        int midIdx = (startIdx + endIdx)/2;
        TreeNode* root = new TreeNode(nums[midIdx]);
        root->left = constructMinHeightBST(nums, startIdx, midIdx-1);
        root->right = constructMinHeightBST(nums, midIdx+1, endIdx);
        return root;
    }
};