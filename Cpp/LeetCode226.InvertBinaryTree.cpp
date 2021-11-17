// time complexity: O(N)
// space complexity: O(d) //depth of tree

#include <algorithm> // for swap

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
    TreeNode* invertTree(TreeNode* root) {
        invertHelper(root);
        return root;
    }
    
    void invertHelper(TreeNode* root) {
        if (root==nullptr) {
            return;
        }
        std::swap(root->left, root->right);
        invertHelper(root->left);
        invertHelper(root->right);
    }
};