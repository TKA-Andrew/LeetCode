/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
 var spiralOrder = function(matrix) {
    let startRow = 0;
    let endRow = matrix.length - 1;
    let startCol = 0;
    let endCol = matrix[0].length - 1;
    let spiral = [];
    while (startRow <= endRow && startCol <= endCol) {
        for (let i = startCol; i <= endCol; i++) {
            spiral.push(matrix[startRow][i])
        }
        for (let i = startRow+1; i <= endRow; i++) {
            spiral.push(matrix[i][endCol])
        }
        if (startRow === endRow || startCol === endCol) {
            break;
        }
        for (let i = endCol-1; i >= startCol; i--) {
            spiral.push(matrix[endRow][i])
        }
        for (let i = endRow-1; i > startRow; i--) {
            spiral.push(matrix[i][startCol])
        }
        startRow ++;
        endRow --;
        startCol ++;
        endCol --;
    }
    return spiral;
};