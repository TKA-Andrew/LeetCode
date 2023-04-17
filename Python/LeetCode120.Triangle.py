class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        N = len(triangle)
        for row in range(N-2, -1, -1):
            for col in range(row+1):
                btm = self.helper(triangle, row+1, col)
                btm_right = self.helper(triangle, row+1, col+1)
                triangle[row][col] = min(triangle[row][col] + btm, triangle[row][col] + btm_right)
        
        return triangle[0][0]


    def helper(self, triangle, row, col):
        if row < 0 or col < 0 or col >= row+1:
            return float('inf')
        return triangle[row][col]