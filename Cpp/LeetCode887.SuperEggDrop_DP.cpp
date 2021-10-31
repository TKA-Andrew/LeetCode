// time complexity: O(KNlogN) // logN is due to binary search, KN is due to types of combination
// space complexity: O(KN)

#include <map>
#include <vector>

class Solution {
public:
    int superEggDrop(int k, int n) {
        std::vector<std::vector<int>> memo(k+1, std::vector(n+1, -1));
        return dp(k,n,memo);
    }
    
    int dp(int k, int n, std::vector<std::vector<int>>& memo) {
        if (k==1) {
            return n;
        }
        
        if (n==0) {
            return 0;
        }
        
        if (memo[k][n]!=-1) {
            return memo[k][n];            
        }
        
        int res = INT_MAX;

        int low = 1;
        int high = n;
        while (low<=high) {
            int mid = (low+high)/2;
            int broken = dp(k-1, mid -1, memo);
            int notBroken = dp(k, n-mid,memo);
            if (broken>notBroken) {
                high = mid -1;
                res = std::min(res, broken+1);
            } else {
                low = mid + 1;
                res = std::min(res,notBroken+1);
            }
        }
        memo[k][n] = res;
        return res;
    }
};