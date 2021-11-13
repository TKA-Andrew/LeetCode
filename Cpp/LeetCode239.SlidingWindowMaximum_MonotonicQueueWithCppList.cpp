#include <vector>
#include <list>

class MonotonicQueue {
public: 
    
    // we need to get last element and first element
    // queue can only get first element
    // stack can only get last element
    // so we need C++ list
    std::list<int> l;
    void push(int num) {
        // WHY l.back() < num instead of l.back() <= num ?
        // SO THAT THERE CAN BE MULTIPLE SAME NUMBER IN THE WINDOW FOR LATER USE
        // let's say we have a nums = [1,3,7,6,7,6,6], N=3
        // if current window is [7,6] and the we push(7)
        // if we use <= , the first 7 will be removed, and left [7] in the window
        // then the window.pop(7) will cause empty window
        // the answer will become [7,7,7,6,6], which is WRONG
        while (!l.empty() && l.back() < num) {
            l.pop_back();
        }
        l.push_back(num);
    }
    
    void pop(int num) {
        if (num == l.front()) {
            l.pop_front();
        }
    }
    
    int max() {
        return l.front();
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