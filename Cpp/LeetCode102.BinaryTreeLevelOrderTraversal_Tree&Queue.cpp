// REFERENCE; https://leetcode.com/problems/binary-tree-level-order-traversal/discuss/1979185/C%2B%2B-easy-solution-oror-using-queue-of-pairs..

#include <vector>
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
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> ans;
        if (root==nullptr)
        {
            return ans;
        }
        
        std::queue<std::pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while(!q.empty())
        {
            TreeNode *cur = q.front().first;
            int layer = q.front().second;
            q.pop();
            
            if (layer == 0)
            {
                ans.push_back({cur->val});
            } else {
                if (ans.size()<=layer)
                {
                    ans.push_back(vector<int>());
                    ans[layer].push_back(cur->val);
                } else {
                    ans[layer].push_back(cur->val);
                }
            }
            layer++;
            
            if (cur->left) q.push({cur->left, layer});
            if (cur->right) q.push({cur->right, layer});
        }
        
        
        return ans;
    }

};