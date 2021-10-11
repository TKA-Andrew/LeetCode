class Solution {
public:
    int tribonacci(int n) {
        if (n==0) {
            return 0;
        }
        if (n==1 || n ==2) {
            return 1;
        }
        long long Fn0 {0};
        long long Fn1 {1};
        long long Fn2 {1};
        long long Fn {0};
        
        for (int i = 3; i<=n; i++) {
            Fn = Fn0 + Fn1 + Fn2;
            Fn0 = Fn1;
            Fn1 = Fn2;
            Fn2 = Fn;
        }
        return Fn;
    
    }
};