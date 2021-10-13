// using Fast Slow Pointers

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

#include <stddef.h> // for NULL

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        // if the linked list only has one node
        if (fast->next == NULL) {
            return NULL;
        }
        
        while (n > 0 && fast->next != NULL) {
            fast = fast->next;
            n--;
        }
        
        // since the constraints have defined that 1 <= n <= sz
        // means if there are remaining n, the remaiining n must be 1.
        // And it menas the initial n = sz
        // When n=sz, it means need to remove first node in the linked list
        if (n>0) {
            slow = slow->next;
            return slow;
        }
        
        // fast is now n nodes ahead of slow
        // so when fast->next = null, it means fast is at the last node
        // and slow is at (n-1)th node from end of the linked list 
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // slow is at (n-1)th node, 
        // so to remove nth node we set the next node equal to next next node
        slow->next = slow->next->next;
        return head;
    }
};