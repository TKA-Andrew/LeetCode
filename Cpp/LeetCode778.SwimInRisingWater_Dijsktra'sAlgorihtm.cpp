#include <queue>
#include <vector>
#include <climits>

typedef std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<std::vector<int>>> MinHeap;

class Solution {
public:
    int swimInWater(std::vector<std::vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int targetR = row - 1;
        int targetC = col - 1;
        
        std::vector<std::vector<bool>> visited(row, std::vector<bool> (col, false));
        int moves[4][4] = {{-1,0},{1,0},{0,-1},{0,1}};
        
        MinHeap minHeap;
        minHeap.push({grid[0][0], 0, 0}); // {timeNeeded, r, c}
        
        while (!minHeap.empty()) {
            auto topEle = minHeap.top();
            int curTimeNeeded = topEle[0];
            int curR = topEle[1];
            int curC = topEle[2];
            minHeap.pop();
            
            if (curR == targetR && curC == targetC) {
                return curTimeNeeded;
            }
            
            if (visited[curR][curC]) continue;
            visited[curR][curC] = true;
            
            for (auto move:moves) {
                int newR = curR + move[0];
                int newC = curC + move[1];
                if (newR < 0 || newR >= row || newC < 0 || newC >= col) {
                    continue;
                } else {
                    if (!visited[newR][newC]) {
                        int newTimeNeeded = std::max(grid[newR][newC], curTimeNeeded);
                        minHeap.push({newTimeNeeded, newR, newC});
                    }
                }
            }
        }
        return 0;
    }
};