// since f(n) = f(n-1) + f(n-2), we only need to remember the latest two number, this reduced the space complexity
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int fib(int n) {
        if (n==0) return 0;
        if (n==1 || n==2) return 1;
        int a {1}; // n = 1
        int b {1}; // n = 2
        int c {2}; // n = 3
        for (int i = 3; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};