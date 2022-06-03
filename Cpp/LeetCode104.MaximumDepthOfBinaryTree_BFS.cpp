#include <queue>

/**
 * 
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
    
    int bfs(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        
        std::queue<TreeNode*> q;
        
        int depth = 0;
        q.push(root);
        
        while (!q.empty())
        {
            int qsize = q.size();
            for(int i=0; i<qsize; i++)
            {
                auto cur = q.front();
                q.pop();

                if (cur->left != nullptr)
                    q.push(cur->left);
                if (cur->right != nullptr)
                    q.push(cur->right);
            }
            depth++;
        }
        return depth;
    }
    
    int maxDepth(TreeNode* root) {
        return bfs(root);
    }
};