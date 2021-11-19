// time complexity: O(n)
// space complexity: O(h)

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
    struct TreeInfo {
        int maxdiameter;
        int height;
    };
    
    int diameterOfBinaryTree(TreeNode* root) {
        return getTreeInfo(root).maxdiameter;
    }
    
    TreeInfo getTreeInfo(TreeNode* root) {
        if (root==nullptr) {
            return {0,0};
        }
        
        TreeInfo leftTree = getTreeInfo(root->left);
        TreeInfo rightTree = getTreeInfo(root->right);
        int diameterThroughRoot = leftTree.height + rightTree.height;
        int diameterWithoutRoot = std::max(leftTree.maxdiameter, rightTree.maxdiameter);
        int maxdiameter = std::max(diameterThroughRoot, diameterWithoutRoot);
        int currentHeight = 1 + std::max(leftTree.height, rightTree.height);
        return {maxdiameter, currentHeight};
    }
    
};