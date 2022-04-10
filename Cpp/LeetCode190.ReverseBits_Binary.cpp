#include <stdint.h>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = n;
        for (int i=0; i<16; i++)
        {
            int a = (ans & (1<<i)) > 0 ? 1:0;
            int b = (ans & (1<<(31-i))) > 0 ? 1:0;
            
            if (a!=b)
            {
                ans = ans^(1<<i);
                ans = ans^(1<<(31-i));
            }
        }
        return ans;
    }
};