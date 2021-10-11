
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::vector<std::string>> res;

    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::string> board(n, std::string(n, '.'));
        backtrack(board, 0);
        return res;
    }
    
    void backtrack(std::vector<std::string>& board, int row) {
        int boardSize = board.size(); // to prevent type mismatch, as board.size() is size_type instead of int
        if (row == boardSize) {
            res.push_back(board);
            return;
        }
        int n = board[row].size();
        for (int col = 0; col < n; col++){
            if (!isValid(board, row, col)) continue; // skip if placing Q at this coordinate is not valid
            board[row][col] = 'Q'; // place Q at this coordinate
            backtrack(board, row+1); // each row can only have one Q, can straight away proceed with next row
            board[row][col] = '.'; // unplaced the Q to look for possibility of Q putting at other column for this row
        }
    }
    
    bool isValid(std::vector<std::string>& board, int row, int col) {

        int boardSize = board.size(); // to prevent type mismatch, as board.size() is size_type instead of int
        
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false; // means before this there is a Q at this column
            }
        }
        
        // this will not happen because we proceed with backtrack(board,row+1) everytime we place a Q
        /*
        for (int i = 0; i < col; i ++) {
            if (board[row][i]) {
                return false; // means before this there is a Q at this row
            }
        }
        */
        
        // check top right
        for (int i=row-1, j=col+1; i>=0 && j<boardSize; i-- , j++) {
            if (board[i][j] == 'Q') {
                return false; // means top right corner has a Q
            }
        }
        
        // check top left
        for (int i=row-1, j=col-1; i>=0 && j>=0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false; // means top left corner has a Q
            }
        }
        
        return true;
    }
};