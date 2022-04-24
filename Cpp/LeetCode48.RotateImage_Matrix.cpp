// Time Complexity: O(N^2)
// Space Complexity: O(1)

#include <vector>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        
        // left boundary and right boundary
        int left = 0;
        int right = n-1;
        
        while (left<right)
        {
            // i represents offset
            int i = 0;
            
            while(left+i < right)
            {
                // top boundary and bottom boundary
                int top = left;
                int bottom = right;
                
                int temp = matrix[top][left+i];
                matrix[top][left+i] = matrix[bottom-i][left];
                matrix[bottom-i][left] = matrix[bottom][right-i];
                matrix[bottom][right-i] = matrix[top+i][right];
                matrix[top+i][right] = temp;
                
                i++;
            }
            
            left++;
            right--;
        }
    }
};