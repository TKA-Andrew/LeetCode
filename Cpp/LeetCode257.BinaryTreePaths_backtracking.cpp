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
    vector<vector<int>> paths;
    
    void backtrack(TreeNode* node, vector<int> track)
    {
        if (node == nullptr) return;
        
        track.push_back(node->val);
        
        // termination condition
        if (node->left == nullptr && node->right == nullptr)
        {
            paths.push_back(track);
            return;
        }
        
        backtrack(node->left, track);
        backtrack(node->right, track);
    }
    
    vector<string> convertPaths(vector<vector<int>> &paths)
    {
        vector<string> k;
        string s="";
        for(auto path: paths)
        {
            for(int i=0;i<path.size();i++)
            {
                if(i==0);
                else
                    s+="->";
                s+=to_string(path[i]);
            }
            k.push_back(s);
            s="";
        }
        return k;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> track;
        backtrack(root, track);
        return convertPaths(paths);
    }
};