class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        N = len(nums)

        if N == 1: return nums[0]

        maxSub = [0] * N
        maxSub[0] = nums[0]
        maxSub[1] = max(nums[1], maxSub[0] + nums[1])

        minSub = [0] * N
        minSub[0] = nums[0]
        minSub[1] = min(nums[1], minSub[0] + nums[1])

        totalSum = sum(nums)

        for i in range(2, N):
            minSub[i] = min(minSub[i-1] + nums[i], nums[i])
            maxSub[i] = max(maxSub[i-1] + nums[i], nums[i])
        
        maxValue = max(maxSub)
        minValue = min(minSub)

        # Corner case: if all values are negative
        if totalSum - minValue == 0:
            return maxValue

        return max(maxValue, totalSum - minValue)
