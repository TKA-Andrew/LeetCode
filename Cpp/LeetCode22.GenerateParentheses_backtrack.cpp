#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> res;
    std::vector<std::string> generateParenthesis(int n) {
        std::string track = "";
        backtrack(n,n,track);
        return res;
    }
    
    void backtrack(int left, int right, std::string& track) {
        if (left<0 || right<0) {
            return;
        }
        
        if (left>right) { //if there are more '(' left
            return;
        }
        
        if (left==0 && right==0) {
            res.push_back(track);
            return;
        }
        
        track.push_back('(');
        backtrack(left-1, right,track);
        track.pop_back();
        
        track.push_back(')');
        backtrack(left, right-1, track);
        track.pop_back();
    }
};