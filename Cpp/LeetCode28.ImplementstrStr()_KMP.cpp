// Time complexity: O(M+N)
// Space complexity: O(M)

#include <vector>
#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        if (needle == "") return 0;
        std::vector<int> pattern = buildPattern(needle);
        return knuthMorrisPrattAlgorithm(haystack, needle, pattern);
    }
    
    int knuthMorrisPrattAlgorithm(const std::string &str, const std::string &substr, const std::vector<int> &pattern) {
        int i = 0;
        int j = 0;
        while (i + substr.size() -j <= str.size()) {
            if (str[i] == substr[j]) {
                if (j == substr.size()-1) {
                    return i-substr.size() + 1;
                }
                i++;
                j++;
            } else if (j > 0) {
                j = pattern[j-1] + 1;
            } else {
                i++;
            }
        }
        return -1;
    }
    
    std::vector<int> buildPattern(const std::string &substr) {
        std::vector<int> pattern(substr.size(), -1);
        int j=0;
        int i=1;
        while(i<substr.size()) {
            if (substr[i] == substr[j]) {
                pattern[i] = j;
                i++;
                j++;
            } else if(j>0) {
                j = pattern[j-1]+1;
            } else {
                i++;
            }
        }
        return pattern;
    }
};