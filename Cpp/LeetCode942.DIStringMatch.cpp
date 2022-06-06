#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> diStringMatch(std::string s) {
        int n = s.length();
        int iNum = 0;
        int dNum = n;
        std::vector<int> output(n+1, 0);
        for (int i=0; i<n; i++)
        {
            if (s[i] == 'I')
            {
                output[i] = iNum;
                iNum++;
            } else {
                output[i] = dNum;
                dNum--;
            }
        }
        
        if (s[n-1] == 'D')
        {
            output[n] = dNum;
        } else {
            output[n] = iNum;
        }
        return output;
    }
};