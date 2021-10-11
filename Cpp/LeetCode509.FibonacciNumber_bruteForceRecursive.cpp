// using Brute Force Recursive
// visual representation
/*
    let's say n = 5

                     f(5)
                   /      \
                f(4)      f(3)
               ....        ...
               /  \        / \
            f(1)  f(2)  f(1)  f(2)

*/
// Time complexity = O(2^n), since it is a binary tree
// Space complexity = O(n)
class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        return fib(n-1) + fib(n-2);
    }
};