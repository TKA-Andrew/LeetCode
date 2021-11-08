#include <stddef.h> // for NULL

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return NULL;
        }
        if (root->val == key) {
            if (root->left == nullptr) {
                return root->right;
            }
            if (root->right == nullptr) {
                return root->left;
            }
            TreeNode* min = getMin(root->right);
            root->val = min->val;
            root->right = deleteNode(root->right, min->val);
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val <key) {
            root->right = deleteNode(root->right,key);
        }
        return root;
    }
    
    TreeNode* getMin(TreeNode* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }
};