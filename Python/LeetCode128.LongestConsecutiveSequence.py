class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums.sort()
        count = 1
        maxCount = 0 if len(nums) == 0 else 1
        for i in range(1, len(nums)):
            if nums[i] - nums[i-1] == 0:
                continue
            elif nums[i] - nums[i-1] == 1:
                count += 1
            else:
                count = 1
            maxCount = max(count, maxCount)
        return maxCount
