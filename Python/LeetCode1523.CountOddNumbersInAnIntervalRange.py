class Solution:
    def countOdds(self, low: int, high: int) -> int:
        count = int ((high-low) / 2)
        if (high % 2 == 1) or (low % 2 == 1):
            count += 1
        return count