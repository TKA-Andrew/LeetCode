#include <queue>
#include <vector>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int> maxHeap;
        
        for (auto n: nums) {
            maxHeap.push(n);
        }
        
        for (int i=1; i<k; i++) {
            maxHeap.pop();
        }
        
        return maxHeap.top();
    }
};