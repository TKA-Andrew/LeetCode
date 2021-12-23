// O(N) time
// O(N) space

#include <vector>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int N=height.size();
        std::vector<int> l_max(N);
        std::vector<int> r_max(N);
        
        // base case
        l_max[0] = height[0];
        r_max[N-1] = height[N-1];
        
        for (int i=1;i<N;i++) {
            l_max[i] = std::max(height[i], l_max[i-1]);
        }
        for (int j=N-2;j>=0;j--) {
            r_max[j] = std::max(r_max[j+1], height[j]);
        }
        int total=0;
        for (int i=1; i<N-1; i++) {
            total += (std::min(l_max[i], r_max[i]) - height[i]);
        }
        return total;
    }
};