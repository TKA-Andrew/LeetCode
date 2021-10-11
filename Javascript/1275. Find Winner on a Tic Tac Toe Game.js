// reference: https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/solution/

/**
 * @param {number[][]} moves
 * @return {string}
 */
 var tictactoe = function(moves) {
    let rows = new Array(3).fill(0);
    let cols = new Array(3).fill(0);
    let diag = 0;
    let anti_diag = 0;
    
    let player = 1;
    for (const [row, col] of moves) {
        rows[row] += player;
        cols[col] += player;
        
        if (row === col) {
            diag += player;
        }
        if ((row+col) === 2) {
            anti_diag += player;
        }
        
        if (Math.abs(rows[row]) === 3 || Math.abs(cols[col]) === 3 || Math.abs(diag) === 3 || Math.abs(anti_diag) === 3) {
            return player === 1 ? 'A' : 'B';
        }
        player *= -1;
    }
    return moves.length === 9 ? "Draw" : "Pending";
};