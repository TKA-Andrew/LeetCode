// O(N^2) time
// O(N) space

#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        std::string res;
        for (int i=0;i<s.size();i++) {
            std::string s1 = palindrome(s, i, i);
            std::string s2 = palindrome(s, i, i+1);
            res = res.size() > s1.size() ? res:s1;
            res = res.size() > s2.size() ? res:s2;
        }
        return res;
    }
    
    std::string palindrome(std::string& s, int l, int r) {
        while (l>=0 && r<s.size() && s[l]==s[r]) {
            l--;
            r++;
        }
        l++; // correction for last while loop
        r--; // correction for last while loop
        return s.substr(l,r-l+1);
    }
};