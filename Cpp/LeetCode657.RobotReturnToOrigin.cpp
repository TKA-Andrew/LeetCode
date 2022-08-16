#include <string>

class Solution {
public:
    bool judgeCircle(std::string moves) {
        int x = 0;
        int y = 0;
        for(const auto m:moves)
        {
            if (m=='L')
            {
                y--;
            } else if (m=='R')
            {
                y++;
            } else if (m=='U')
            {
                x++;
            } else
            {
                x--;
            }
        }
        return x==0 && y==0;
    }
};