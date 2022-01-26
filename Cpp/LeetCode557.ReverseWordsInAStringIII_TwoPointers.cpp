#include <string>

class Solution {
public:
    std::string reverseWords(std::string s) {
        int left = 0;
        int right = 1;
        while (right < s.length()) {
            while (s[right] != ' ' && (right< s.length())) {
                right++;
            } 
            int x=right-1;
            while (left<x) {
                std::swap(s[left], s[x]);
                left++;
                x--;
            }
            left = right+1;
            right++;
        }
        return s;
    }
};