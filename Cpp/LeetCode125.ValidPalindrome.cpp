#include <string>

class Solution {
public:
    bool isPalindrome(std::string s) {
        int left =0;
        int right =s.length()- 1;
        while (left<right) {
            if (isalnum(s[left]) && isalnum(s[right])) {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                left++;
                right--;
            }
            if (!isalnum(s[left]))
                left ++;
            
            if (!isalnum(s[right])) 
                right--;
        }
        return true;
    }
};