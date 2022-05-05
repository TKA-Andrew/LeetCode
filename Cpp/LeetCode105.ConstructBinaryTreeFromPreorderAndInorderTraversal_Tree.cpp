#include <unordered_map>
#include <vector>

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

    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        std::unordered_map<int, int> inMap;
        for (int i=0;i<inorder.size(); i++)
        {
            inMap[inorder[i]] = i;
        }
        return buildTreeHelper(preorder, inorder, inMap, 0, preorder.size()-1, 0, inorder.size()-1);
    }
    
    TreeNode* buildTreeHelper(std::vector<int>& preorder, std::vector<int>& inorder, std::unordered_map<int, int> &inMap, int preStart, int preEnd, int inStart, int inEnd)
    {
        if (preStart>preEnd || inStart>inEnd)
        {
            return nullptr;
        }
        
        TreeNode *root = new TreeNode(preorder[preStart]);
        int inRoot = inMap[preorder[preStart]];
        int numsLeft = inRoot - inStart;
        
        root->left = buildTreeHelper(preorder, inorder, inMap, preStart+1, preStart+numsLeft, inStart, inRoot-1);
        root->right = buildTreeHelper(preorder, inorder, inMap, preStart+numsLeft+1, preEnd, inRoot+1, inEnd);
        
        return root;
    }

};