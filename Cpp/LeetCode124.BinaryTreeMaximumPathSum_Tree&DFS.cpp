#include <math.h>

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
    int ans = 0;
    int maxPathSum(TreeNode* root) {
        if (root!=nullptr)
        {
            ans = root->val;
        }
        dfs(root);
        return ans;
    }
    
    int dfs(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        
        int leftMax = dfs(root->left);
        int rightMax = dfs(root->right);
        leftMax = std::max(leftMax, 0);
        rightMax = std::max(rightMax, 0);
        
        ans = std::max(ans, root->val+leftMax+rightMax);

        return root->val + std::max(leftMax, rightMax);
    }
};