class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        left = 0
        right = len(nums) - 1
        
        while (right >= 0 and left <= right):
            if nums[right] == val:
                right -= 1
                nums.pop();
            elif nums[left] == val:
                nums[left] = nums[right]
                nums[right] = val
            else:
                left += 1
        
        return len(nums)