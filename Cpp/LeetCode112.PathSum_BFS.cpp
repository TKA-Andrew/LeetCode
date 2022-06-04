#include <queue>

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if (root == nullptr) return false;

        std::queue<std::pair<TreeNode*, int>> q; 
        q.push({root, root->val});
        
        while(!q.empty())
        {
            int n = q.size();
            for (int i=0; i<n; i++)
            {
                auto currentPair = q.front();
                auto currentNode = currentPair.first;
                auto currentSum = currentPair.second;
                q.pop();
                
                if (currentNode->left == nullptr && currentNode->right == nullptr)
                {
                    if (currentSum == targetSum)
                        return true;
                } else {
                    if (currentNode->left) 
                        q.push({currentNode->left, currentSum+currentNode->left->val});
                    if (currentNode->right)
                        q.push({currentNode->right, currentSum+currentNode->right->val});             
                }
            }
        }
        
        return false;
    }
};