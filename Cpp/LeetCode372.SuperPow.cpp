#include <vector>

// CONCEPTS
/*
    1) To handle vector<int> b:
    
        a^345 = a^5 * (a^34)^10
        a^345 = a^5 * (a^4 * (a^3)^10)^10
        a^345 = a^5 * (a^4 * (a^3 * 1^10)^10)^10

        From this we know
            part1 * part2 = mypow(a, last) * mypow(superPow(a, b), 10)

    2) To handle integer overflow problem, we need to understand the following:
        (a*b)%base = (a%base)(b%base)%base

        This is why there are "%base" added in the code

    3) For better exponential calculation, we need to understand:

                { a * a^(k-1) // for odd k
        a^k =   |
                { (a^(k/2))^2 // for even k

*/

class Solution {
private:
    int base = 1337;
public:
    int mypow (int a, int k) {
        if (k==0) return 1;
        a %= base;
        if (k%2 == 1) // odd
        {
            return (a*mypow(a,k-1))%base;
        } else {
            int sub = mypow(a, k/2);
            return (sub*sub)%base;
        }
    }
    
    int superPow(int a, std::vector<int>& b) {
        if (b.empty()) {
            return 1;
        }
        
        int last = b.back();
        b.pop_back();
        int part1 = mypow(a, last)%base;
        int part2 = mypow(superPow(a, b), 10)%base;
        return (part1*part2)%base;
    }
};