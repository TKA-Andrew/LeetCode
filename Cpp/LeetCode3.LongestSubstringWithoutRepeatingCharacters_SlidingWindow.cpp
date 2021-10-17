// using Sliding Window with 2 pointers
// Time Complexity: O(N)
// Space Complexity: O(N)

#include <string>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int left = 0; // left index of window
        int right = 0; // right index of window
        int matched = 0; // to check how many types characters already fullfilled the target
        std::unordered_map<char, int> window; // to store amount of each target character found in window
        int longest = 0;
        int sStringSize = s.size();
        
        while (right < sStringSize) {
            char c = s[right];
            right++;
            window[c]++;
            
            // shrink when the window contained the character more than once
            while (window[c]>1) {
                char d = s[left];
                left++;
                window[d]--;
            }
            
            if (right - left > longest) {
                longest = right - left ;
            }
            
        }
        return longest;

    }
};