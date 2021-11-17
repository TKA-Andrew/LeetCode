// time complexity: O(N)
// space complexity: O(N)

#include <vector>
#include <limits.h> // for INT_MIN & INT_MAX

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
    int rootIdx;

    TreeNode* bstFromPreorder(std::vector<int>& preorder) {
        rootIdx = 0;
        return reconstruct(preorder, INT_MIN, INT_MAX);
    }
    
    TreeNode* reconstruct(std::vector<int>& preorder, int min, int max) {
        int nodeSize = preorder.size();
        if (rootIdx == nodeSize){
            return nullptr;
        }
        int rootValue = preorder[rootIdx];
        if (rootValue<min || rootValue>=max) {
            return nullptr;
        }
        rootIdx++;
        auto bst = new TreeNode(rootValue);
        bst->left = reconstruct(preorder, min, rootValue);
        bst->right = reconstruct(preorder, rootValue, max);
        return bst;
    }
};