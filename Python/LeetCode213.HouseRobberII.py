class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)

        if n == 1: return nums[0]

        return max(self.robRange(nums, 0, n-2), self.robRange(nums, 1, n-1))

    # start from behind so that we dont need to find the initial base case
    def robRange(self, nums, start, end):
        dp_i = 0
        dp_i2 = 0
        dp_i3 = 0

        for i in range(end, start-1, -1):
            dp_i3 = dp_i2
            dp_i2 = dp_i
            dp_i = max(dp_i2, dp_i3+nums[i])
        
        return dp_i