// time complexity: O(N)
// space complexity: O(N)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* left;
    bool isPalindrome(ListNode* head) {
        left = head;
        return traverse(head);
    }
    
    bool traverse(ListNode* right) {
        if (right == nullptr) return true;
        bool res = traverse(right->next);
        
        res = res && (left->val == right->val);
        left = left->next;
        return res;
    }
};