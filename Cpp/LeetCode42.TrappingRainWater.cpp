// time complexity: O(N)
// space complexity: O(N)

#include <vector>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int N = height.size();
        std::vector<int> arrayH(N, 0);
        if (N==0) return 0;
        // left max
        int maxH = 0;
        for (int i=1; i<N; i++) {
            maxH = std::max(maxH, height[i-1]);
            arrayH[i] = maxH;
            // Definition of arrayH[i] at here:
            // amount of water can be trapped at index j, without considering right boundary
        }
        arrayH[N-1] = 0;
        maxH = 0;
        for (int j=N-2;j>=0;j--) {
            maxH = std::max(maxH, height[j+1]);
            arrayH[j] = std::min(arrayH[j],maxH); 
            // Definition of arrayH[i] at here:
            // amount of water can be trapped at index j, after considering right boundary
            
            if (arrayH[j]>height[j]) {
                arrayH[j] -= height[j];
            } else {
                arrayH[j] = 0; // if pillar's height is greater and equal, no water can be trapped
            }
        }
        int totalArea = 0;
        for (int i=0;i<N;i++) {
            totalArea += arrayH[i];
        }
      return totalArea;
    }
};