// time complexity: O(4^n) // 4 is because worst case might have 4 possible letters
// space complexity: O(4^n)

#include <vector>
#include <unordered_map>
#include <string>

class Solution {
public:
    std::vector<std::string> res;
    std::unordered_map<char, std::string> DIGIT_LETTERS {
        {'0', "0"},
        {'1', "1"},
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.length()==0) {
            return {};
        }
        std::string track="";
        backtrack(digits, track, 0);
        return res;
    }
    
    void backtrack(std::string& digits, std::string& track, int start) {
        if (track.length()==digits.length()) {
            res.push_back(track);
            return;
        }
        
        for (int i = start; i<digits.length(); i++) {
            for (auto c : DIGIT_LETTERS[digits[i]]) {
                track.push_back(c);
                backtrack(digits, track, i+1);
                track.pop_back();
            }
        }
    }
};