#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> res;
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<int> track;
        backtrack(1, n, k, track);
        return res;
    }
    
    void backtrack(int start, int n, int k, std::vector<int>& track) {
        if (track.size() == k) {
            res.push_back(track);
            return;
        }
        
        for (int i=start; i<=n;i++) {
            track.push_back(i);
            backtrack(i+1, n,k,track);
            track.pop_back();
        }
    }
};