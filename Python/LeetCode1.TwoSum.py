class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        numMap = {}
        
        for i, j in enumerate(nums):
            r = target - j
            if r in numMap:
                return [numMap[r], i]
            numMap[j] = i