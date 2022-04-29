// REFERENCE: https://www.youtube.com/watch?v=gqXU1UyA8pk

#include <unordered_map>
#include <string>

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        std::unordered_map<char, int> countmap;
        int l = 0;
        int r = 0;
        int maxF = 0;
        int ans = 0;
        while (r<s.length())
        {
            if (countmap[s[r] <= 0])
            {
                countmap[s[r]] = 1;
            } else {
                countmap[s[r]]++;
            }
            
            maxF = std::max(maxF, countmap[s[r]]);
            
            while ((r-l+1) - maxF > k)
            {
                countmap[s[l]]--;
                l++;
            }
            ans = std::max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};