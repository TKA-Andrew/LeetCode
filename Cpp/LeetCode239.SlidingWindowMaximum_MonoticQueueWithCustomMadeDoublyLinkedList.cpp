// time complexity: O(N)
// space complexity: O(k)

#include <vector>

class Node{
    public:
        int val; 
        Node* prev;
        Node* next;
        Node(int val){
            this->val = val;
    }
};

// Modified from LeetCode 146
class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;
        int size;
    
    public:
        DoublyLinkedList() {
            this->head = new Node(0);
            this->tail = new Node(0);
            head->next = tail;
            tail->prev = head;
            this->size = 0;
        }

    public: void addLast(Node* x) {
        x->prev = tail->prev;
        x->next = tail;
        tail->prev->next = x;
        tail->prev = x;
        size++;
    }
    
    public: void remove(Node* x) {
        x->prev->next = x->next;
        x->next->prev = x->prev;
        size--;
    }
    
    public: bool isEmpty() {
        return head->next == tail;
    }
    
    public: int getFirstValue() {
        return head->next->val;
    }
    
    public: int getLastValue() {
        return tail->prev->val;
    }

    public: void removeFirst() {
        if (head->next != tail) {
            Node* first = head->next;
            remove(first);
        }
    }
    
    public: void removeLast() {
        if (tail->prev != head) {
            Node* last = tail->prev;
            remove(last);
        }
    }
    
    public: int getSize() {
        return size;
    }
    
};

class MonotonicQueue {
public: 
    
    // we need to get last element and first element
    // queue can only get first element
    // stack can only get last element
    // so we need doubly linked list (actually can use C++ List)
    DoublyLinkedList* q = new DoublyLinkedList();
    void push(int num) {
        // WHY q->getLastValue() < num instead of q->getLastValue() <= num ?
        // SO THAT THERE CAN BE MULTIPLE SAME NUMBER IN THE WINDOW FOR LATER USE
        // let's say we have a nums = [1,3,7,6,7,6,6], N=3
        // if current window is [7,6] and the we push(7)
        // if we use <= , the first 7 will be removed, and left [7] in the window
        // then the window.pop(7) will cause empty window
        // the answer will become [7,7,7,6,6], which is WRONG
        while (!q->isEmpty() && q->getLastValue() <= num) {
            q->removeLast();
        }
        Node* numNode = new Node(num);
        q->addLast(numNode);
    }
    
    void pop(int num) {
        if (num == q->getFirstValue()) {
            q->removeFirst();
        }
    }
    
    int max() {
        return q->getFirstValue();
    }
};

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        int N = nums.size();
        MonotonicQueue window = MonotonicQueue();
        std::vector<int> ans(N-k+1); // for example, if N=5, k=3, there will be only 2 sliding windows
        
        for (int i=0;i<N;i++) {
            if (i<k-1) {
                window.push(nums[i]);
            } else {
                window.push(nums[i]);
                ans[i-k+1] = window.max();
                window.pop(nums[i-k+1]);
            }
        }
        return ans;
    }
};