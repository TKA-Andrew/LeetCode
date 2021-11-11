// refer to this link for the appropraite answer: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/discuss/1568365/C%2B%2B-oror-level-order-oror-Self-explanatory-soln

#include <queue>
#include <string>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        std::string s = "";
        if (root == nullptr) {
            return s;
        }
        serializeHelper(root, s);
        return s;
    }
    
    void serializeHelper(TreeNode* root, std::string& s) {
        if (root == nullptr) {
            s = s + "#,";
            return;
        }
        s = s + std::to_string(root->val) + ",";
        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        int stringSize = data.size();
        if(stringSize==0)
            return nullptr;
        std::queue<std::string> q;
        stringstream str(data);
        std::string val;
        while (true) {
            getline(str,val,',');
            if (val == "") {
                break;
            }
            q.push(val);
        }
        return deserializeHelper(q);
    }
    
    TreeNode* deserializeHelper(std::queue<std::string>& q) {
        if (q.size()==0){
            return nullptr;
        }
        std::string val = q.front();
        q.pop();
        
        if (val == "#") {
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserializeHelper(q);
        root->right = deserializeHelper(q);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));