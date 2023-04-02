class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        farthest = 0
        end = 0
        jump = 0

        # no need to jump at the last index
        for i in range(0, n-1):
            farthest = max(farthest, nums[i] + i)
            # if reached the previous farthest, need to jump
            if end == i:
                jump += 1
                end = farthest
        return jump
