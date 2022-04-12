#include <string>
#include <vector>

class Solution {
public:
    int numDecodings(std::string s) {
        int N = s.length();
        std::vector<int> dp(N, 0);
        
        if (s[0] == '0')
        {
            return 0;
        }
        
        if (N == 1) {
            return 1;
        }
        
        // base case
        dp[0] = 1;
        if (s[1] == '0')
        {
             if ((s[0]-'0')>2)
            {
                return 0;
            }
            dp[1] = dp[0];
        } else if (N>=2 && s[2] == '0') {
            dp[1] = dp[0];
        } else if (s[0]=='1' || (s[0]=='2' && (s[1]-'0') <=6)) {
            dp[1] = dp[0] + 1;
        } else {
            dp[1] = dp[0];
        }
        
        for (int i=2; i<N; i++)
        {
            if (s[i] == '0')
            {
                if (s[i-1]=='0') // to handle case like: 100
                {
                    return 0;
                }
                if ((s[i-1]-'0')>2) // to handle case like: 140
                {
                    return 0;
                }
                dp[i] = dp[i-1];
            } else if (i<=N-2 && s[i+1] == '0') // to handle case like: 2101
            { 
                dp[i] = dp[i-1];
            }  
            else if (s[i-1]=='1' || (s[i-1]=='2' && (s[i]-'0') <=6)) {
                dp[i] = dp[i-2] + dp[i-1];
            } else {
                dp[i] = dp[i-1];
            }
        }
        
        return dp[N-1];
    }
};