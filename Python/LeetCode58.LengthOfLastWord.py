class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        idx = len(s) - 1
        count = 0
        while (idx > 0 and s[idx] == ' '):
            idx -= 1
        while (idx >= 0):
            if s[idx] == ' ':
                return count
            else:
                count += 1
                idx -= 1
        return count