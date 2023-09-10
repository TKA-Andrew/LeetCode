class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        l = 0
        r = 0
        max_frequency = 0
        max_length = 0
        char_count = {}

        while r < len(s):
            char_count[s[r]] = char_count.get(s[r], 0) + 1
            max_frequency = max(max_frequency, char_count[s[r]])

            while r-l+1 - max_frequency > k:
                char_count[s[l]] -= 1
                l += 1

            max_length = max(max_length, r-l+1)
            r += 1

        return max_length
