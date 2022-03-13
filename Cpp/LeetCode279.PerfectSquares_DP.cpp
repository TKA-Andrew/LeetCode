#include <vector>
#include <climits>

class Solution {
public:
    int numSquares(int n) {
        std::vector dp(n+1, INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        
        for (int i=2; i<=n; i++){
            for (int j=1; j*j<=i; j++) {
                if (i == j*j) {
                    dp[i] = 1;
                } else {
                    dp[i] = std::min(dp[i], dp[i-j*j] + 1);
                }
            }
        }
        
        return dp[n];
    }
};