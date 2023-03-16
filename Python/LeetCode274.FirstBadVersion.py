# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        left = 1
        right = n
        while left < right:
            mid = int(left + (right-left)/2) # round up
            if isBadVersion(mid):
                right = mid
            else:
                left = mid + 1
        return left