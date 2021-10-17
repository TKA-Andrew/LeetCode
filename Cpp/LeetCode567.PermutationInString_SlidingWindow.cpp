// using Sliding Window with 2 pointers
// Time Complexity: O(N)
// Space Complexity: O(N)

#include <string>
#include <unordered_map>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        int left = 0; // left index of window
        int right = 0; // right index of window
        int matched = 0; // to check how many types characters already fullfilled the target
        std::unordered_map<char, int> need; // to store amount of each character needed
        std::unordered_map<char, int> window; // to store amount of each target character found in window
        for (const auto c:s1) {
            need[c]++;
        }

        // to prevent type mismatch as s.size() is of type "size_t" instead of "int"
        int matchesNeeded = need.size();
        int s1StringSize = s1.size();
        int s2stringSize = s2.size();

        while (right<s2stringSize) {
            char c = s2[right];
            right++;
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    matched++;
                }
            }

            // SIDE NOTES: There are two options when deciding when to shrink the window
            /*
            1) Shrink the window when window size is greater and equal to target string size,
                then, return true when all the characters matched
            2) Shrink the window when we have all the needed characters,
                then return true when the window size is equal to target string size

            Second option is easier to understand and logical as first one doesn't really need a while loop
            */

            // shrink the window when we have all the characters needed in window, 
            // until window size is equal to s1StringSize
            while (matched == matchesNeeded) {
                if (right-left == s1StringSize) {
                    return true;
                }
                char d = s2[left];
                left++;
                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        matched--;
                    }
                    window[d]--;
                }
            }
        }        
        return false;
    }
};