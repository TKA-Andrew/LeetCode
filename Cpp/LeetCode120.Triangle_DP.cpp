#include <vector>
#include <climits>

class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        int rows = triangle.size();
        
        std::vector<int> dp(rows, 0);
        
        // BASE CASE
        dp[0] = triangle[0][0];
        
        for (int i=1;i<rows;i++) {
            for (int j=i; j>=0; j--) {
                if (j==0) {
                    dp[j] = dp[0] + triangle[i][j];
                } else if (j==i) {
                    dp[j] = dp[j-1] + triangle[i][j];
                } else {
                    dp[j] = std::min(dp[j], dp[j-1]) + triangle[i][j];
                }
            }
        }
        
        int ret = INT_MAX;
        for (int i=0;i<rows;i++) {
            ret = std::min(ret, dp[i]);
        }
        return ret;
    }
};