// time complexity: O(KN)
// space complexity: O(KN)

#include <vector>

class Solution {
public:
    int superEggDrop(int K, int N) {
        
        std::vector<std::vector<int>> dp(K+1, std::vector(N+1, 0));
        
        // definition of dp:
        // dp[k][m] means given k eggs and m trials, maximum can test how many floors
        
        // base case:
        // dp[0][...] = 0
        // dp[...][0] = 0
        
        // state transition:
        // dp[k][m] = dp[k][m-1] + dp[k-1][m-1] + 1
        
        int m = 0;
        
        while(dp[K][m]<N) {
            m++;
            for (int k=1; k<=K; k++) {
                dp[k][m] = dp[k][m-1] + dp[k-1][m-1] + 1;
            }
        }
        
        return m;
    }
    
};