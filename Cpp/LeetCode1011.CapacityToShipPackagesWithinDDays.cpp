// O(nlogn) time // log n due to binary search
// O(1) space

#include <vector>

class Solution {
public:
    int shipWithinDays(std::vector<int>& weights, int days) {
        int maxW=0;
        int sum=0;
        for (const auto weight: weights) {
            maxW = std::max(weight,maxW);
            sum += weight;
        }

        int left = maxW;
        int right = sum;
        
        while (left<right) {
            int mid = left + (right-left)/2;
            if (canFinish(weights, days, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    
    bool canFinish(std::vector<int>& weights, int days, int maxCap) {
        int wIdx = 0;
        int wSize = weights.size();
        for (int i=0;i<days;i++) {
            int cap = maxCap;
            while ((cap -= weights[wIdx])>=0) {
                wIdx++;
                if (wIdx == weights.size()) {
                    return true;
                }
            }
        }
        return false;
    }
};