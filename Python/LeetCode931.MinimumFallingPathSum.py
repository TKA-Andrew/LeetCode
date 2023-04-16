class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        m = len(matrix[0])

        if n == 1 and m == 1:
            return matrix[0][0]
        elif n == 1:
            return min(matrix[0])

        for row in range(n-2, -1, -1):
            for col in range(m):
                btm_left = self.helper(matrix, row+1, col-1, n, m)
                btm = self.helper(matrix, row+1, col, n, m)
                btm_right = self.helper(matrix, row+1, col+1, n, m)
                matrix[row][col] = min(matrix[row][col] + btm_left,
                                        min(matrix[row][col] + btm,
                                            matrix[row][col] + btm_right))

        return min(matrix[0])

    def helper(self, matrix, row: int, col: int, n: int, m: int):
        if row < 0 or row >= n or col < 0 or col >= m:
            return float('inf')
        return matrix[row][col]