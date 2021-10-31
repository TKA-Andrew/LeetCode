// time complexity: O(KN)
// space complexity: O(N)

#include <vector>

class Solution {
public:

    int superEggDrop(int K, int N) {
        std::vector<int> dp(N+1, 0);
        int ans = 0;
        for (int k=1; k<=K; k++) {
            int pre = 0; // equivalent to dp[k][0] = 0
            for (int m=1; dp[m-1]<N; m++) {
                int temp = dp[m]; // to store the value before being updated
                dp[m] = dp[m-1] + pre + 1;
                pre = temp; // equivalent to dp[k-1][m-1] in next loop
                ans = m; // to get latest m
            }
        }
        return ans;
    }
    
};