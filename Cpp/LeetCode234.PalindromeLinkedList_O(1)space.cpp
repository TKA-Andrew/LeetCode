// time complexity: O(N)
// space complexity: O(1) // previous solution is O(N) space because of recursive function

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
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=nullptr && fast->next!=nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast != nullptr) {
            // if the length is odd number
            slow = slow->next;
        }
        // slow supposedly now at middle or middle+1
        
        ListNode* left = head;
        ListNode* right = reverse(slow);
        
        while (right != nullptr) {
            if (left->val != right->val) {
                return false;
            }
            left = left->next;
            right = right->next;
        }
        return true;
    }
    
    ListNode* reverse(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = nullptr;
        
        while (cur != nullptr) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};