// O(nlogn) time // log n due to binary search
// O(1) space

#include <vector>

class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        int right = getMax(piles);
        int left = 1; // minimum speed
        
        // make use of binary search
        while (left<right) {
            int mid = left + (right-left)/2;
            if (canFinish(piles, mid, h)) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left; // doesn't matter return left or right, at here left=right
    }
    
    bool canFinish(std::vector<int>& piles, int speed, int h) {
        int timeUsed = 0;
        for (const auto pile:piles) {
            timeUsed += (pile/speed + ((pile%speed==0)?0:1));
        }
        return timeUsed<=h;
    }
    
    int getMax(std::vector<int>& piles) {
        int max=0;
        for (const auto pile: piles) {
            max = std::max(pile,max);
        }
        return max;
    }
};