// REFERENCE: https://www.youtube.com/watch?v=2uPKWpMHmZA
// Time Complexity: O(N)
// Space Complexity: O(logN)

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

// Side Note: Inorder traversal of Binary Search Tree will get increasing sequence

class Solution {
public:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = new TreeNode(INT_MIN);
    
    void recoverTree(TreeNode* root) {
        traverse(root);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
    
    void traverse(TreeNode* root) {
        if (root == nullptr)
        {
            return;
        }
        
        traverse(root->left);
        
        if (first == nullptr && prev->val > root->val)
        {
            first = prev;
        }
        
        // find second only if first is found
        if (first != nullptr && prev->val > root->val)
        {
            second = root;
        }
        
        prev = root;
        
        traverse(root->right);
    }
};