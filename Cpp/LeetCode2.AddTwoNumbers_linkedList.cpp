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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto l1copy = l1;
        auto l2copy = l2;
        int carry=0;
        auto ans = new ListNode(0);
        auto currentNode = ans;
        while (l1copy != nullptr || l2copy != nullptr || carry != 0) {
            int value1 = l1copy == nullptr ? 0 : l1copy->val;
            int value2 = l2copy == nullptr ? 0 : l2copy->val;
            int sum = value1 + value2 + carry;
            int leftover = sum%10;
            carry = sum/10;
            auto newNode = new ListNode(leftover);
            currentNode->next = newNode;
            currentNode = newNode; // point to next node
            
            l1copy = l1copy == nullptr ? nullptr:l1copy->next;
            l2copy = l2copy == nullptr ? nullptr:l2copy->next;
            
        }
        return ans->next;
    }
};