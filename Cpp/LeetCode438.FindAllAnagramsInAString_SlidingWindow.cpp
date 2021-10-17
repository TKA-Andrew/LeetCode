// using Sliding Window with 2 pointers
// Time Complexity: O(N)
// Space Complexity: O(N)


#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        std::vector<int> res;
        int left = 0; // left index of window
        int right = 0; // right index of window
        int matched = 0; // to check how many types characters already fullfilled the target
        int len = INT_MAX; // length of window = length of substring
        std::unordered_map<char, int> need; // to store amount of each character needed
        std::unordered_map<char, int> window; // to store amount of each target character found in window
        for (const auto c:p) {
            need[c]++;
        }

        int matchesNeeded = need.size();
        int sStringSize = s.size();
        int pStringSize = p.size();
        
        while (right < sStringSize) {
            char c = s[right];
            right++;
            
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    matched++;
                }
            }
            
            while (matched == matchesNeeded) {
                // if window length is equal to size of string p
                if (right - left == pStringSize) {
                    res.push_back(left);
                }
                
                char d = s[left];
                left++;
                
                if (need.count(d)) {
                    if(window[d] == need[d]) {
                        matched--;
                    }
                    window[d]--;
                }
            }
        }
        return res;
        
    }
};