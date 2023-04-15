class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        ans = [1] * (rowIndex + 1)
        
        for n in range(2, rowIndex + 1):
            temp = ans.copy()
            for j in range(1, n):
                ans[j] = temp[j-1] + temp[j]
        return ans