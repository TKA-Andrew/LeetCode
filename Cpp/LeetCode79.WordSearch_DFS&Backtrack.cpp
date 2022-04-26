#include<vector>
#include<string>

class Solution {
public:
    int m = 0;
    int n = 0;
    
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        m = board.size();
        n = board[0].size();
        int index = 0;
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (board[i][j] == word[0] && dfs(board, visited, word, 0, i, j))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool dfs(std::vector<std::vector<char>>& board, std::vector<std::vector<bool>>& visited, std::string &word, int index, int i, int j)
    {
        if (visited[i][j])
        {
            return false;
        }
        if (board[i][j] == word[index])
        {
            visited[i][j] = true;
            if (index == word.length() - 1)
            {
                return true;
            }
            if (i>0 && dfs(board, visited, word, index+1, i-1, j))
            {
                return true;
            }
            if (j>0 && dfs(board, visited, word, index+1, i, j-1))
            {
                return true;
            }
            if (i<m-1 && dfs(board, visited, word, index+1, i+1, j))
            {
                return true;
            }
            if (j<n-1 && dfs(board, visited, word, index+1, i, j+1))
            {
                return true;
            }
            visited[i][j] = false;
        }
        return false; 
        
    }
};