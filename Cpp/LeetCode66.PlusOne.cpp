#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int N = digits.size();
        bool add = true;
        if (digits[N-1] < 9)
        {
            digits[N-1]++;
        } else {
            for (int i=digits.size()-1; i>=0; i--)
            {
                digits[i]++;
                if (digits[i] == 10)
                {
                    digits[i] = 0;
                    if (i == 0) {
                        digits.insert(digits.begin(), 1);
                    }
                } else {
                    break;
                }
            }
        }
        return digits;
    }
};