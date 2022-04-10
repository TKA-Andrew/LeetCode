// Time Complexity: O(N)
// Space Complexity: O(1)

#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int N = height.size();
        int left = 0;
        int right = N-1;
        int maxArea = 0;
        
        while (left < right)
        {
            int minH = std::min(height[left], height[right]);
            int area = minH*(right-left);
            maxArea = std::max(maxArea, area);
            
            if (height[left] < height[right])
            {
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }
};