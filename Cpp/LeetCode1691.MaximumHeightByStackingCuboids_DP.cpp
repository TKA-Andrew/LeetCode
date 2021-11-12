#include <vector>
#include <algorithm>

class Solution {
public:
    int maxHeight(std::vector<std::vector<int>>& cuboids) {
        // sort(rotate) each of the cuboids first
        for (auto& cuboid: cuboids) {
            sort(cuboid.begin(), cuboid.end());
        }
        // sort the array of arrays
        sort(cuboids.begin(), cuboids.end());
        
        int N = cuboids.size();
        std::vector<int> dp(N,0);
        
        int maxHeight=cuboids[0][2];
        for (int i=0;i<N;i++) {
            dp[i] = cuboids[i][2]; // base case
            for (int j=0;j<i;j++) {
                if (canStack(cuboids[i], cuboids[j])) {
                    dp[i] = std::max(dp[i], dp[j] + cuboids[i][2]);
                }
            }
            maxHeight = std::max(maxHeight, dp[i]);
        }
        return maxHeight;
    }
    
    bool canStack(std::vector<int> cubeI, std::vector<int> cubeJ) {
        return (cubeI[0]>=cubeJ[0] && cubeI[1]>=cubeJ[1] && cubeI[2]>=cubeJ[2]);
    }
};