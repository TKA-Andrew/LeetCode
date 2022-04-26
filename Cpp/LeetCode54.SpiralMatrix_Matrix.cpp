#include <vector>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0;
        int bottom = m;
        int left = 0;
        int right = n;
        std::vector<int> ans;
        
        // left right boundary: [)
        // top bottom boundary: [)
        
        while (left<right && top<bottom)
        {
            for (int j=left; j<right;j++)
            {
                ans.push_back(matrix[top][j]);
            }
            
            for (int i=top+1; i<bottom; i++)
            {
                ans.push_back(matrix[i][right-1]);
            }

            if (bottom-1 != top)
            {
                for (int j=right-2;j>=left;j--)
                {
                    ans.push_back(matrix[bottom-1][j]);
                }        
            }
            
            if (right-1 != left)
            {
                for (int i=bottom-2; i>top; i--)
                {
                    ans.push_back(matrix[i][left]);
                }
            }
            
            left++;
            right--;
            top++;
            bottom--;  
        }
        
        return ans;
    }
};