#include <vector>

class Solution {

private:
    int row;
    int col;
    int sourceColor;
    
public:
    std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int newColor) {
        row = image.size();
        col = image[0].size();
        sourceColor = image[sr][sc];
        if (image[sr][sc] == newColor) {
            return image;
        }
        dfs(image, sr, sc, newColor);
        return image;
    }
    
    void dfs(std::vector<std::vector<int>>& image, int r, int c, int newValue) {
        if (r<0 || c<0 || r>=row || c>=col || image[r][c] != sourceColor) {
            return;
        }
        image[r][c] = newValue;
        dfs(image, r-1, c, newValue);
        dfs(image, r+1, c, newValue);
        dfs(image, r, c-1, newValue);
        dfs(image, r, c+1, newValue);
        
    }
};