class Solution:
    def getMaxLen(self, nums: List[int]) -> int:
        N = len(nums)
        p = [0] * N
        n = [0] * N
        if nums[0] > 0:
            p[0] = 1
        elif nums[0] < 0:
            n[0] = 1
        ans = p[0]

        for i in range (1, N):
            if (nums[i] > 0):
                p[i] = p[i-1] + 1
                n[i] = n[i-1] + 1 if n[i-1] > 0 else 0
            elif (nums[i] < 0):
                n[i] = p[i-1] + 1
                p[i] = n[i-1] + 1 if n[i-1] > 0 else 0
            ans = max(p[i], ans)
    
        return ans
