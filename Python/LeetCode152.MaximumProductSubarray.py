class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        N = len(nums)

        if N == 1: return nums[0]

        maxP = nums[0]
        minP = nums[0]
        ans = nums[0]

        for i in range(1, N):
            temp = maxP
            maxP = max(nums[i], nums[i] * maxP)
            maxP = max(maxP, nums[i] * minP)
            minP = min(nums[i], nums[i] * minP)
            minP = min(minP, nums[i] * temp)
            ans = max(maxP, ans)

        return ans