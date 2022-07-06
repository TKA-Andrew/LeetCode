#include <cmath>

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int dfs(Node* node, int maxdepth)
    {
        if (node->children.size() == 0) return maxdepth;
        ++maxdepth;
        int currentDepth = maxdepth;
        for (auto child: node->children)
        {
            maxdepth = std::max(maxdepth, dfs(child, currentDepth));
        }  
        return maxdepth;
    }
    
    int maxDepth(Node* root) {
        if (root == nullptr) return 0;
        return dfs(root, 1);
    }
};