class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ans = [[1]]
        for n in range (1,numRows):
            temp = [1] * (n + 1)
            for j in range(1, n):
                temp[j] = ans[n-1][j-1] + ans[n-1][j]
            ans.append(temp)

        return ans