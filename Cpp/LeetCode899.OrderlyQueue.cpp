// credit to： https://www.tutorialspoint.com/orderly-queue-in-cplusplus
#include <iostream>
#include <algorithm>

class Solution {
public:
    std::string orderlyQueue(std::string s, int k) {
        // for k>1 , any permutation is possible
        // hence, we straight away use the sort() function
        if (k>1) {
            sort(s.begin(), s.end());
            return s;
        } 
        
        // only need to handle case when k = 1
        // for k = 1, only rotation of s is possible
        // hence, we need brute force to solve this
        int i = 0;
        std::string ret = s;
        for (i=0; i<s.length(); i++) {
             s = s.substr(1) + s.substr(0, 1);
             if(s < ret) ret = s;
        }
        return ret;
    }
};

// test
int main () {
    Solution test;
    std::cout << "Input String = 'cabaa', k = 3" << '\n';
    std::cout << "Expected answer: aaabc" << '\n'; 
    std::cout << "Returned answer: " << (test.orderlyQueue("cabaa", 3)) << '\n';
    std::cout << "Input String = 'cabaa', k = 1" << '\n';
    std::cout << "Expected answer: aacab" << '\n'; 
    std::cout << "Returned answer: " << (test.orderlyQueue("cabaa", 1)) << '\n';
    return 0;
}