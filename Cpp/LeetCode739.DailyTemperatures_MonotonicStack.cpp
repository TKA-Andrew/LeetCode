// time complexity: O(N)
// space complexity: O(N)

#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        int N = temperatures.size();
        std::vector<int> ans(N);
        int sTopIdx = N-1;
        std::stack<int> s; // this stack will store the idx of the next greater temperature
        for (int i=N-1; i>=0;i--) {
            while (!s.empty() && temperatures[s.top()]<=temperatures[i]) {
                s.pop();
            }
            ans[i] = s.empty() ? 0:(s.top()-i);
            s.push(i);
        }
        return ans;
    }
};