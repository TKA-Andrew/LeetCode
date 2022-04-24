// REFERENCE: https://leetcode.com/problems/pacific-atlantic-water-flow/discuss/1969210/Easy-DFS%2BBFS-Explained

#include <vector>

class Solution {
public:
    int m=0;
    int n=0;
    
    void dfs(std::vector<std::vector<int>>& heights, std::vector<std::vector<bool>> &v, int i, int j)
    {
        v[i][j] = true;
        
        if (i<m-1 && v[i+1][j]==false && heights[i+1][j] >= heights[i][j])
        {
            dfs(heights, v, i+1, j);
        }
        if (i>0 && v[i-1][j]==false && heights[i-1][j] >= heights[i][j])
        {
            dfs(heights, v, i-1, j);
        }
        if (j<n-1 && v[i][j+1]==false && heights[i][j+1] >= heights[i][j])
        {
            dfs(heights, v, i, j+1);
        }
        if (j>0 && v[i][j-1]==false && heights[i][j-1] >= heights[i][j])
        {
            dfs(heights, v, i, j-1);
        }
    }
    
    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        std::vector<std::vector<bool>> canP(m, std::vector<bool> (n, false));
        std::vector<std::vector<bool>> canA(m, std::vector<bool> (n, false));
        
        for (int i=0;i<m;i++)
        {
            dfs(heights, canP, i, 0);
            dfs(heights, canA, i, n-1);
        }
        for (int j=0;j<n;j++)
        {
            dfs(heights, canP, 0, j);
            dfs(heights, canA, m-1, j);
        }
        
        std::vector<std::vector<int>> answer;
        for (int i=0;i<m;i++)
        {
            for (int j=0; j<n; j++)
            {
                if (canP[i][j] && canA[i][j])
                {
                    answer.push_back({i,j});
                }
            }
        }
        
        return answer;
    }
};