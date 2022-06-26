#include <vector>

class Solution {
public:
    std::vector<int> findBall(std::vector<std::vector<int>>& grid) {
        size_t n = grid[0].size();
        size_t m = grid.size();
        std::vector<int> ans(n, -1);
        for (int ball=0; ball<n; ball++)
        {
            int row = 0;
            int column = ball;
            while (row<m)
            {
                if (grid[row][column] == 1)
                {
                    if (column == n-1) {
                        row++;
                        break; // stucks against right wall
                    } else if (grid[row][column+1] == -1) { // check right
                        row++;
                        break; // reached V
                    } else if (row == m-1) { // reached last row
                        ans[ball] = column+1;
                        row++;
                        break;
                    } else {
                        column++;
                    }
                }
                else {
                    if (column == 0) {
                        row++;
                        break; // stucks against left wall
                    } else if (grid[row][column-1] == 1) { // check left
                        row++;
                        break; // reached V
                    } else if (row == m-1) { // reached last row
                        ans[ball] = column-1;
                        row++;
                        break;
                    } else {
                        column--;
                    }
                }
                row++;
            }
        }
        return ans;
    }
};