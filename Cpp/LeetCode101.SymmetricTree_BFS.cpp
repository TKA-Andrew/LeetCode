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
    bool isSymmetric(TreeNode* root) {
        std::queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        
        while(!q.empty()) {
            int n = q.size();
            // n/2 because every time we pop 2 elements
            for (int i = 0; i < n/2; i++) {
                auto nodeLeft = q.front();
                q.pop();
                auto nodeRight = q.front();
                q.pop();
                
                if (nodeLeft == nullptr && nodeRight == nullptr)
                {
                    continue;
                }
                if (nodeLeft == nullptr || nodeRight == nullptr)
                {
                    return false;
                }
                
                if (nodeLeft->val != nodeRight->val) return false;
                
                q.push(nodeLeft->left);
                q.push(nodeRight->right);
                q.push(nodeLeft->right);
                q.push(nodeRight->left);

            }
        }
        return true;
    }
};