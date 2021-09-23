#include <iostream>

class Solution {
public:
    std::string breakPalindrome(std::string palindrome) {
        const int length = palindrome.size();
        if (length == 1) {
            return "";
        }
        for (int i=0; i<(length/2); i++) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        
        palindrome[length - 1] = 'b';
        return palindrome;
    }
};