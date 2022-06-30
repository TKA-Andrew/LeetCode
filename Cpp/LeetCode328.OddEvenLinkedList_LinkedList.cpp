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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        fast = head->next;
        ListNode* even = fast;
        ListNode* evenHead = fast;
        while (slow->next != nullptr && fast->next != nullptr)
        {
            slow->next = fast->next;
            slow = slow->next;            
            fast = slow->next;
            even->next = fast;
            if (even != nullptr)
                even=even->next;
        }
        slow->next = evenHead;
        return head;
    }
};