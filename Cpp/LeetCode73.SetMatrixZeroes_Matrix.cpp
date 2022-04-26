#include <vector>

class Solution {
public:
    int m = 0;
    int n = 0;
    
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        std::vector<std::vector<bool>> bombed(m, std::vector<bool> (n, false));
        
        for (int i=0; i<m; i++)
        {
            for (int j=0;j<n;j++)
            {
                if (bombed[i][j])
                {
                    continue;
                }
                if (matrix[i][j] == 0)
                {
                    bomb(matrix, bombed, i, j);
                }
            }
        }
    }
    
    void bomb(std::vector<std::vector<int>>& matrix, std::vector<std::vector<bool>>& bombed, int row, int col)
    {
        for (int j=0; j<n; j++)
        {
            if (bombed[row][j])
            {
                continue;
            }
            bombed[row][j] = true;
            if (matrix[row][j] == 0)
            {
                bomb(matrix, bombed, row, j);
            }
            matrix[row][j] = 0;
        }
        
        for (int i=0; i<m; i++)
        {
            if (bombed[i][col])
            {
                continue;
            }
            bombed[i][col] = true;
            if (matrix[i][col] == 0)
            {
                bomb(matrix, bombed, i, col);
            }
            matrix[i][col] = 0;
        }
    }
};