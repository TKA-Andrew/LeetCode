#include <map>

class Solution {
public:
    int superEggDrop(int k, int n) {
        std::map<int,std::map<int,int>> memo;
        return dp(k,n,memo);
    }
    
    int dp(int k, int n, std::map<int,std::map<int,int>>& memo) {
        if (k==1) {
            return n;
        }
        
        if (n==0) {
            return 0;
        }
        
        if (memo.count(k)) {
            if (memo[k].count(n)) {
                return memo[k][n];            
            }
        }
        
        int res = INT_MAX;
        for (int i=1; i<=n;i++) {
            res = std::min(res, std::max(dp(k,n-i,memo), dp(k-1,i-1,memo))+1);
        }
        memo[k][n] = res;
        return res;
    }
};