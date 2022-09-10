#include <vector>

class Solution
{
public:
    // Solution using Boyer–Moore Majority Vote Algorithm
    int majorityElement(std::vector<int> &nums)
    {
        int m = 0;
        int i = 0;
        for (int num : nums)
        {
            if (i == 0)
            {
                m = num;
                i = 1;
            }
            else
            {
                if (m == num)
                {
                    ++i;
                }
                else
                {
                    --i;
                }
            }
        }
        return m;
    }
};