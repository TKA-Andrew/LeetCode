// time complexity: O(N)
// space complexity: O(N)

#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> nextGreaterElements(std::vector<int>& nums) {
        int N = nums.size();
        std::vector<int> ans(N);
        std::stack<int> s;
        for (int i=2*N-1; i>=0; i--) { // double the length of the vector
            while (!s.empty() && s.top()<=nums[i%N]) { // use i%N to refer to the correct index
                s.pop();
            }
            ans[i%N]= s.empty() ? -1:s.top();
            s.push(nums[i%N]);
        }
        return ans;
    }
};