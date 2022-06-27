#include <string>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.size() == 0) return "";
        for (int i = 0; i<strs[0].length(); i++ )
        {
            for (int j=1; j<strs.size(); j++)
            {
                if (i==strs[j].length() || strs[j][i] != strs[0][i])
                {
                    return strs[0].substr(0,i);
                }
            }
        }
        return strs[0];
    }
};