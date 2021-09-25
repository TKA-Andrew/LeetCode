// reference: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/discuss/1484716/C%2B%2B-Solution-explained-with-Easy-steps-and-approach
// the solution is slightly monified to implement Struct

#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    int shortestPath(std::vector<std::vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        struct TravelInfo {
            int x{0};
            int y{0};
            int currentLength{0};
            int remainingK {};
        };
        
        std::vector<std::vector<int>> visited(m, std::vector<int>(n, -1));
        std::queue<TravelInfo> q;
        
        q.push(TravelInfo {0,0,0,k});
        
        while(!q.empty()) {
            auto t = q.front();
            q.pop();
            
            if (t.x < 0 || t.x >= m || t.y < 0 || t.y >=n ) {
                continue;
            }
            
            if (t.x == (m-1) && t.y == (n-1)) {
                return t.currentLength;
            }
            
            if (grid[t.x][t.y] == 1) {
                if (t.remainingK > 0) {
                    t.remainingK --;
                } else {
                    continue;
                }
            }
            
            if (visited[t.x][t.y] != -1 && visited[t.x][t.y] >= t.remainingK) {
                continue;
            }
            
            visited[t.x][t.y] = t.remainingK;
            
            q.push(TravelInfo {t.x + 1, t.y , t.currentLength + 1, t.remainingK});
            q.push(TravelInfo {t.x - 1, t.y , t.currentLength + 1, t.remainingK});
            q.push(TravelInfo {t.x , t.y + 1, t.currentLength + 1, t.remainingK});
            q.push(TravelInfo {t.x , t.y - 1, t.currentLength + 1, t.remainingK});

        }
        return -1;
    }
};