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
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> values;
        postOrderTraverse(root, values);
        return values;
    }
    
    void postOrderTraverse(TreeNode* root, std::vector<int>& values) {
        if (root == nullptr) {
            return;
        }
        
        postOrderTraverse(root->left, values);
        postOrderTraverse(root->right, values);
        
        values.push_back(root->val);
    }
};