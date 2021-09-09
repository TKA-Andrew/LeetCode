// credit to: https://leetcode.com/problems/largest-plus-sign/discuss/1453636/Intuitiveor-Explained-with-image-or-Short-and-Clean-or-C%2B%2B
// for explanation, please refer to the link above

/**
 * @param {number} n
 * @param {number[][]} mines
 * @return {number}
 */

// Time complexity: O(n^2)
// Space complexity: O(n^2), which is the size of the matrix
var orderOfLargestPlusSign = function(n, mines) {
    let lef = new Array(n).fill().map( ()=> new Array(n).fill(1));
    let rig = new Array(n).fill().map( ()=> new Array(n).fill(1));
    let top = new Array(n).fill().map( ()=> new Array(n).fill(1));
    let bot = new Array(n).fill().map( ()=> new Array(n).fill(1));

    for (const [r,c] of mines) {
        lef[r][c] = 0
        rig[r][c] = 0
        top[r][c] = 0
        bot[r][c] = 0
    }

    // solution of https://leetcode.com/problems/largest-plus-sign/discuss/1453636/Intuitiveor-Explained-with-image-or-Short-and-Clean-or-C%2B%2B
    /*
        for (let i=0; i<n; i++) {
            for (let j=0; j<n; j++) {
                let x = n - i - 1;
                let y = n - j - 1;
                if( (i>0)   && top[i][j] ) top[i][j] += top[i-1][j];
                if( (j>0)   && lef[i][j] ) lef[i][j] += lef[i][j-1];
                if( (x<n-1) && bot[x][y] ) bot[x][y] += bot[x+1][y];
                if( (y<n-1) && rig[x][y] ) rig[x][y] += rig[x][y+1];
            }
        }
    */

    // modified solution
    // each [i][j] represents the center of a plus sign
    // we skip the first row and first column because it cannot be the center of plus sign
    // traverse from top to bottom, left to righ
    for (let i=1; i<n; i++) { // use i = 1 to skip first column
        for (let j=1; j<n; j++) { // use j = 1 to skip first row
            let x = n - i - 1; // x is reversed index of i
            let y = n - j - 1; // y is reversed index of j
            if( top[i][j] !== 0 ) top[i][j] += top[i-1][j];
            if( lef[i][j] !== 0 ) lef[i][j] += lef[i][j-1];
            if( bot[x][y] !== 0 ) bot[x][y] += bot[x+1][y];
            if( rig[x][y] !== 0 ) rig[x][y] += rig[x][y+1];
        }
    }

    let ans = 0;

    for(let i=0;i<n;i++)
        for(let j=0;j<n;j++)
            ans = Math.max(ans, Math.min(lef[i][j], rig[i][j], top[i][j], bot[i][j]));

    return ans;
};