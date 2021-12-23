// O(N) time
// O(1) space

#include <vector>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int N = height.size();
        int leftMax = height[0];
        int rightMax = height[N-1];
        int left = 0;
        int right = N-1;
        int total = 0;
        
        while (left<right) {
            leftMax = std::max(leftMax, height[left]);
            rightMax = std::max(rightMax, height[right]);
            if (leftMax<rightMax) {
                total += leftMax - height[left];
                left++;
            } else {
                total += rightMax - height[right];
                right--;
            }
        }
        return total;
    }
};