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
    int getGrandchild(TreeNode* node)
    {
        if (node == nullptr) return 0;
        int sum = 0;
        if (node->left)
        {
            if (node->left->left) sum+=node->left->left->val;
            if (node->left->right) sum+=node->left->right->val;
        }
        if (node->right)
        {
            if (node->right->left) sum+=node->right->left->val;
            if (node->right->right) sum+=node->right->right->val;
        }
        return sum;
    }
    
    int dfs(TreeNode* node, int &sum)
    {
        if (node == nullptr) return 0;
        if (node->val % 2 == 0)
        {
            sum+=getGrandchild(node);
        }
        if (node->left) {
            dfs(node->left, sum);
        }
        if (node->right) {
            dfs(node->right, sum);
        }
        return sum;
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        return dfs(root, sum);
    }
};