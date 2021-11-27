// time complexity: O(!N*N)
// space complexity: O(!N*N)

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> res;
    void backtrack(int start, std::vector<int>& array, std::vector<std::vector<int>>& perms) {
        if (start == array.size() -1) {
            perms.push_back(array); // O(N) operation
            return;
        }
        for (int i=start; i<array.size(); i++) {
            std::swap(array[i], array[start]); // O(1) operation
            backtrack(start+1, array, perms);
            std::swap(array[i], array[start]); // O(1) operation
        }
    }
    std::vector<std::vector<int>> permute(std::vector<int>& nums) 
    {
        std::vector<std::vector<int>> perms;
        backtrack(0,nums,perms); // O(!N) times
        return perms;
    }
};