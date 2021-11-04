// time complexity: O(N)
// space complexity: O(N)

#include <unordered_map>

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
    std::unordered_map<TreeNode*, int> memo;
    
    int rob(TreeNode* root) {
        if (!root) return 0;
        if (memo[root]) {
            return memo[root];
        }
        int doIt = root->val + (root->left? rob(root->left->left) + rob(root->left->right) : 0)
            + (root->right? rob(root->right->left) + rob(root->right->right) : 0);
        int dontDoIt = rob(root->left) + rob(root->right);
        int res = std::max(doIt, dontDoIt);
        memo[root] = res;
        return res;
    }
};