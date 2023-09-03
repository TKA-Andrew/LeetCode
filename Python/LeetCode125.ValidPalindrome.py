import re


class Solution:
    def isPalindrome(self, s: str) -> bool:
        processed = re.sub(r'[\W_]', '', s.lower())
        left = 0
        right = len(processed) - 1
        while left < right:
            if processed[left] != processed[right]:
                return False
            left += 1
            right -= 1
        return True
