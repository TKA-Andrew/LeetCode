#include <unordered_set>

class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set <int> inSet;
        while(true)
        {
            if (n==1) {
                return true;
            }
            int sum = 0;
            int mod = 0;
            while(n>0)
            {
                mod = n%10;
                n = n/10;
                sum += mod*mod;
            }
            if (inSet.find(sum) != inSet.end())
            {
                return false;
            }
            inSet.insert(sum);
            n = sum;
        }
        return false;
    }
};