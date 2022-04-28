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
    typedef std::priority_queue <int, std::vector<int>, std::greater<int>> MinHeap;
    
    int kthSmallest(TreeNode* root, int k) {
        MinHeap minHeap;
        dfs(minHeap, root);
        int i = 1;
        while (i!=k)
        {
            minHeap.pop();
            i++;
        }
        return minHeap.top();
    }
    
    void dfs(MinHeap &minHeap, TreeNode* root)
    {
        if (root==nullptr)
        {
            return;
        }
        minHeap.push(root->val);
        dfs(minHeap, root->left);
        dfs(minHeap, root->right);
    }
};