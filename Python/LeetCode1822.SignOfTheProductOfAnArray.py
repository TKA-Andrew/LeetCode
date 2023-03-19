class Solution:
    def arraySign(self, nums: List[int]) -> int:
        sign = 1
        for num in nums:
            if num < 0:
                sign = -sign;
            elif num == 0:
                return 0
        return sign
