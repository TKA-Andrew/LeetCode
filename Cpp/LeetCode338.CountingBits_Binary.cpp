// Reference: https://leetcode.com/problems/counting-bits/discuss/1808016/C%2B%2B-oror-Vectors-Only-oror-Easy-To-Understand-oror-Full-Explanation

#include <vector>

class Solution {
public:
    std::vector<int> countBits(int n) {
        std::vector<int> ans(n+1, 0);
        for (int i=1; i<=n; i++)
        {
            ans[i] = ans[i/2] + i%2;
        }
        return ans;
    }
};