class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if len(nums) == 1:
            return nums
        left = 0
        right = 1
        limit = len(nums)
        while right < limit:
            if nums[left] == 0:
                while right<limit and nums[right] == 0:
                    right+=1
                if right >= limit:
                    return nums
                nums[left] = nums[right]
                nums[right] = 0
            else:
                left += 1
                right += 1
        return nums