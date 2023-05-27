class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        while int(n) >= 3:
            n = n / 3
        return True if n % 3 == 1 and n > 0 else False