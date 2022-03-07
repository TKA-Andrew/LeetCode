#include <vector>
#include <climits>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int maxProfit = 0;
        int minimum = INT_MAX;
        for (auto price:prices) {
            if (price<minimum) {
                minimum = price;
            }
            int margin = price - minimum;
            if (margin>maxProfit) {
                maxProfit = margin;
            }
        }
        return maxProfit;
    }
};