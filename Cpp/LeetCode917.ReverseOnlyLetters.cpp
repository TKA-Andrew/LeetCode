// Reference of solution 2 and 3: https://leetcode.com/problems/reverse-only-letters/discuss/1462718/C%2B%2B-2-solutions%3A-Two-Pointer-Stack-of-letters-Space-O(1)-Clean-and-Concise
#include <iostream>
#include <vector>
#include <stack>

class Solution {
public:
    // solution 1 : using vector
    std::string reverseOnlyLetters(std::string s) {
        int n = s.length();
        std::vector <int> g1;
        for (int i=0; i<n; i++) {
            if (std::isalpha(s[i])) {
                g1.push_back(s[i]);
            }
        }
        int idx = 0;
        for (int i=n-1; i>=0; i--) {
            if (std::isalpha(s[i])) {
                s[i] = g1.at(idx);
                idx++;
            }
        }
        return s;
    }
    
    // solution 2: using stack to do LIFO
    std::string reverseOnlyLetters2(std::string s) {
        std::stack <char> st;
        for (int i=0; i<s.length(); i++) {
            if (std::isalpha(s[i])) {
                st.push(s[i]);
            }
        }
        for (int i=0; i<s.length();i++) {
            if (std::isalpha(s[i])) {
                s[i] = st.top();
                st.pop();
            }
        }
        return s;
    }
    
    // solution 3: using 2 pointers
    std::string reverseOnlyLetters3(std::string s) {
        int l = 0;
        int r = s.length() - 1;
        // find the left most and right most alpha character
        // then use std::swap()
        while (l<r) {
            while (!std::isalpha(s[l]) && l<r) {
                l++;
            }
            while (!std::isalpha(s[r]) && l<r) {
                r--;
            }
            std::swap(s[l++],s[r--]);
        }
        return s;
    }
};