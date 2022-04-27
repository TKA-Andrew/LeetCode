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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root!=nullptr && subRoot!=nullptr && root->val == subRoot->val)
        {
            if (helper(root, subRoot))
            {
                return true;
            }
        }
        
        return (root->left && isSubtree(root->left, subRoot)) || (root->right && isSubtree(root->right, subRoot));
    }
    
    bool helper(TreeNode *root, TreeNode *subRoot)
    {
        
        if (root == nullptr && subRoot == nullptr)
        {
            return true;
        }
        
        if (root == nullptr || subRoot == nullptr)
        {
            return false;
        }
        
        if (root->val == subRoot->val)
        {
            if (helper(root->left, subRoot->left) && helper(root->right, subRoot->right))
            {
                return true;
            }
        }
        
        return false;
    }
};