/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

#include <unordered_map>
#include <vector>

class Solution {
public:
    
    Node* dfs(Node *ori, unordered_map <Node*, Node*> &mp)
    {
        std::vector<Node *> neighbours;
        Node *clone = new Node(ori->val);
        mp[ori] = clone;
        for (auto n : ori->neighbors)
        {
            if (mp.find(n) != mp.end())
            {
                neighbours.push_back(mp[n]);
            }
            else
            {
                neighbours.push_back(dfs(n, mp));
            }
        }
        clone->neighbors = neighbours;
        return clone;
    }
    
    Node* cloneGraph(Node* node) {
        unordered_map <Node*, Node*> mp; // to store mapping of original Node to cloned Node
        
        if (node == nullptr)
        {
            return nullptr;
        }
        
        if (node->neighbors.size() == 0)
        {
            Node *clone = new Node(node->val);
            return clone;
        }
        
        return dfs(node, mp);
    }
};