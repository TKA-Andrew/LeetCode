// time complexity: O(9^m) // worst case
// space complexity: O(1) // no additional space needed

#include <vector>

class Solution {
public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        backtrack(board, 0, 0);
    }
    
    bool backtrack(std::vector<std::vector<char>>& board, int i, int j) {
        if (j==9) {
            return backtrack(board, i+1, 0); // start with nex row and reset column to 0
        }
        
        if (i==9) {
            return true; // if the backtrack successfully reached i==9, means there is a valid solution found
        }

        if (board[i][j] != '.') { // skip this coordinate if it is not empty box
            return backtrack(board, i, j+1);
        }

        for (char ch='1'; ch<='9'; ch++) {
            if (!isValid(board, i, j, ch)) {
                continue;
            }
            board[i][j]=ch;
            if (backtrack(board, i, j+1)) {
                return true; // return true to stop backtrack
            }
            board[i][j]='.';
        }
        return false;
    }
    
    bool isValid(std::vector<std::vector<char>>& board, int r, int c, char ch) {
        for (int i=0;i<9;i++) {
            if (board[r][i] == ch) {
                return false;
            }
            if (board[i][c] == ch) {
                return false;
            }
            if (board[(r/3)*3 + i/3][(c/3)*3 + i%3] == ch) {
                return false;
            }
        }
        return true;
    }
};