// using Recursive With Memoization
// visual representation
/*
  let's say n = 5

                    f(5)
                   /    \
                 f(4) - f(3)
                    \   /    \
                     f(2) - f(1)
                        \
                        f(0)

*/
// With memoization, it is no longer a binary tree
// Time complexity = O(N)
// Space complexity = O(n)
#include <vector>
#include <iostream>

class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        std::vector<int> memoize(n+1, -1); // n+1 because of including '0'
        memoize[0] = 0; // base-case
        memoize[1] = 1; // base-case
        return helper(memoize, n);
    }
    
    // &memoize means pass by reference, to avoid copying
    int helper(std::vector<int> &memoize, int n) {
        if (memoize[n] != -1) {
            return memoize[n];
        }
        memoize[n]=helper(memoize, n-1) + helper(memoize, n-2);
        return memoize[n];
    }
    
};