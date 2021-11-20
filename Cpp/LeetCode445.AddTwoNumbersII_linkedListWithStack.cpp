// time complexity: O(max(m,n))
// space complexity: O(max(m,n))

#include <stack>

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
    std::stack<int> s1;
    std::stack<int> s2;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        while (l1 != nullptr) {
            s1.push(l1->val);
            l1=l1->next;
        }
        while (l2 != nullptr) {
            s2.push(l2->val);
            l2=l2->next;
        }
        int carry=0;
        ListNode* afterHead = nullptr;
        while (!s1.empty() || !s2.empty() || carry != 0) {
            int sum = carry;
            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }
            int leftover = sum%10;
            carry = sum/10;
            auto head = new ListNode(leftover);
            head->next = afterHead;
            afterHead = head; // point to next node
        }
        return afterHead;
    }
    
};