// Time Complexity: O(MN)
// Space Complexity: O(N)

#include <vector>

class Solution {
public:

    int uniquePaths(int m, int n) {
        std::vector<int> dp(n, 1);
        
        // base case: dp[n-1] = 1
        
        for (int i = m-2; i>=0; i--)
        {
            for (int j = n-2; j>=0; j--)
            {
                dp[j] = dp[j] + dp[j+1];
            }
        }
        
        return dp[0];
    }
};