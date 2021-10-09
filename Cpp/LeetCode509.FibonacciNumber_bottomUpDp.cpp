// using bottom up DP
// this is quite similar to recursive with Memoization (which is a top-down approach)

// visual representation
/*
  let's say n = 5

    dp[0]   dp[1]  dp[2]
              \     /  \
                dp[3] - dp[4]
                    \   /
                    dp[5]
*/

// Time complexity = O(N)
// Space complexity = O(n)

#include <vector>
class Solution {
public:
    int fib(int n) {
        if (n==0) return 0;
        if (n==1) return 1;
        std::vector dp(n+1, 0);
        dp[1] = dp[2] = 1; // base case
        for (int i = 3; i<=n; i++)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
};