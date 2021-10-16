// using Sliding Window with 2 pointers
// Time Complexity: O(N)
// Space Complexity: O(N)

#include <string>
#include <unordered_map>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        int left = 0; // left index of window
        int right = 0; // right index of window
        int start = 0; // first index of substring
        int matched = 0; // to check how many types characters already fullfilled the target
        int len = INT_MAX; // length of window = length of substring
        std::unordered_map<char, int> need; // to store amount of each character needed
        std::unordered_map<char, int> window; // to store amount of each target character found in window
        for (const auto c:t) {
            need[c]++;
        }

        int matchesNeeded = need.size();

        int stringSize = s.size(); // to prevent type mismatch as s.size() is of type "size_t" instead of "int"
        while (right<stringSize) {
            char c = s[right];
            right++;
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    matched++;
                }
            }
            
            // shrink the window when all needed characters are in window
            while (matched == matchesNeeded) {
                if ((right - left)<len) {
                    start = left;
                    len = right - left;
                }
                char d = s[left];
                left++;
                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        matched--;
                    }
                    window[d]--;
                }
            }
        }        
        return len==INT_MAX ? "":s.substr(start,len);
    }
};