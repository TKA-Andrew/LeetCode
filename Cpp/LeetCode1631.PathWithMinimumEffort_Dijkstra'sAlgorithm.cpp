#include <queue>
#include <vector>
#include <climits>
#include <math.h>

typedef std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<std::vector<int>>> MinHeap;

class Solution {
public:
    int minimumEffortPath(std::vector<std::vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        int targetR = row - 1;
        int targetC = col - 1;
        
        std::vector<std::vector<int>> minTravelCost(row, std::vector<int> (col, INT_MAX));
        minTravelCost[0][0] = 0;
        
        int moves[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        
        MinHeap minHeap;
        minHeap.push({0, 0, 0}); // {effort, r, c}
        
        while (!minHeap.empty()) {
            auto topEle = minHeap.top();
            int curEffort = topEle[0];
            int curR = topEle[1];
            int curC = topEle[2];
            minHeap.pop();
            
            if (curR == targetR && curC == targetC) {
                return curEffort;
            }
            
            if (curEffort>minTravelCost[curR][curC]) {
                continue;
            }
            
            for (auto move:moves) {
                int newR = curR + move[0];
                int newC = curC + move[1];
                if (newR < 0 || newR >= row || newC < 0 || newC >= col) {
                    continue;
                } else {
                    int newEffort = abs(heights[newR][newC] - heights[curR][curC]);
                    int minEffort = newEffort;
                    if (curEffort != INT_MAX) {
                        // If previous effort is higher, than minEffort is equal to previous effort
                        minEffort = std::max(newEffort, curEffort);
                    }
                    if (minEffort < minTravelCost[newR][newC]) {
                        minTravelCost[newR][newC] = minEffort;
                        minHeap.push({minEffort, newR, newC});
                    }
                    
                }
            }
        }
        
        return minTravelCost[targetR][targetC];
    }
};