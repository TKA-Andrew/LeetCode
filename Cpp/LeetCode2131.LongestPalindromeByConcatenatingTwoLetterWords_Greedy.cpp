#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    int longestPalindrome(std::vector<std::string>& words) {
        std::unordered_map<std::string, int> h;
        int total = 0;
        bool extra = false;
        for (auto w:words)
        {
            h[w]++;
        }
        for (auto w:words)
        {
            std::string temp = w;
            if (temp[0] == temp[1])
            {
                if (h[temp]>0)
                {
                    total+= (h[temp]/2)*2;
                    if (h[temp] % 2 != 0)
                    {
                        extra = true;
                    }
                    h[temp] = 0; // set it to 0 after considering it
                } 
                continue;
            }
            std::swap(temp[0], temp[1]);
            if (h.find(temp) != h.end() && h[temp]!=0)
            {
                total += (std::min(h[temp], h[w])*2);
                h[temp] = 0;  // set it to 0 after considering it
                h[w] = 0;  // set it to 0 after considering it
            }
        }
        return extra ? total*2 + 2 : total*2;
    }
};